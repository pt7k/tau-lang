// To view the license please visit https://github.com/IDNI/tau-lang/blob/main/LICENSE.txt

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <iostream>
#include <string>
#include <random>
#include <sstream>
#include <iomanip>
#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/utility/setup/console.hpp>

#include "doctest.h"
#include "interpreter.h"
#include "sbf_ba.h"

using namespace boost::log;
using namespace idni::tau;

std::string random_file(const std::string& extension = ".out", const std::string prefix = "/tmp/") {
    // define the characters to use in the random string
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
	// length of the random string
    const size_t length = 10;
    // random number generator
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<> dist(0, sizeof(charset) - 2);
    std::ostringstream oss;
	// add default location
	oss << prefix;
    // generate random string
    for (size_t i = 0; i < length; ++i) oss << charset[dist(generator)];
    // append the file extension and return the file name
    oss << extension;
    return oss.str();
}

template<typename...BAs>
struct output_sbf_console {

	bool write(const assignment<BAs...>& outputs) {
		// for each stream in out.streams, write the value from the solution
		for (const auto& [var, value]: outputs)
			std::cout << var << " <- " << value << "\n";
		return true; // success (always)
	}

	std::optional<type> type_of(const nso<BAs...>&) {
		return { "sbf" }; // sbf (always)
	}
};

template<typename...BAs>
struct input_sbf_vector {

	input_sbf_vector() = default;
	input_sbf_vector(std::vector<assignment<BAs...>>& inputs): inputs(inputs) {}

	std::optional<assignment<BAs...>> read() {
		if (inputs.empty()) return { assignment<BAs...>{} };
		if (current == inputs.size()) return {};
		return inputs[current++];
	}

	std::pair<std::optional<assignment<BAs...> >, bool> read(
		const auto& , const size_t ) {
		return { assignment<BAs...>{}, false };
	}

	std::optional<type> type_of(const nso<BAs...>&) {
		return { "sbf" }; // sbf (always)
	}

	std::vector<assignment<BAs...>> inputs;
	size_t current = 0;
};

std::optional<assignment<tau_ba<sbf_ba>, sbf_ba>> run_test(const char* sample,
		input_sbf_vector<tau_ba<sbf_ba>, sbf_ba>& inputs,
		output_sbf_console<tau_ba<sbf_ba>, sbf_ba>& outputs,
		const size_t& times) {
	auto sample_src = make_tau_source(sample);
	auto spec = make_nso_rr_using_factory<
		tau_ba<sbf_ba>, sbf_ba>(sample_src).value().main;

	#ifdef DEBUG
	std::cout << "run_test/------------------------------------------------------\n";
	std::cout << "run_test/sample: " << sample << "\n";
	#endif // DEBUG

	if (auto intprtr = make_interpreter(spec, inputs, outputs); intprtr) {

		// we read the inputs only once (they are always empty in this test suite)

		for (size_t i = 0; i < times; ++i) {
			// we execute the i-th step
			auto in = inputs.read();

			#ifdef DEBUG
			std::cout << "run_test/input[" << i << "]: ";
			if (in.has_value()) {
				for (const auto& [var, value]: in.value())
					std::cout << var << " <- " << value << " ... ";
				std::cout << "\n";
			} else std::cout << "{}\n"; // no input
			#endif // DEBUG

			auto [out, _ ] = intprtr.value().step(inputs);

			// The output can be empty if all variables have been assigned in previous steps
			if (!out.has_value()) {
				intprtr.value().memory.clear();
				#ifdef DEBUG
				std::cout << "run_test/output[" << i << "]: {}\n"; // no output
				#endif // DEBUG
				break;
			}

			#ifdef DEBUG
			std::cout << "run_test/output[" << i << "]: ";
			for (const auto& [var, value]: out.value()) {
				std::cout << var << " <- " << value << " ... ";
				if (auto io_vars = find_top(value, is_non_terminal<tau_parser::io_var, tau_ba<sbf_ba>, sbf_ba>); io_vars) {
					std::cout << "run_test/output[" << i << "]: unexpected io_var " << io_vars.value() << "\n";
					intprtr.value().memory.clear();
					break;
				}
			}
			std::cout << "\n";
			#endif // DEBUG
		}

		return intprtr.value().memory;
	}
	return {};
}

std::optional<assignment<tau_ba<sbf_ba>, sbf_ba>> run_test(const char* sample,
		const size_t& times) {
	input_sbf_vector<tau_ba<sbf_ba>, sbf_ba> inputs;
	output_sbf_console<tau_ba<sbf_ba>, sbf_ba> outputs;
	return run_test(sample, inputs, outputs, times);
}

