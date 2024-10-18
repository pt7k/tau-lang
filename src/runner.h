// LICENSE
// This software is free for use and redistribution while including this
// license notice, unless:
// 1. is used for commercial or non-personal purposes, or
// 2. used for a product which includes or associated with a blockchain or other
// decentralized database technology, or
// 3. used for a product which includes or associated with the issuance or use
// of cryptographic or electronic currencies/coins/tokens.
// On all of the mentioned cases, an explicit and written permission is required
// from the Author (Ohad Asor).
// Contact ohad@idni.org for requesting a permission. This license may be
// modified over time by the Author.

#ifndef __RUNNER_H__
#define __RUNNER_H__

#include <fstream>
#include <termios.h>

#include "tau_ba.h"
#include "solver.h"
#include "satisfiability.h"

#ifdef DEBUG
#include "debug_helpers.h"
#endif // DEBUG

namespace idni::tau {


using type = std::string;

using filename = std::string;

template<typename...BAs>
using io_var_name = nso<BAs...>; // out_var_name or in_var_name

template<typename...BAs>
using var_desc = std::pair<io_var_name<BAs...>, type>;

// represents an solution of variables to values.
template<typename...BAs>
using assignment = std::map<nso<BAs...>, nso<BAs...>>;

// A system represent a clause to be solved. It maps the different
// equations of the clause according to its type.
template<typename...BAs>
using system = std::map<type, nso<BAs...>>;

template<typename...BAs>
struct finputs {

	finputs() = delete;

	finputs(std::map<var_desc<BAs...>, filename> inputs) {
		// open the corresponding streams for input and store them in streams
		for (const auto& [var_desc, filename]: inputs) {
			this->types[var_desc.first] = var_desc.second;
			if (filename.empty()) this->streams[var_desc.first] = {};
			else this->streams[var_desc.first] = std::ifstream(filename);
		}
	}

	~finputs() {
		// close the streams
		for (auto& [_, file]: streams)
			if (file) file.value().close();
	}


	std::optional<assignment<BAs...>> read() {
		// for each stream in in streams, read the value from the file/stdin,
		// parsed it and store it in out.
		static nso_factory<BAs...> factory;
		if (streams.empty()) return assignment<BAs...>();
		assignment<BAs...> current;
		for (auto& [var, file]: streams) {
			std::string line;
			if (file) {
				std::getline(file.value(), line);
			} else {
				std::cout << var << "[" << time_point << "]: ";
				// get current terminal attributes
				termios orig_attrs;
    			tcgetattr(STDIN_FILENO, &orig_attrs);
				// read from standad input
				set_canonical_mode(orig_attrs);
				std::getline(std::cin, line);
				// restore original terminal attributes
				reset_mode(orig_attrs);
			}
			if (line.empty()) return {}; // error
			// TODO MEDIUM add logging in case of error
			current[var] = build_bf_constant(factory.parse(line, types[var]));
		}
		time_point += 1;
		return current;
	}

	std::optional<type> type_of(const nso<BAs...>& var) {
		if (auto type = types.find(var); type != types.end())
			return type->second;
		return {}; // error
	}

	std::map<nso<BAs...>, type> types;
	std::map<nso<BAs...>, std::optional<std::ifstream>> streams;
	size_t time_point = 0;

private:

	void set_canonical_mode(termios& orig_attrs) {
		termios new_attrs = orig_attrs;
		new_attrs.c_lflag |= ICANON;  // enable canonical mode
		new_attrs.c_lflag |= ECHO;    // enable echo
		tcsetattr(STDIN_FILENO, TCSANOW, &new_attrs);
	}

	void reset_mode(const termios& orig_attrs) {
		tcsetattr(STDIN_FILENO, TCSANOW, &orig_attrs);
	}
};

template<typename...BAs>
struct foutputs {

	foutputs() = delete;

	foutputs(std::map<var_desc<BAs...>, filename> outputs) {
		// open the corresponding streams for input and store them in streams
		for (const auto& [var_desc, file]: outputs) {
			//print_sp_tau_node_tree(std::cout, var_desc.first);
			//std::cout << var_desc.second << "\n";
			this->types[var_desc.first] = var_desc.second;
			if (file.empty()) this->streams[var_desc.first] = {};
			else this->streams[var_desc.first] = std::ofstream(file);
		}
	}

	~foutputs() {
		// close the streams
		for (auto& [_, file]: streams)
			if (file) file.value().close();
	}

	bool write(const assignment<BAs...>& outputs) {
		// sorting by time
		auto sorted = sort(outputs);
		// adding missing values
		auto completed = complete(sorted);
		// for each stream in out.streams, write the value from the solution
		for (const auto& output: completed) {
			for (const auto& [var, value]: output) {
				if (auto stream = streams.find(var); stream != streams.end())
					if (stream->second) stream->second.value() << value << "\n";
					else std::cout << value << "\n";
				else return false; // error
			}
		}
		return true; // success
	}

	std::optional<type> type_of(const nso<BAs...>& var) {
		if (auto type = types.find(var); type != types.end())
			return type->second;
		return {}; // error
	}

	std::map<nso<BAs...>, type> types;
	std::map<nso<BAs...>, std::optional<std::ofstream>> streams;

private:

	std::vector<assignment<BAs...>> sort(const assignment<BAs...>& sol) {
		auto compute_range = [](const assignment<BAs...>& sol) {
			size_t lower = std::numeric_limits<size_t>::max(), upper = 0;
			for (const auto& [var, value]: sol) {
				if (auto num = var
						| tau_parser::variable
						| tau_parser::io_var
						| tau_parser::out
						| tau_parser::offset
						| tau_parser::num
						| only_child_extractor<BAs...>
						| offset_extractor<BAs...>; num) {
					lower = std::min(lower, num | optional_value_extractor<size_t>);
					upper = std::max(upper, num | optional_value_extractor<size_t>);
				}
			}
			return std::make_pair(lower, upper);
		};

		auto [lower, upper] = compute_range(sol);

		#ifdef DEBUG
		std::cout << "sort/lower: " << lower << "\n";
		std::cout << "sort/upper: " << upper << "\n";
		#endif // DEBUG

		std::vector<assignment<BAs...>> result(upper - lower + 1);

		for (auto& [var, value]: sol) {
			if (auto num = var
					| tau_parser::variable
					| tau_parser::io_var
					| tau_parser::out
					| tau_parser::offset
					| tau_parser::num
					| only_child_extractor<BAs...>
					| offset_extractor<BAs...>; num) {
				auto io_var = var
					| tau_parser::variable
					| tau_parser::io_var
					| tau_parser::out
					| tau_parser::out_var_name
					| optional_value_extractor<nso<BAs...>>;
				result[num.value() - lower][io_var] = value;
			}
		}

		#ifdef DEBUG
		for (size_t i = 0; i < result.size(); ++i) {
			std::cout << "sort/result/[" << i <<"]: ";
			for (const auto& [k, v]: result[i]) std::cout << k << " <- " << v << " ";
			std::cout << "\n";
		}
		#endif // DEBUG

		return result;
	}

	std::vector<assignment<BAs...>> complete(const std::vector<assignment<BAs...>>& sols) {
		std::vector<assignment<BAs...>> result(sols.size());
		for (size_t i = 0; i < sols.size(); ++i) {
			assignment<BAs...> nsol = sols[i];
			for (const auto& [var, _]: types)
				if ( !nsol.contains(var) ) nsol[var] = _0<BAs...>;
			result[i] = nsol;
		}

		#ifdef DEBUG
		for (size_t i = 0; i < result.size(); ++i) {
			std::cout << "complete/result/[" << i <<"]: ";
			for (const auto& [k, v]: result[i]) std::cout << k << " <- " << v << " ";
			std::cout << "\n";
		}
		#endif // DEBUG

		return result;
	}
};

template<typename...BAs>
struct interpreter {

	interpreter(const std::set<system<BAs...>>& systems, assignment<BAs...>& memory, size_t& time_point):
			systems(systems), memory(memory), time_point(time_point) {
		// iniialize the variables
		for (const auto& system: systems) {
			for (const auto& [type, equations]: system) {
				for (const auto& out_var_name:
						select_top(equations, is_non_terminal<tau_parser::out_var_name, BAs...>))
					outputs[system].insert(out_var_name);
			}
		}
	}