std::optional<assignment<tau_ba<sbf_ba>, sbf_ba>> run_test(const char* sample,
		input_sbf_vector<tau_ba<sbf_ba>, sbf_ba>& inputs,
		const size_t& times) {
	output_sbf_console<tau_ba<sbf_ba>, sbf_ba> outputs;
	return run_test(sample, inputs, outputs, times);
}

std::optional<assignment<tau_ba<sbf_ba>, sbf_ba>> run_test(const char* sample,
		output_sbf_console<tau_ba<sbf_ba>, sbf_ba>& outputs,
		const size_t& times) {
	input_sbf_vector<tau_ba<sbf_ba>, sbf_ba> inputs;
	return run_test(sample, inputs, outputs, times);
}

TEST_SUITE("configuration") {

	TEST_CASE("configuration") {
		// initialize the bdd library
		bdd_init<Bool>();
		// configuring boost logging only for errors
		core::get()->set_filter(trivial::severity >= trivial::error);
		add_console_log(std::cout, keywords::format =
			expressions::stream << expressions::smessage);
	}
}

TEST_SUITE("only outputs") {

	// In this test suite we test the interpreter with only outputs in the Tau
	// specifications, no inputs are provided at all. The outputs are written
	// to the console.

	// coonstant test cases

	TEST_CASE("o1[t] = 0") {
		const char* sample = "o1[t] = 0.";
		auto memory = run_test(sample, 2);
		CHECK ( !memory.value().empty() );
	}

	TEST_CASE("o1[t] = {a}:sbf") {
		const char* sample = "o1[t] = {a}:sbf.";
		auto memory = run_test(sample, 2);
		CHECK ( !memory.value().empty() );
	}

	TEST_CASE("o1[0] = 1") {
		const char* sample = "o1[0] = 1.";
		auto memory = run_test(sample, 3);
		CHECK ( !memory.value().empty() );
	}

	TEST_CASE("o1[1] = 1") {
		const char* sample = "o1[1] = 1.";
		auto memory = run_test(sample, 3);
		CHECK ( !memory.value().empty() );
	}

	TEST_CASE("o1[0] = {a}:sbf") {
		const char* sample = "o1[0] = {a}:sbf.";
		auto memory = run_test(sample, 3);
		CHECK ( !memory.value().empty() );
	}

	TEST_CASE("o1[1] = {a}:sbf") {
		const char* sample = "o1[1] = {a}:sbf.";
		auto memory = run_test(sample, 3);
		CHECK ( !memory.value().empty() );
	}

	// TODO (HIGH) check with Ohad the proper output in this case.
	// The spec is T, i.e. all outputs are valid. However, due to our inner
	// implementation, we are not defining outputs as we have T in the spec.
	// and hence, we are not able to provide outputs.
	// One possibility is return an optional instead of an assignment and
	// return an optional with an empty assigment in this case.
	TEST_CASE("o1[t] & o1[t]'= 0") {
		const char* sample = "o1[t] & o1[t]' = 0.";
		auto memory = run_test(sample, 2);
		CHECK ( (!memory.has_value() || memory.value().empty()) );
	}

	TEST_CASE("o1[0] = 1 && o1[t] = o1[t-1]") {
		const char* sample = "o1[0] = 1 && o1[t] = o1[t-1].";
		auto memory = run_test(sample, 2);
		CHECK ( !memory.value().empty() );
	}

	TEST_CASE("o1[0] = {a}:sbf && o1[t] = o1[t-1]") {
		const char* sample = "o1[0] = {a}:sbf && o1[t] = o1[t-1].";
		auto memory = run_test(sample, 3);
		CHECK ( !memory.value().empty() );
	}

	TEST_CASE("o1[0] = {a}:sbf && o1[t] != o1[t-1]") {
		const char* sample = "o1[0] = {a}:sbf && o1[t] = o1[t-1].";
		auto memory = run_test(sample, 3);
		CHECK ( !memory.value().empty() );
	}

	TEST_CASE("o1[t] | o2[t]= 0") {
		const char* sample = "o1[t] | o2[t]= 0.";
		auto memory = run_test(sample, 2);
		CHECK ( !memory.value().empty() );
	}

	TEST_CASE("o1[t] & o1[t-1] = 1") {
		const char* sample = "o1[t] & o1[t-1] = 1.";
		auto memory = run_test(sample, 2);
		CHECK ( !memory.value().empty() );
	}

	TEST_CASE("o1[t] + o1[t-1] = 1") {
		const char* sample = "o1[t] + o1[t-1] = 1.";
		auto memory = run_test(sample, 2);
		CHECK ( !memory.value().empty() );
	}

	TEST_CASE("o1[0] = {a}:sbf && o1[t] < o1[t-1] && o1[t] != 0") {
		const char* sample = "o1[0] = {a}:sbf && o1[t] < o1[t-1] && o1[t] != 0.";
		auto memory = run_test(sample, 4);
		CHECK ( !memory.value().empty() );
	}

	// increasing monotonicity (2)
	TEST_CASE("o1[0] = {a}:sbf && o1[t] > o1[t-1] && o1[t] != 1") {
		const char* sample = "o1[0] = {a}:sbf && o1[t] > o1[t-1] && o1[t] != 1.";
		auto memory = run_test(sample, 4);
		CHECK ( !memory.value().empty() );
	}

	// increasing monotonicity (3)
	TEST_CASE("o1[0] = 0 && o1[t] > o1[t-1] && o1[t] != 1") {
		const char* sample = "o1[0] = {a}:sbf && o1[t] > o1[t-1] && o1[t] != 1.";
		auto memory = run_test(sample, 4);
		CHECK ( !memory.value().empty() );
	}

	// increasing monotonicity (4)
	TEST_CASE("o1[t] > o1[t-1] && o1[t] != 1") {
		const char* sample = "o1[0] = {a}:sbf && o1[t] > o1[t-1] && o1[t] != 1.";
		auto memory = run_test(sample, 4);
		CHECK ( !memory.value().empty() );
	}

	TEST_CASE("<:a> o1[t] + <:b> o1[t]' = 0") {
		const char* sample = "<:a> o1[t] + <:b> o1[t]' = 0.";
		auto memory = run_test(sample, 8);
		CHECK ( !memory.value().empty() );
	}

	TEST_CASE("o1[0] = <:c> && o1[t] = <:a> o1[t-1] + <:b> o1[t-1]'") {
		const char* sample = "o1[0] = <:c> && o1[t] = <:a> o1[t-1] + <:b> o1[t-1]'.";
		auto memory = run_test(sample, 8);
		CHECK ( !memory.value().empty() );
	}

	// f(f(f(x))) = f(x) using uninterpreted constants
	TEST_CASE("o1[t] = <:a> o1[t-1] + <:b> o1[t-1]'") {
		const char* sample = "o1[t] = <:a> o1[t-1] + <:b> o1[t-1]'.";
		auto memory = run_test(sample, 8);
		CHECK ( !memory.value().empty() );
	}

	// f(f(f(x))) = f(x) using constants
	TEST_CASE("o1[t] = {a}:sbf o1[t-1] + {b}:sbf o1[t-1]'") {
		// TODO (CHECK this one too
		// const char* sample = "o1[t] = {a}:sbf o1[t-1] + {b}:sbf o1[t-1]'.";
		const char* sample = "o1[t] = {a}:sbf o1[t-1] + {b}:sbf o1[t-1]'.";
		auto memory = run_test(sample, 8);
		CHECK ( !memory.value().empty() );
	}

	// Fibonacci like sequence with BA constants (0 or 1)
	TEST_CASE("o1[0] = 1 && o1[1] = 1 && o1[t] = o1[t-1] + o1[t-2]") {
		const char* sample = "o1[0] = 1 && o1[1] = 1 && o1[t] = o1[t-1] + o1[t-2].";
		auto memory = run_test(sample, 8);
		CHECK ( !memory.value().empty() );
	}

	// Fibonacci like sequence with SBFs
	TEST_CASE("o1[0] = {a}:sbf && o1[1] = {a}:sbf && o1[t] = o1[t-1] + o1[t-2]") {
		const char* sample = "o1[0] =  {a}:sbf && o1[1] =  {a}:sbf && o1[t] = o1[t-1] + o1[t-2].";
		auto memory = run_test(sample, 8);
		CHECK ( !memory.value().empty() );
	}

	// Fibonacci like sequence with sample Tau syntax
	TEST_CASE("o1[0] = {<:x> = 0.} && o1[1] = {<:x> = 0.} && o1[t] = o1[t-1] + o1[t-2]") {
		const char* sample = "o1[0] =  {<:x> = 0.} && o1[1] =  {<:x> = 0.} && o1[t] = o1[t-1] + o1[t-2].";
		auto memory = run_test(sample, 8);
		CHECK ( !memory.value().empty() );
	}

	// Fibonacci like sequence with sample Tau programs
	TEST_CASE("o1[0] = {o1[0] = 0.} && o1[1] = {o1[0] = 0.} && o1[t] = o1[t-1] + o1[t-2]") {
		const char* sample = "o1[0] =  {o1[0] = 0.} && o1[1] =  {o1[0] = 0.} && o1[t] = o1[t-1] + o1[t-2].";
		auto memory = run_test(sample, 8);
		CHECK ( !memory.value().empty() );
	}
}


TEST_SUITE("with inputs and outputs") {

	input_sbf_vector<tau_ba<sbf_ba>, sbf_ba> build_i1_inputs(
			std::vector<nso<tau_ba<sbf_ba>, sbf_ba>> values) {
		std::vector<assignment<tau_ba<sbf_ba>, sbf_ba>> assignments;
		for (const auto& value: values) {
			assignment<tau_ba<sbf_ba>, sbf_ba> assignment;
			assignment[build_in_var_name<tau_ba<sbf_ba>, sbf_ba>(1)] = value;
			assignments.push_back(assignment);
		}
		input_sbf_vector<tau_ba<sbf_ba>, sbf_ba> ins(assignments);
		return ins;
	}

	TEST_CASE("i1[t] = o1[t]") {
		const char* sample = "i1[t] = o1[t].";
		auto ins = build_i1_inputs({
			_1<tau_ba<sbf_ba>, sbf_ba>,
			_0<tau_ba<sbf_ba>, sbf_ba>,
			_0<tau_ba<sbf_ba>, sbf_ba> });
		auto memory = run_test(sample, ins, 3);
		CHECK ( !memory.value().empty() );
	}

	// In this case, we get an error as the output should be equal to the
	// input all the time, but the output is set to 0 at the beginning.
	//
	// TODO (HIGH) check this case, issue in unconstrained constants model
	// Note that this specification is unsat.
	TEST_CASE("i1[t] = o1[t] && o1[0] = 0") {
		const char* sample = "i1[t] = o1[t] && o1[0] = 0.";
		auto ins = build_i1_inputs({
			_1<tau_ba<sbf_ba>, sbf_ba>,
			_1<tau_ba<sbf_ba>, sbf_ba>,
			_1<tau_ba<sbf_ba>, sbf_ba> });
		auto memory = run_test(sample, ins, 3);
		CHECK ( (!memory.has_value() || memory.value().empty()) );
	}

	// In this case we get the sequence 0, 1, 1 as the output is set to 1
	// at the beginning.
	TEST_CASE("i1[t-1] = o1[t] && o1[0] = 0") {
		const char* sample = "i1[t-1] = o1[t] && o1[0] = 0.";
		auto ins = build_i1_inputs({
			_1<tau_ba<sbf_ba>, sbf_ba>,
			_1<tau_ba<sbf_ba>, sbf_ba>,
			_1<tau_ba<sbf_ba>, sbf_ba> });
		auto memory = run_test(sample, ins, 2);
		CHECK ( !memory.value().empty() );
	}

}