	assignment<BAs...> step(const assignment<BAs...>& inputs) {
		// update the memory with the inputs
		for (const auto& [var, value]: inputs)
			memory[build_in_variable_at_n(var, time_point)] = value;
		// for each system in systems try to solve it, if it is not possible
		// continue with the next system.
		for (const auto& system: this->systems) {
			std::map<type, solution<BAs...>> solutions;
			bool solved = true;
			// solve the equations fro each type in the system
			for (const auto& [type, equations]: system) {
				// rewriting the inputs and inserting them into memory
				auto updated = update_to_time_point(equations);
				auto memory_copy = memory;
				auto current = replace(updated, memory_copy);

				#ifdef DEBUG
				std::cout << "step/type: " << type << "\n";
				std::cout << "step/equations: " << equations << "\n";
				std::cout << "step/updated: " << updated << "\n";
				std::cout << "step/current: " << current << "\n";
				std::cout << "step/memory: ";
				for (const auto& [k, v]: memory) std::cout << k << " <- " << v << " ";
				std::cout << "\n";
				#endif // DEBUG

				auto solution = solve(current, type);

				#ifdef DEBUG
				if (solution) {
					std::cout << "step/solution: ";
					if (solution.value().empty()) std::cout << "{}";
					else for (const auto& [k, v]: solution.value()) std::cout << k << " <- " << v << " ";
					std::cout << "\n";
					auto copy = solution.value();
					auto substituted = replace(current, copy);
					auto check = snf_wff(substituted);
					std::cout << "step/check: " << check << "\n";
				} else {
					std::cout << "step/solution: error\n";
				}
				#endif // DEBUG

				if (solution.has_value()) solutions[type] = solution.value();
				else { solved = false; break; }
			}
			if (solved) {
				solution<BAs...> global;
				// merge the solutions
				for (const auto& [type, solution]: solutions) {
					memory.insert(solution.begin(), solution.end());
					for (const auto& [var, value]: solution) {
						global[var] = value;
					}
				}
				// complete solution according to the outputs
				for (const auto &var: outputs[system]) {
					auto timed_var = build_out_variable_at_n(var, time_point);
					if (!global.contains(timed_var)) {
						memory[timed_var] = _0<BAs...>;
						global[timed_var] = _0<BAs...>;
					}
				}
				// update the time_point
				time_point += 1;
				// TODO (HIGH) remove old values from memory
				return global;
			}
		}
		return {}; // error
	}

	// store all the possible systems to be solved, each system corresponds to a
	// different clause.
	std::set<system<BAs...>> systems;
	assignment<BAs...> memory;
	size_t time_point;
	std::map<system<BAs...>, std::set<nso<BAs...>>> outputs;

private:

	nso<BAs...> update_to_time_point(const nso<BAs...>& f) {
		// update the f according to current time_point, i.e. for each
		// input/ouput var which has a shift, we replace it with the value
		// corresponding to the current time_point minnus the shift.
		std::map<nso<BAs...>, nso<BAs...>> changes;
		for (const auto& io_var:
				select_top(f, is_non_terminal<tau_parser::io_var, BAs...>))
			if (auto shift = io_var
						| only_child_extractor<BAs...>
						| tau_parser::offset
						| tau_parser::shift,
					var = shift
						| tau_parser::variable,
					num = shift
						| tau_parser::num
						| only_child_extractor<BAs...>
						| offset_extractor<BAs...>;
							num && var)
				changes[shift.value()] = build_num<BAs...>(time_point - num.value());
			else if (auto offset = io_var
						| only_child_extractor<BAs...>
						| tau_parser::offset,
					variable = offset
						| tau_parser::variable;
							variable)
				changes[offset.value()] = wrap(
					tau_parser::offset,
						build_num<BAs...>(time_point));
		return replace(f, changes);
	}
};

template<typename...BAs>
size_t compute_initial_execution_time(const nso<BAs...>& phi_inf) {
	// for each loopback in phi_inf, store the input and output lookbacks
	// in a pair and return it.
	size_t initial_time_point = 0;
	for (const auto& io_var: select_top(phi_inf, is_non_terminal<tau_parser::io_var, BAs...>)) {
		if (auto num = io_var
				| tau_parser::in
				| tau_parser::offset
				| tau_parser::shift
				| tau_parser::num
				| only_child_extractor<BAs...>
				| offset_extractor<BAs...>; num) {
			initial_time_point = max(initial_time_point, num | optional_value_extractor<size_t>);
		} else if (auto num = io_var
				| tau_parser::out
				| tau_parser::offset
				| tau_parser::shift
				| tau_parser::num
				| only_child_extractor<BAs...>
				| offset_extractor<BAs...>; num) {
			initial_time_point = max(initial_time_point, num | optional_value_extractor<size_t>);
		} else if (auto num = io_var
				| tau_parser::in
				| tau_parser::offset
				| tau_parser::num
				| only_child_extractor<BAs...>
				| offset_extractor<BAs...>; num) {
			initial_time_point = max(initial_time_point, num | optional_value_extractor<size_t>);
		} else if (auto num = io_var
				| tau_parser::out
				| tau_parser::offset
				| tau_parser::num
				| only_child_extractor<BAs...>
				| offset_extractor<BAs...>; num) {
			initial_time_point = max(initial_time_point, num | optional_value_extractor<size_t>);
		}
	}
	return initial_time_point;
}

template<typename input_t, typename...BAs>
std::optional<assignment<BAs...>> compute_initial_memory(const nso<BAs...>& phi_inf,
		const size_t& initial_execution_time, input_t& inputs) {
	assignment<BAs...> memory;
	for (size_t n = 0; n < initial_execution_time; ++n) {
		assignment<BAs...> current;
		if (auto current = inputs.read(); current)
			for (const auto& [var, value]: current.value())
				memory[build_in_variable_at_n(var, n)] = value;
		else return {}; // error
	}
	return memory;
}

template<typename input_t, typename output_t, typename...BAs>
std::optional<std::pair<type, nso<BAs...>>> compute_literal(const nso<BAs...>& literal,
		input_t& inputs, output_t& outputs) {
	if (auto io_var = find_top(literal,
			is_non_terminal<tau_parser::io_var, BAs...>); io_var) {
		if (auto in_var_name = io_var
				| tau_parser::in
				| tau_parser::in_var_name; in_var_name) {
			if(auto t = inputs.type_of(in_var_name.value()); t)
				return { make_pair(t.value() , literal) };
		} else if (auto out_var_name = io_var
				| tau_parser::out
				| tau_parser::out_var_name; out_var_name) {
			if (auto t = outputs.type_of(out_var_name.value()); t)
				return { make_pair(t.value() , literal) };
		}
	}
	return {}; // error
}

template<typename input_t, typename output_t, typename...BAs>
std::optional<system<BAs...>> compute_system(const nso<BAs...>& clause,
		input_t& inputs, output_t& outputs) {
	auto is_literal = [](const nso<BAs...>& n) {
		return is_child_non_terminal<tau_parser::bf_eq, BAs...>(n)
			|| is_child_non_terminal<tau_parser::bf_neq, BAs...>(n);
	};

	#ifdef DEBUG
	std::cout << "compute_systems/clause: " << clause << "\n";
	#endif // DEBUG

	system<BAs...> sys;
	for (const auto& literal: select_top(clause, is_literal)) {
		#ifdef DEBUG
		std::cout << "compute_systems/literal: " << literal << "\n";
		#endif // DEBUG
		if (auto l = compute_literal(literal, inputs, outputs); l) {
			if (sys.find(l.value().first) == sys.end()) sys[l.value().first] = l.value().second;
			else sys[l.value().first] = build_wff_and(sys[l.value().first], l.value().second);
		} else return {}; // error
	}
	return { sys };
}

template<typename input_t, typename output_t, typename...BAs>
std::optional<std::set<system<BAs...>>> compute_systems(const nso<BAs...>& phi_inf,
		input_t& inputs, output_t& outputs) {
	std::set<system<BAs...>> systems;
	// split phi_inf in clauses
	for (auto& clause: get_dnf_wff_clauses(phi_inf))
		if (auto system = compute_system(clause, inputs, outputs); system)
			systems.insert(system.value());
		else return {}; // error
	return systems;
}

template<typename input_t, typename output_t, typename...BAs>
std::optional<interpreter<BAs...>> make_interpreter(nso<BAs...> phi_inf, input_t& inputs, output_t& outputs) {
	// compute the different systems to be solved
	auto systems = compute_systems(phi_inf, inputs, outputs);
	if (!systems) return {}; // error
	// compute the initial time point for execution
	size_t initial_execution_time = compute_initial_execution_time(phi_inf);
	// compute initial memory
	auto memory = compute_initial_memory(phi_inf, initial_execution_time, inputs);
	if (!memory) return {}; // error
	//after the bove, we have the interpreter ready to be used.
	return interpreter<BAs...>{ systems.value(), memory.value(), initial_execution_time };
};


template<typename input_t, typename output_t, typename...BAs>
void run(const nso<BAs...>& phi_inf, input_t& inputs, output_t& outputs, size_t max_iter = std::numeric_limits<size_t>::max()) {
	auto intrprtr = make_interpreter(phi_inf, inputs, outputs);
	if (!intrprtr) {
		std::cout << "unable to create interpreter\n";
		return;
	}

	for (size_t i = 0; i < max_iter; ++i) {
		if (auto current = inputs.read(); current) {
			if (auto output = intrprtr.value().step(current.value()); output.size()) {
				if (!outputs.write(output)) return;
			} else return;
		// TODO (HIGH) add logging in case of no input
		} else return;
	}
}

} // namespace idni::tau

# endif //__RUNNER_TMPL_H__