TEST_SUITE("test inputs") {

	TEST_CASE("reading from file with sbf inputs") {
		std::map<nso<tau_ba<sbf_ba>, sbf_ba>, std::pair<type, std::string>> input_map;
		auto var = build_in_var_name<tau_ba<sbf_ba>, sbf_ba>(1);
		input_map[var] = { "sbf", "integration/test_files/sbf-alternating_zeros_and_ones-length_10.in"};
		finputs<tau_ba<sbf_ba>, sbf_ba> inputs(input_map);
		CHECK ( inputs.type_of(var).has_value() );
		for (size_t i = 0; i < 10; ++i) {
			auto in = inputs.read();
			if (in) {
				auto check = (i % 2)
					? in.value()[var] == _1<tau_ba<sbf_ba>, sbf_ba>
					: in.value()[var] == _0<tau_ba<sbf_ba>, sbf_ba>;
				CHECK ( check );
			} else FAIL("no input");
		}
	}

	TEST_CASE("reading from file with tau program inputs") {
		std::map<nso<tau_ba<sbf_ba>, sbf_ba>, std::pair<type, std::string>> input_map;
		auto var = build_in_var_name<tau_ba<sbf_ba>, sbf_ba>(1);
		input_map[var] = { "tau", "integration/test_files/tau-alternating_zeros_and_ones-length_10.in"};
		finputs<tau_ba<sbf_ba>, sbf_ba> inputs(input_map);
		CHECK ( inputs.type_of(var).has_value() );
		for (size_t i = 0; i < 10; ++i) {
			auto in = inputs.read();
			if (in) {
				auto check = (i % 2)
					? in.value()[var] == _1<tau_ba<sbf_ba>, sbf_ba>
					: in.value()[var] == _0<tau_ba<sbf_ba>, sbf_ba>;
				CHECK ( check );
			} else FAIL("no input");
		}
	}
}

TEST_SUITE("test outputs") {

	TEST_CASE("writing to file") {
		std::map<nso<tau_ba<sbf_ba>, sbf_ba>, std::pair<type, std::string>> output_map;
		auto var = build_out_var_name<tau_ba<sbf_ba>, sbf_ba>(1);
		auto var_0 = build_out_variable_at_n<tau_ba<sbf_ba>, sbf_ba>(1, 0);

		output_map[var] = { "sbf", random_file() };

		#ifdef DEBUG
		std::cout << "test_outputs/writing_to_file/output: " << output_map[var].second << "\n";
		#endif // DEBUG

		foutputs<tau_ba<sbf_ba>, sbf_ba> outputs(output_map);
		assignment<tau_ba<sbf_ba>, sbf_ba> output = {
			{ var_0, _1<tau_ba<sbf_ba>, sbf_ba> }
		};

		CHECK( outputs.type_of(var).has_value() );
		CHECK ( outputs.write(output) );
	}

	TEST_CASE("writing to files: two outputs") {
		std::map<nso<tau_ba<sbf_ba>, sbf_ba>, std::pair<type, std::string>> output_map;
		auto var1 = build_out_var_name<tau_ba<sbf_ba>, sbf_ba>(1);
		auto var2 = build_out_var_name<tau_ba<sbf_ba>, sbf_ba>(2);
		auto var1_0 = build_out_variable_at_n<tau_ba<sbf_ba>, sbf_ba>(1, 0);
		auto var2_0 = build_out_variable_at_n<tau_ba<sbf_ba>, sbf_ba>(2, 0);
		output_map[var1] = {"sbf", random_file()};
		output_map[var2] = {"sbf", random_file()};

		#ifdef DEBUG
		std::cout << "test_outputs/writing_to_file/output: " << output_map[var1].second << "\n";
		std::cout << "test_outputs/writing_to_file/output: " << output_map[var2].second << "\n";
		#endif // DEBUG

		foutputs<tau_ba<sbf_ba>, sbf_ba> outputs(output_map);
		assignment<tau_ba<sbf_ba>, sbf_ba> output = {
			{ var1_0, _1<tau_ba<sbf_ba>, sbf_ba> },
			{ var2_0, _0<tau_ba<sbf_ba>, sbf_ba> }
		};

		CHECK( outputs.type_of(var1).has_value() );
		CHECK( outputs.type_of(var2).has_value() );
		CHECK ( outputs.write(output) );
	}

	TEST_CASE("writing to files: completing outputs") {
		std::map<nso<tau_ba<sbf_ba>, sbf_ba>, std::pair<type, std::string>> output_map;
		auto var1 = build_out_var_name<tau_ba<sbf_ba>, sbf_ba>(1);
		auto var2 = build_out_var_name<tau_ba<sbf_ba>, sbf_ba>(2);
		auto var1_0 = build_out_variable_at_n<tau_ba<sbf_ba>, sbf_ba>(1, 0);
		auto var2_1 = build_out_variable_at_n<tau_ba<sbf_ba>, sbf_ba>(2, 1);
		output_map[var1] = {"sbf", random_file()};
		output_map[var2] = {"sbf", random_file()};

		#ifdef DEBUG
		std::cout << "test_outputs/writing_to_file/output: " << output_map[var1].second << "\n";
		std::cout << "test_outputs/writing_to_file/output: " << output_map[var2].second << "\n";
		#endif // DEBUG

		foutputs<tau_ba<sbf_ba>, sbf_ba> outputs(output_map);
		assignment<tau_ba<sbf_ba>, sbf_ba> output = {
			{ var1_0, _1<tau_ba<sbf_ba>, sbf_ba> },
			{ var2_1, _1<tau_ba<sbf_ba>, sbf_ba> }
		};

		CHECK( outputs.type_of(var1).has_value() );
		CHECK( outputs.type_of(var2).has_value() );
		CHECK ( outputs.write(output) );
	}
}
