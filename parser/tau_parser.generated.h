// This file is generated from a file parser/tau.tgf by
//       https://github.com/IDNI/parser/tools/tgf
//
#ifndef __TAU_PARSER_H__
#define __TAU_PARSER_H__
#include <string.h>
#include "parser.h"
struct tau_parser {
	using char_type     = char;
	using terminal_type = char;
	using traits_type   = std::char_traits<char_type>;
	using int_type      = typename traits_type::int_type;
	using symbol_type   = idni::lit<char_type, terminal_type>;
	using location_type = std::array<size_t, 2>;
	using node_type     = std::pair<symbol_type, location_type>;
	using parser_type   = idni::parser<char_type, terminal_type>;
	using options       = parser_type::options;
	using parse_options = parser_type::parse_options;
	using forest_type   = parser_type::pforest;
	using input_type    = parser_type::input;
	using decoder_type  = parser_type::input::decoder_type;
	using encoder_type  = std::function<std::basic_string<char_type>(
			const std::vector<terminal_type>&)>;
	tau_parser() :
		nts(load_nonterminals()), cc(load_cc()),
		g(nts, load_prods(), nt(241), cc), p(g, load_opts()) {}
	std::unique_ptr<forest_type> parse(const char_type* data, size_t size,
		parse_options po = {}) { return p.parse(data, size, po); }
	std::unique_ptr<forest_type> parse(std::basic_istream<char_type>& is,
		parse_options po = {}) { return p.parse(is, po); }
	std::unique_ptr<forest_type> parse(const std::string& fn,
		parse_options po = {}) { return p.parse(fn, po); }
#ifndef WIN32
	std::unique_ptr<forest_type> parse(int fd, parse_options po = {})
		{ return p.parse(fd, po); }
#endif //WIN32
	bool found(int start = -1) { return p.found(start); }
	typename parser_type::error get_error() { return p.get_error(); }
	enum nonterminal {
		nul, eof, space, digit, xdigit, alpha, alnum, punct, printable, comment, 
		_Rcomment_0, _Rcomment_1, _Rcomment_2, __, _R___3, _, _R__4, bf_def, wff_def, tau_def, 
		dot, open_parenthesis, close_parenthesis, open_bracket, close_bracket, open_brace, close_brace, minus, colon, semicolon, 
		less, comma, apostrophe, quote, chars, _Rchars_5, _Rchars_6, digits, _Rdigits_7, sym, 
		offsets, offset, _Roffsets_8, _Roffsets_9, num, capture, shift, variable, io_var, _Roffset_10, 
		_Rshift_11, _Rshift_12, var, in, out, in_var_name, out_var_name, bool_variable, wff_t, wff_f, 
		capture_var, tau_rule, tau_matcher, tau_body, tau, tau_collapse_positives_cb, tau_positives_upwards_cb, tau_rec_relation, tau_and, tau_neg, 
		tau_or, tau_wff, _Rtau_rec_relation_13, tau_ref, _Rtau_ref_14, tau_ref_args, tau_ref_arg, _Rtau_ref_args_15, _Rtau_ref_args_16, bf, 
		tau_and_sym, tau_or_sym, tau_neg_sym, wff, wff_rule, wff_matcher, wff_body, bf_eq_cb, bf_neq_cb, wff_has_clashing_subformulas_cb, 
		wff_has_subformula_cb, wff_remove_existential_cb, wff_remove_bexistential_cb, wff_remove_buniversal_cb, wff_rec_relation, wff_and, wff_neg, wff_xor, wff_conditional, wff_or, 
		wff_all, wff_ex, wff_imply, wff_equiv, wff_ball, wff_bex, bf_eq, bf_neq, bf_less, bf_less_equal, 
		bf_greater, bf_interval, bf_not_less_equal, _Rwff_rec_relation_17, wff_ref, _Rwff_ref_18, wff_ref_args, wff_ref_arg, _Rwff_ref_args_19, _Rwff_ref_args_20, 
		wff_and_sym, wff_or_sym, wff_xor_sym, wff_conditional_sym, wff_neg_sym, wff_imply_sym, wff_equiv_sym, wff_all_sym, _Rwff_all_21, wff_ex_sym, 
		_Rwff_ex_22, wff_ball_sym, _Rwff_ball_23, wff_bex_sym, _Rwff_bex_24, bf_equality_sym, bf_nequality_sym, bf_less_sym, bf_less_equal_sym, bf_not_less_equal_sym, 
		bf_greater_sym, bf_rule, bf_matcher, bf_body, bf_is_zero_cb, bf_is_one_cb, bf_has_subformula_cb, bf_remove_funiversal_cb, bf_remove_fexistential_cb, bf_and_cb, 
		bf_or_cb, bf_xor_cb, bf_neg_cb, bf_ref, bf_constant, bf_and, bf_neg, bf_xor, bf_or, bf_all, 
		bf_ex, bf_t, bf_f, bf_splitter, bf_rec_relation, _Rbf_rec_relation_25, _Rbf_ref_26, bf_ref_args, bf_ref_arg, _Rbf_ref_args_27, 
		_Rbf_ref_args_28, bf_and_sym, bf_or_sym, bf_xor_sym, bf_neg_sym, bf_all_sym, _Rbf_all_29, bf_ex_sym, _Rbf_ex_30, bf_splitter_sym, 
		constant, binding, source_binding, named_binding, type, source, source0, _Rsource_31, _Rsource_32, bf_and_cb_sym, 
		bf_cb_arg, bf_or_cb_sym, bf_xor_cb_sym, bf_neg_cb_sym, bf_eq_cb_sym, wff_cb_arg, bf_neq_cb_sym, bf_is_zero_cb_sym, bf_is_one_cb_sym, bf_remove_funiversal_cb_sym, 
		bf_remove_fexistential_cb_sym, wff_remove_existential_cb_sym, wff_remove_bexistential_cb_sym, wff_remove_buniversal_cb_sym, wff_has_clashing_subformulas_cb_sym, bf_has_subformula_cb_sym, wff_has_subformula_cb_sym, tau_collapse_positives_cb_sym, tau_cb_arg, _Rtau_collapse_positives_cb_33, 
		_Rtau_collapse_positives_cb_34, tau_positives_upwards_cb_sym, inputs, input, _Rinputs_35, _Rinputs_36, builder, builder_head, builder_body, _Rbuilder_head_37, 
		_Rbuilder_head_38, bf_builder_body, wff_builder_body, tau_builder_body, library, rules, rule, _Rrules_39, _Rrules_40, nso_rr, 
		nso_rec_relations, nso_main, nso_rec_relation, _Rnso_rec_relations_41, _Rnso_rec_relations_42, gssotc_rr, gssotc_rec_relations, gssotc_main, gssotc_rec_relation, _Rgssotc_rec_relations_43, 
		_Rgssotc_rec_relations_44, start, _Rstart_45, file, file_sym, file_path, cli, cli_command, _Rcli_46, _Rcli_47, 
		_Rcli_48, wff_onf_cmd, wff_dnf_cmd, wff_cnf_cmd, wff_anf_cmd, wff_nnf_cmd, wff_pnf_cmd, wff_mnf_cmd, bf_dnf_cmd, bf_cnf_cmd, 
		bf_anf_cmd, bf_nnf_cmd, bf_pnf_cmd, bf_mnf_cmd, rr_nso, help, version, quit, get, list_outputs, 
		_Rcli_command_49, wff_substitute_cmd, wff_instantiate_cmd, bf_substitute_cmd, bf_instantiate_cmd, normalize_cmd, list_outputs_cmd, clear_outputs_cmd, print_output_cmd, file_cmd, 
		toggle_cmd, set_cmd, get_cmd, help_cmd, version_cmd, quit_cmd, normalize_cmd_sym, output, wff_selection, _Rnormalize_cmd_50, 
		instantiate_cmd_sym, bf_selection, _Rbf_instantiate_cmd_51, _Rbf_instantiate_cmd_52, _Rwff_instantiate_cmd_53, _Rwff_instantiate_cmd_54, substitute_cmd_sym, _Rbf_substitute_cmd_55, _Rbf_substitute_cmd_56, _Rbf_substitute_cmd_57, 
		substitutecmd__sym, _Rwff_substitute_cmd_58, _Rwff_substitute_cmd_59, _Rwff_substitute_cmd_60, dnf_cmd_sym, _Rbf_dnf_cmd_61, cnf_cmd_sym, _Rbf_cnf_cmd_62, anf_cmd_sym, _Rbf_anf_cmd_63, 
		nnf_cmd_sym, _Rbf_nnf_cmd_64, pnf_cmd_sym, _Rbf_pnf_cmd_65, mnf_cmd_sym, _Rbf_mnf_cmd_66, onf_cmd_sym, _Rwff_onf_cmd_67, _Rwff_dnf_cmd_68, _Rwff_cnf_cmd_69, 
		_Rwff_anf_cmd_70, _Rwff_nnf_cmd_71, _Rwff_pnf_cmd_72, _Rwff_mnf_cmd_73, help_cmd_sym, cli_cmd_sym, _Rhelp_cmd_74, version_cmd_sym, quit_cmd_sym, selection_sym, 
		bf_var_selection, wff_var_selection, absolute_output, relative_output, absolute_output_sym, output_sym, _Rabsolute_output_75, output_id, relative_output_sym, _Rclear_outputs_cmd_76, 
		clear_sym, file_cmd_sym, get_cmd_sym, set_cmd_sym, toggle_cmd_sym, instantiate_sym, substitute_sym, clear_cmd_sym, option, _Rget_cmd_77, 
		_Rset_cmd_78, option_value, bool_option, severity_opt, status_opt, colors_opt, option_value_true, option_value_false, severity, error_sym, 
		debug_sym, trace_sym, info_sym, __neg_0, __neg_1, __neg_2, __neg_3, __neg_4, __neg_5, __neg_6, 
		__neg_7, __neg_8, __neg_9, __neg_10, __neg_11, __neg_12, __neg_13, __neg_14, __neg_15, __neg_16, 
		__neg_17, __neg_18, __neg_19, __neg_20, __neg_21, __neg_22, __neg_23, __neg_24, __neg_25, __neg_26, 
		__neg_27, __neg_28, __neg_29, __neg_30, __neg_31, __neg_32, __neg_33, __neg_34, __neg_35, __neg_36, 
		__neg_37, __neg_38, __neg_39, __neg_40, __neg_41, __neg_42, __neg_43, __neg_44, __neg_45, __neg_46, 
		__neg_47, __neg_48, __neg_49, 
	};
	size_t id(const std::basic_string<char_type>& name) {
		return nts.get(name);
	}
	const std::basic_string<char_type>& name(size_t id) {
		return nts.get(id);
	}
private:
	std::vector<terminal_type> ts{
		'\0', '\t', '\n', '\r', '#', ':', '=', '.', '(', 
		')', '[', ']', '{', '}', '-', ';', '<', ',', '\'', 
		'"', '$', 'i', '_', 'o', '&', '|', '!', '^', '?', 
		'>', 'a', 'l', 'e', 'x', 'b', 'T', 'F', '+', 'f', 
		'S', '1', '0', 'h', 's', 'u', 'r', 'm', 'c', 'w', 
		'n', 'g', 'v', 't', 'd', 'q', 'z', 'p', '%', 'y', 
	};
	idni::nonterminals<char_type, terminal_type> nts{};
	idni::char_class_fns<terminal_type> cc;
	idni::grammar<char_type, terminal_type> g;
	parser_type p;
	idni::prods<char_type, terminal_type> t(size_t tid) {
		return idni::prods<char_type, terminal_type>(ts[tid]);
	}
	idni::prods<char_type, terminal_type> nt(size_t ntid) {
		return idni::prods<char_type, terminal_type>(
			symbol_type(ntid, &nts));
	}
	idni::nonterminals<char_type, terminal_type> load_nonterminals() const {
		idni::nonterminals<char_type, terminal_type> nts{};
		for (const auto& nt : {
			"", "eof", "space", "digit", "xdigit", "alpha", "alnum", "punct", "printable", "comment", 
			"_Rcomment_0", "_Rcomment_1", "_Rcomment_2", "__", "_R___3", "_", "_R__4", "bf_def", "wff_def", "tau_def", 
			"dot", "open_parenthesis", "close_parenthesis", "open_bracket", "close_bracket", "open_brace", "close_brace", "minus", "colon", "semicolon", 
			"less", "comma", "apostrophe", "quote", "chars", "_Rchars_5", "_Rchars_6", "digits", "_Rdigits_7", "sym", 
			"offsets", "offset", "_Roffsets_8", "_Roffsets_9", "num", "capture", "shift", "variable", "io_var", "_Roffset_10", 
			"_Rshift_11", "_Rshift_12", "var", "in", "out", "in_var_name", "out_var_name", "bool_variable", "wff_t", "wff_f", 
			"capture_var", "tau_rule", "tau_matcher", "tau_body", "tau", "tau_collapse_positives_cb", "tau_positives_upwards_cb", "tau_rec_relation", "tau_and", "tau_neg", 
			"tau_or", "tau_wff", "_Rtau_rec_relation_13", "tau_ref", "_Rtau_ref_14", "tau_ref_args", "tau_ref_arg", "_Rtau_ref_args_15", "_Rtau_ref_args_16", "bf", 
			"tau_and_sym", "tau_or_sym", "tau_neg_sym", "wff", "wff_rule", "wff_matcher", "wff_body", "bf_eq_cb", "bf_neq_cb", "wff_has_clashing_subformulas_cb", 
			"wff_has_subformula_cb", "wff_remove_existential_cb", "wff_remove_bexistential_cb", "wff_remove_buniversal_cb", "wff_rec_relation", "wff_and", "wff_neg", "wff_xor", "wff_conditional", "wff_or", 
			"wff_all", "wff_ex", "wff_imply", "wff_equiv", "wff_ball", "wff_bex", "bf_eq", "bf_neq", "bf_less", "bf_less_equal", 
			"bf_greater", "bf_interval", "bf_not_less_equal", "_Rwff_rec_relation_17", "wff_ref", "_Rwff_ref_18", "wff_ref_args", "wff_ref_arg", "_Rwff_ref_args_19", "_Rwff_ref_args_20", 
			"wff_and_sym", "wff_or_sym", "wff_xor_sym", "wff_conditional_sym", "wff_neg_sym", "wff_imply_sym", "wff_equiv_sym", "wff_all_sym", "_Rwff_all_21", "wff_ex_sym", 
			"_Rwff_ex_22", "wff_ball_sym", "_Rwff_ball_23", "wff_bex_sym", "_Rwff_bex_24", "bf_equality_sym", "bf_nequality_sym", "bf_less_sym", "bf_less_equal_sym", "bf_not_less_equal_sym", 
			"bf_greater_sym", "bf_rule", "bf_matcher", "bf_body", "bf_is_zero_cb", "bf_is_one_cb", "bf_has_subformula_cb", "bf_remove_funiversal_cb", "bf_remove_fexistential_cb", "bf_and_cb", 
			"bf_or_cb", "bf_xor_cb", "bf_neg_cb", "bf_ref", "bf_constant", "bf_and", "bf_neg", "bf_xor", "bf_or", "bf_all", 
			"bf_ex", "bf_t", "bf_f", "bf_splitter", "bf_rec_relation", "_Rbf_rec_relation_25", "_Rbf_ref_26", "bf_ref_args", "bf_ref_arg", "_Rbf_ref_args_27", 
			"_Rbf_ref_args_28", "bf_and_sym", "bf_or_sym", "bf_xor_sym", "bf_neg_sym", "bf_all_sym", "_Rbf_all_29", "bf_ex_sym", "_Rbf_ex_30", "bf_splitter_sym", 
			"constant", "binding", "source_binding", "named_binding", "type", "source", "source0", "_Rsource_31", "_Rsource_32", "bf_and_cb_sym", 
			"bf_cb_arg", "bf_or_cb_sym", "bf_xor_cb_sym", "bf_neg_cb_sym", "bf_eq_cb_sym", "wff_cb_arg", "bf_neq_cb_sym", "bf_is_zero_cb_sym", "bf_is_one_cb_sym", "bf_remove_funiversal_cb_sym", 
			"bf_remove_fexistential_cb_sym", "wff_remove_existential_cb_sym", "wff_remove_bexistential_cb_sym", "wff_remove_buniversal_cb_sym", "wff_has_clashing_subformulas_cb_sym", "bf_has_subformula_cb_sym", "wff_has_subformula_cb_sym", "tau_collapse_positives_cb_sym", "tau_cb_arg", "_Rtau_collapse_positives_cb_33", 
			"_Rtau_collapse_positives_cb_34", "tau_positives_upwards_cb_sym", "inputs", "input", "_Rinputs_35", "_Rinputs_36", "builder", "builder_head", "builder_body", "_Rbuilder_head_37", 
			"_Rbuilder_head_38", "bf_builder_body", "wff_builder_body", "tau_builder_body", "library", "rules", "rule", "_Rrules_39", "_Rrules_40", "nso_rr", 
			"nso_rec_relations", "nso_main", "nso_rec_relation", "_Rnso_rec_relations_41", "_Rnso_rec_relations_42", "gssotc_rr", "gssotc_rec_relations", "gssotc_main", "gssotc_rec_relation", "_Rgssotc_rec_relations_43", 
			"_Rgssotc_rec_relations_44", "start", "_Rstart_45", "file", "file_sym", "file_path", "cli", "cli_command", "_Rcli_46", "_Rcli_47", 
			"_Rcli_48", "wff_onf_cmd", "wff_dnf_cmd", "wff_cnf_cmd", "wff_anf_cmd", "wff_nnf_cmd", "wff_pnf_cmd", "wff_mnf_cmd", "bf_dnf_cmd", "bf_cnf_cmd", 
			"bf_anf_cmd", "bf_nnf_cmd", "bf_pnf_cmd", "bf_mnf_cmd", "rr_nso", "help", "version", "quit", "get", "list_outputs", 
			"_Rcli_command_49", "wff_substitute_cmd", "wff_instantiate_cmd", "bf_substitute_cmd", "bf_instantiate_cmd", "normalize_cmd", "list_outputs_cmd", "clear_outputs_cmd", "print_output_cmd", "file_cmd", 
			"toggle_cmd", "set_cmd", "get_cmd", "help_cmd", "version_cmd", "quit_cmd", "normalize_cmd_sym", "output", "wff_selection", "_Rnormalize_cmd_50", 
			"instantiate_cmd_sym", "bf_selection", "_Rbf_instantiate_cmd_51", "_Rbf_instantiate_cmd_52", "_Rwff_instantiate_cmd_53", "_Rwff_instantiate_cmd_54", "substitute_cmd_sym", "_Rbf_substitute_cmd_55", "_Rbf_substitute_cmd_56", "_Rbf_substitute_cmd_57", 
			"substitutecmd__sym", "_Rwff_substitute_cmd_58", "_Rwff_substitute_cmd_59", "_Rwff_substitute_cmd_60", "dnf_cmd_sym", "_Rbf_dnf_cmd_61", "cnf_cmd_sym", "_Rbf_cnf_cmd_62", "anf_cmd_sym", "_Rbf_anf_cmd_63", 
			"nnf_cmd_sym", "_Rbf_nnf_cmd_64", "pnf_cmd_sym", "_Rbf_pnf_cmd_65", "mnf_cmd_sym", "_Rbf_mnf_cmd_66", "onf_cmd_sym", "_Rwff_onf_cmd_67", "_Rwff_dnf_cmd_68", "_Rwff_cnf_cmd_69", 
			"_Rwff_anf_cmd_70", "_Rwff_nnf_cmd_71", "_Rwff_pnf_cmd_72", "_Rwff_mnf_cmd_73", "help_cmd_sym", "cli_cmd_sym", "_Rhelp_cmd_74", "version_cmd_sym", "quit_cmd_sym", "selection_sym", 
			"bf_var_selection", "wff_var_selection", "absolute_output", "relative_output", "absolute_output_sym", "output_sym", "_Rabsolute_output_75", "output_id", "relative_output_sym", "_Rclear_outputs_cmd_76", 
			"clear_sym", "file_cmd_sym", "get_cmd_sym", "set_cmd_sym", "toggle_cmd_sym", "instantiate_sym", "substitute_sym", "clear_cmd_sym", "option", "_Rget_cmd_77", 
			"_Rset_cmd_78", "option_value", "bool_option", "severity_opt", "status_opt", "colors_opt", "option_value_true", "option_value_false", "severity", "error_sym", 
			"debug_sym", "trace_sym", "info_sym", "__neg_0", "__neg_1", "__neg_2", "__neg_3", "__neg_4", "__neg_5", "__neg_6", 
			"__neg_7", "__neg_8", "__neg_9", "__neg_10", "__neg_11", "__neg_12", "__neg_13", "__neg_14", "__neg_15", "__neg_16", 
			"__neg_17", "__neg_18", "__neg_19", "__neg_20", "__neg_21", "__neg_22", "__neg_23", "__neg_24", "__neg_25", "__neg_26", 
			"__neg_27", "__neg_28", "__neg_29", "__neg_30", "__neg_31", "__neg_32", "__neg_33", "__neg_34", "__neg_35", "__neg_36", 
			"__neg_37", "__neg_38", "__neg_39", "__neg_40", "__neg_41", "__neg_42", "__neg_43", "__neg_44", "__neg_45", "__neg_46", 
			"__neg_47", "__neg_48", "__neg_49", 
		}) nts.get(nt);
		return nts;
	}
	idni::char_class_fns<terminal_type> load_cc() {
		return idni::predefined_char_classes<char_type, terminal_type>({
			"eof",
			"space",
			"digit",
			"xdigit",
			"alpha",
			"alnum",
			"punct",
			"printable",
		}, nts);
	}
	options load_opts() {
		options o;
		return o;
	}
	idni::prods<char_type, terminal_type> load_prods() {
		idni::prods<char_type, terminal_type> q,
			nul(symbol_type{});
		// _Rcomment_0 => '\t'.
		q(nt(10), (t(1)));
		// _Rcomment_0 => printable.
		q(nt(10), (nt(8)));
		// _Rcomment_1 => null.
		q(nt(11), (nul));
		// _Rcomment_1 => _Rcomment_0 _Rcomment_1.
		q(nt(11), (nt(10)+nt(11)));
		// _Rcomment_2 => '\n'.
		q(nt(12), (t(2)));
		// _Rcomment_2 => '\r'.
		q(nt(12), (t(3)));
		// _Rcomment_2 => eof.
		q(nt(12), (nt(1)));
		// comment => '#' _Rcomment_1 _Rcomment_2.
		q(nt(9), (t(4)+nt(11)+nt(12)));
		// _R___3 => space.
		q(nt(14), (nt(2)));
		// _R___3 => comment.
		q(nt(14), (nt(9)));
		// __ => _R___3 _.
		q(nt(13), (nt(14)+nt(15)));
		// _R__4 => null.
		q(nt(16), (nul));
		// _R__4 => __.
		q(nt(16), (nt(13)));
		// _ => _R__4.
		q(nt(15), (nt(16)));
		// bf_def => ':' '='.
		q(nt(17), (t(5)+t(6)));
		// wff_def => ':' ':' '='.
		q(nt(18), (t(5)+t(5)+t(6)));
		// tau_def => ':' ':' ':' '='.
		q(nt(19), (t(5)+t(5)+t(5)+t(6)));
		// dot => '.'.
		q(nt(20), (t(7)));
		// open_parenthesis => '('.
		q(nt(21), (t(8)));
		// close_parenthesis => ')'.
		q(nt(22), (t(9)));
		// open_bracket => '['.
		q(nt(23), (t(10)));
		// close_bracket => ']'.
		q(nt(24), (t(11)));
		// open_brace => '{'.
		q(nt(25), (t(12)));
		// close_brace => '}'.
		q(nt(26), (t(13)));
		// minus => '-'.
		q(nt(27), (t(14)));
		// colon => ':'.
		q(nt(28), (t(5)));
		// semicolon => ';'.
		q(nt(29), (t(15)));
		// less => '<'.
		q(nt(30), (t(16)));
		// comma => ','.
		q(nt(31), (t(17)));
		// apostrophe => '\''.
		q(nt(32), (t(18)));
		// quote => '"'.
		q(nt(33), (t(19)));
		// _Rchars_5 => alnum.
		q(nt(35), (nt(6)));
		// _Rchars_6 => null.
		q(nt(36), (nul));
		// _Rchars_6 => _Rchars_5 _Rchars_6.
		q(nt(36), (nt(35)+nt(36)));
		// chars => alpha _Rchars_6.
		q(nt(34), (nt(5)+nt(36)));
		// _Rdigits_7 => digit.
		q(nt(38), (nt(3)));
		// _Rdigits_7 => digit _Rdigits_7.
		q(nt(38), (nt(3)+nt(38)));
		// digits => _Rdigits_7.
		q(nt(37), (nt(38)));
		// sym => chars.
		q(nt(39), (nt(34)));
		// _Roffsets_8 => _ comma _ offset.
		q(nt(42), (nt(15)+nt(31)+nt(15)+nt(41)));
		// _Roffsets_9 => null.
		q(nt(43), (nul));
		// _Roffsets_9 => _Roffsets_8 _Roffsets_9.
		q(nt(43), (nt(42)+nt(43)));
		// offsets => open_bracket _ offset _Roffsets_9 _ close_bracket.
		q(nt(40), (nt(23)+nt(15)+nt(41)+nt(43)+nt(15)+nt(24)));
		// __neg_0 => io_var.
		q(nt(363), (nt(48)));
		// _Roffset_10 => variable & ~( __neg_0 ).
		q(nt(49), (nt(47)) & ~(nt(363)));
		// offset => num.
		q(nt(41), (nt(44)));
		// offset => capture.
		q(nt(41), (nt(45)));
		// offset => shift.
		q(nt(41), (nt(46)));
		// offset => _Roffset_10.
		q(nt(41), (nt(49)));
		// __neg_1 => io_var.
		q(nt(364), (nt(48)));
		// _Rshift_11 => variable & ~( __neg_1 ).
		q(nt(50), (nt(47)) & ~(nt(364)));
		// _Rshift_12 => capture.
		q(nt(51), (nt(45)));
		// _Rshift_12 => _Rshift_11.
		q(nt(51), (nt(50)));
		// shift => _Rshift_12 _ minus _ num.
		q(nt(46), (nt(51)+nt(15)+nt(27)+nt(15)+nt(44)));
		// num => digits.
		q(nt(44), (nt(37)));
		// variable => io_var.
		q(nt(47), (nt(48)));
		// variable => var.
		q(nt(47), (nt(52)));
		// io_var => in.
		q(nt(48), (nt(53)));
		// io_var => out.
		q(nt(48), (nt(54)));
		// in => in_var_name open_bracket offset close_bracket.
		q(nt(53), (nt(55)+nt(23)+nt(41)+nt(24)));
		// out => out_var_name open_bracket offset close_bracket.
		q(nt(54), (nt(56)+nt(23)+nt(41)+nt(24)));
		// __neg_2 => wff_t.
		q(nt(365), (nt(58)));
		// __neg_3 => wff_f.
		q(nt(366), (nt(59)));
		// bool_variable => chars & ~( __neg_2 ) & ~( __neg_3 ).
		q(nt(57), (nt(34)) & ~(nt(365)) & ~(nt(366)));
		// capture => capture_var.
		q(nt(45), (nt(60)));
		// capture_var => '$' chars.
		q(nt(60), (t(20)+nt(34)));
		// var => chars.
		q(nt(52), (nt(34)));
		// in_var_name => 'i' '_' chars.
		q(nt(55), (t(21)+t(22)+nt(34)));
		// out_var_name => 'o' '_' chars.
		q(nt(56), (t(23)+t(22)+nt(34)));
		// tau_rule => tau_matcher _ tau_def _ tau_body _ dot.
		q(nt(61), (nt(62)+nt(15)+nt(19)+nt(15)+nt(63)+nt(15)+nt(20)));
		// tau_matcher => tau.
		q(nt(62), (nt(64)));
		// tau_body => tau.
		q(nt(63), (nt(64)));
		// tau_body => tau_collapse_positives_cb.
		q(nt(63), (nt(65)));
		// tau_body => tau_positives_upwards_cb.
		q(nt(63), (nt(66)));
		// __neg_4 => capture.
		q(nt(367), (nt(45)));
		// __neg_5 => tau_and.
		q(nt(368), (nt(68)));
		// __neg_6 => tau_neg.
		q(nt(369), (nt(69)));
		// __neg_7 => tau_or.
		q(nt(370), (nt(70)));
		// __neg_8 => tau_wff.
		q(nt(371), (nt(71)));
		// _Rtau_rec_relation_13 => ~( __neg_4 ) & tau & ~( __neg_5 ) & ~( __neg_6 ) & ~( __neg_7 ) & ~( __neg_8 ).
		q(nt(72), ~(nt(367)) & (nt(64)) & ~(nt(368)) & ~(nt(369)) & ~(nt(370)) & ~(nt(371)));
		// tau_rec_relation => _Rtau_rec_relation_13 _ tau_def _ tau _ dot.
		q(nt(67), (nt(72)+nt(15)+nt(19)+nt(15)+nt(64)+nt(15)+nt(20)));
		// _Rtau_ref_14 => null.
		q(nt(74), (nul));
		// _Rtau_ref_14 => offsets.
		q(nt(74), (nt(40)));
		// tau_ref => sym _ _Rtau_ref_14 _ tau_ref_args.
		q(nt(73), (nt(39)+nt(15)+nt(74)+nt(15)+nt(75)));
		// _Rtau_ref_args_15 => _ tau_ref_arg.
		q(nt(77), (nt(15)+nt(76)));
		// _Rtau_ref_args_16 => null.
		q(nt(78), (nul));
		// _Rtau_ref_args_16 => _Rtau_ref_args_15 _Rtau_ref_args_16.
		q(nt(78), (nt(77)+nt(78)));
		// tau_ref_args => open_parenthesis _Rtau_ref_args_16 _ close_parenthesis.
		q(nt(75), (nt(21)+nt(78)+nt(15)+nt(22)));
		// tau_ref_arg => capture.
		q(nt(76), (nt(45)));
		// tau_ref_arg => variable.
		q(nt(76), (nt(47)));
		// tau_ref_arg => bf.
		q(nt(76), (nt(79)));
		// tau => capture.
		q(nt(64), (nt(45)));
		// tau => tau_and.
		q(nt(64), (nt(68)));
		// tau => tau_neg.
		q(nt(64), (nt(69)));
		// tau => tau_or.
		q(nt(64), (nt(70)));
		// tau => tau_wff.
		q(nt(64), (nt(71)));
		// tau => tau_ref.
		q(nt(64), (nt(73)));
		// tau_and => open_parenthesis _ tau _ tau_and_sym _ tau _ close_parenthesis.
		q(nt(68), (nt(21)+nt(15)+nt(64)+nt(15)+nt(80)+nt(15)+nt(64)+nt(15)+nt(22)));
		// tau_or => open_parenthesis _ tau _ tau_or_sym _ tau _ close_parenthesis.
		q(nt(70), (nt(21)+nt(15)+nt(64)+nt(15)+nt(81)+nt(15)+nt(64)+nt(15)+nt(22)));
		// tau_neg => tau_neg_sym _ tau.
		q(nt(69), (nt(82)+nt(15)+nt(64)));
		// tau_wff => open_brace _ wff _ close_brace.
		q(nt(71), (nt(25)+nt(15)+nt(83)+nt(15)+nt(26)));
		// tau_and_sym => '&' '&' '&'.
		q(nt(80), (t(24)+t(24)+t(24)));
		// tau_or_sym => '|' '|' '|'.
		q(nt(81), (t(25)+t(25)+t(25)));
		// tau_neg_sym => '!' '!' '!'.
		q(nt(82), (t(26)+t(26)+t(26)));
		// wff_rule => wff_matcher _ wff_def _ wff_body _ dot.
		q(nt(84), (nt(85)+nt(15)+nt(18)+nt(15)+nt(86)+nt(15)+nt(20)));
		// wff_matcher => wff.
		q(nt(85), (nt(83)));
		// wff_body => wff.
		q(nt(86), (nt(83)));
		// wff_body => bf_eq_cb.
		q(nt(86), (nt(87)));
		// wff_body => bf_neq_cb.
		q(nt(86), (nt(88)));
		// wff_body => wff_has_clashing_subformulas_cb.
		q(nt(86), (nt(89)));
		// wff_body => wff_has_subformula_cb.
		q(nt(86), (nt(90)));
		// wff_body => wff_remove_existential_cb.
		q(nt(86), (nt(91)));
		// wff_body => wff_remove_bexistential_cb.
		q(nt(86), (nt(92)));
		// wff_body => wff_remove_buniversal_cb.
		q(nt(86), (nt(93)));
		// __neg_9 => capture.
		q(nt(372), (nt(45)));
		// __neg_10 => bool_variable.
		q(nt(373), (nt(57)));
		// __neg_11 => wff_t.
		q(nt(374), (nt(58)));
		// __neg_12 => wff_f.
		q(nt(375), (nt(59)));
		// __neg_13 => wff_and.
		q(nt(376), (nt(95)));
		// __neg_14 => wff_neg.
		q(nt(377), (nt(96)));
		// __neg_15 => wff_xor.
		q(nt(378), (nt(97)));
		// __neg_16 => wff_conditional.
		q(nt(379), (nt(98)));
		// __neg_17 => wff_or.
		q(nt(380), (nt(99)));
		// __neg_18 => wff_all.
		q(nt(381), (nt(100)));
		// __neg_19 => wff_ex.
		q(nt(382), (nt(101)));
		// __neg_20 => wff_imply.
		q(nt(383), (nt(102)));
		// __neg_21 => wff_equiv.
		q(nt(384), (nt(103)));
		// __neg_22 => wff_ball.
		q(nt(385), (nt(104)));
		// __neg_23 => wff_bex.
		q(nt(386), (nt(105)));
		// __neg_24 => bf_eq.
		q(nt(387), (nt(106)));
		// __neg_25 => bf_neq.
		q(nt(388), (nt(107)));
		// __neg_26 => bf_less.
		q(nt(389), (nt(108)));
		// __neg_27 => bf_less_equal.
		q(nt(390), (nt(109)));
		// __neg_28 => bf_greater.
		q(nt(391), (nt(110)));
		// __neg_29 => bf_interval.
		q(nt(392), (nt(111)));
		// __neg_30 => bf_not_less_equal.
		q(nt(393), (nt(112)));
		// _Rwff_rec_relation_17 => ~( __neg_9 ) & ~( __neg_10 ) & ~( __neg_11 ) & ~( __neg_12 ) & wff & ~( __neg_13 ) & ~( __neg_14 ) & ~( __neg_15 ) & ~( __neg_16 ) & ~( __neg_17 ) & ~( __neg_18 ) & ~( __neg_19 ) & ~( __neg_20 ) & ~( __neg_21 ) & ~( __neg_22 ) & ~( __neg_23 ) & ~( __neg_24 ) & ~( __neg_25 ) & ~( __neg_26 ) & ~( __neg_27 ) & ~( __neg_28 ) & ~( __neg_29 ) & ~( __neg_30 ).
		q(nt(113), ~(nt(372)) & ~(nt(373)) & ~(nt(374)) & ~(nt(375)) & (nt(83)) & ~(nt(376)) & ~(nt(377)) & ~(nt(378)) & ~(nt(379)) & ~(nt(380)) & ~(nt(381)) & ~(nt(382)) & ~(nt(383)) & ~(nt(384)) & ~(nt(385)) & ~(nt(386)) & ~(nt(387)) & ~(nt(388)) & ~(nt(389)) & ~(nt(390)) & ~(nt(391)) & ~(nt(392)) & ~(nt(393)));
		// wff_rec_relation => _Rwff_rec_relation_17 _ wff_def _ wff _ dot.
		q(nt(94), (nt(113)+nt(15)+nt(18)+nt(15)+nt(83)+nt(15)+nt(20)));
		// wff => capture.
		q(nt(83), (nt(45)));
		// wff => bool_variable.
		q(nt(83), (nt(57)));
		// wff => wff_t.
		q(nt(83), (nt(58)));
		// wff => wff_f.
		q(nt(83), (nt(59)));
		// wff => wff_and.
		q(nt(83), (nt(95)));
		// wff => wff_neg.
		q(nt(83), (nt(96)));
		// wff => wff_xor.
		q(nt(83), (nt(97)));
		// wff => wff_conditional.
		q(nt(83), (nt(98)));
		// wff => wff_or.
		q(nt(83), (nt(99)));
		// wff => wff_all.
		q(nt(83), (nt(100)));
		// wff => wff_ex.
		q(nt(83), (nt(101)));
		// wff => wff_imply.
		q(nt(83), (nt(102)));
		// wff => wff_equiv.
		q(nt(83), (nt(103)));
		// wff => wff_ball.
		q(nt(83), (nt(104)));
		// wff => wff_bex.
		q(nt(83), (nt(105)));
		// wff => bf_eq.
		q(nt(83), (nt(106)));
		// wff => bf_neq.
		q(nt(83), (nt(107)));
		// wff => bf_less.
		q(nt(83), (nt(108)));
		// wff => bf_less_equal.
		q(nt(83), (nt(109)));
		// wff => bf_greater.
		q(nt(83), (nt(110)));
		// wff => bf_interval.
		q(nt(83), (nt(111)));
		// wff => bf_not_less_equal.
		q(nt(83), (nt(112)));
		// wff => wff_ref.
		q(nt(83), (nt(114)));
		// _Rwff_ref_18 => null.
		q(nt(115), (nul));
		// _Rwff_ref_18 => offsets.
		q(nt(115), (nt(40)));
		// wff_ref => sym _ _Rwff_ref_18 _ wff_ref_args.
		q(nt(114), (nt(39)+nt(15)+nt(115)+nt(15)+nt(116)));
		// _Rwff_ref_args_19 => _ wff_ref_arg.
		q(nt(118), (nt(15)+nt(117)));
		// _Rwff_ref_args_20 => null.
		q(nt(119), (nul));
		// _Rwff_ref_args_20 => _Rwff_ref_args_19 _Rwff_ref_args_20.
		q(nt(119), (nt(118)+nt(119)));
		// wff_ref_args => open_parenthesis _Rwff_ref_args_20 _ close_parenthesis.
		q(nt(116), (nt(21)+nt(119)+nt(15)+nt(22)));
		// wff_ref_arg => capture.
		q(nt(117), (nt(45)));
		// wff_ref_arg => variable.
		q(nt(117), (nt(47)));
		// wff_ref_arg => bf.
		q(nt(117), (nt(79)));
		// wff_and => open_parenthesis _ wff _ wff_and_sym _ wff _ close_parenthesis.
		q(nt(95), (nt(21)+nt(15)+nt(83)+nt(15)+nt(120)+nt(15)+nt(83)+nt(15)+nt(22)));
		// wff_or => open_parenthesis _ wff _ wff_or_sym _ wff _ close_parenthesis.
		q(nt(99), (nt(21)+nt(15)+nt(83)+nt(15)+nt(121)+nt(15)+nt(83)+nt(15)+nt(22)));
		// wff_xor => open_parenthesis _ wff _ wff_xor_sym _ wff _ close_parenthesis.
		q(nt(97), (nt(21)+nt(15)+nt(83)+nt(15)+nt(122)+nt(15)+nt(83)+nt(15)+nt(22)));
		// wff_conditional => open_parenthesis _ wff _ wff_conditional_sym _ wff _ colon _ wff _ close_parenthesis.
		q(nt(98), (nt(21)+nt(15)+nt(83)+nt(15)+nt(123)+nt(15)+nt(83)+nt(15)+nt(28)+nt(15)+nt(83)+nt(15)+nt(22)));
		// wff_neg => wff_neg_sym _ wff.
		q(nt(96), (nt(124)+nt(15)+nt(83)));
		// wff_imply => open_parenthesis _ wff _ wff_imply_sym _ wff _ close_parenthesis.
		q(nt(102), (nt(21)+nt(15)+nt(83)+nt(15)+nt(125)+nt(15)+nt(83)+nt(15)+nt(22)));
		// wff_equiv => open_parenthesis _ wff _ wff_equiv_sym _ wff _ close_parenthesis.
		q(nt(103), (nt(21)+nt(15)+nt(83)+nt(15)+nt(126)+nt(15)+nt(83)+nt(15)+nt(22)));
		// _Rwff_all_21 => capture.
		q(nt(128), (nt(45)));
		// _Rwff_all_21 => variable.
		q(nt(128), (nt(47)));
		// wff_all => wff_all_sym __ _Rwff_all_21 __ wff.
		q(nt(100), (nt(127)+nt(13)+nt(128)+nt(13)+nt(83)));
		// _Rwff_ex_22 => capture.
		q(nt(130), (nt(45)));
		// _Rwff_ex_22 => variable.
		q(nt(130), (nt(47)));
		// wff_ex => wff_ex_sym __ _Rwff_ex_22 __ wff.
		q(nt(101), (nt(129)+nt(13)+nt(130)+nt(13)+nt(83)));
		// _Rwff_ball_23 => capture.
		q(nt(132), (nt(45)));
		// _Rwff_ball_23 => bool_variable.
		q(nt(132), (nt(57)));
		// wff_ball => wff_ball_sym __ _Rwff_ball_23 __ wff.
		q(nt(104), (nt(131)+nt(13)+nt(132)+nt(13)+nt(83)));
		// _Rwff_bex_24 => capture.
		q(nt(134), (nt(45)));
		// _Rwff_bex_24 => bool_variable.
		q(nt(134), (nt(57)));
		// wff_bex => wff_bex_sym __ _Rwff_bex_24 __ wff.
		q(nt(105), (nt(133)+nt(13)+nt(134)+nt(13)+nt(83)));
		// bf_eq => open_parenthesis _ bf _ bf_equality_sym _ bf _ close_parenthesis.
		q(nt(106), (nt(21)+nt(15)+nt(79)+nt(15)+nt(135)+nt(15)+nt(79)+nt(15)+nt(22)));
		// bf_neq => open_parenthesis _ bf _ bf_nequality_sym _ bf _ close_parenthesis.
		q(nt(107), (nt(21)+nt(15)+nt(79)+nt(15)+nt(136)+nt(15)+nt(79)+nt(15)+nt(22)));
		// bf_less => open_parenthesis _ bf _ bf_less_sym _ bf _ close_parenthesis.
		q(nt(108), (nt(21)+nt(15)+nt(79)+nt(15)+nt(137)+nt(15)+nt(79)+nt(15)+nt(22)));
		// bf_less_equal => open_parenthesis _ bf _ bf_less_equal_sym _ bf _ close_parenthesis.
		q(nt(109), (nt(21)+nt(15)+nt(79)+nt(15)+nt(138)+nt(15)+nt(79)+nt(15)+nt(22)));
		// bf_not_less_equal => open_parenthesis _ bf _ bf_not_less_equal_sym _ bf _ close_parenthesis.
		q(nt(112), (nt(21)+nt(15)+nt(79)+nt(15)+nt(139)+nt(15)+nt(79)+nt(15)+nt(22)));
		// bf_greater => open_parenthesis _ bf _ bf_greater_sym _ bf _ close_parenthesis.
		q(nt(110), (nt(21)+nt(15)+nt(79)+nt(15)+nt(140)+nt(15)+nt(79)+nt(15)+nt(22)));
		// bf_interval => open_parenthesis _ bf _ bf_less_equal_sym _ bf _ bf_less_equal_sym _ bf _ close_parenthesis.
		q(nt(111), (nt(21)+nt(15)+nt(79)+nt(15)+nt(138)+nt(15)+nt(79)+nt(15)+nt(138)+nt(15)+nt(79)+nt(15)+nt(22)));
		// wff_and_sym => '&' '&'.
		q(nt(120), (t(24)+t(24)));
		// wff_or_sym => '|' '|'.
		q(nt(121), (t(25)+t(25)));
		// wff_xor_sym => '^'.
		q(nt(122), (t(27)));
		// wff_conditional_sym => '?'.
		q(nt(123), (t(28)));
		// wff_neg_sym => '!'.
		q(nt(124), (t(26)));
		// wff_imply_sym => '-' '>'.
		q(nt(125), (t(14)+t(29)));
		// wff_equiv_sym => '<' '-' '>'.
		q(nt(126), (t(16)+t(14)+t(29)));
		// wff_all_sym => 'a' 'l' 'l'.
		q(nt(127), (t(30)+t(31)+t(31)));
		// wff_ex_sym => 'e' 'x'.
		q(nt(129), (t(32)+t(33)));
		// wff_ball_sym => 'b' 'a' 'l' 'l'.
		q(nt(131), (t(34)+t(30)+t(31)+t(31)));
		// wff_bex_sym => 'b' 'e' 'x'.
		q(nt(133), (t(34)+t(32)+t(33)));
		// wff_t => 'T'.
		q(nt(58), (t(35)));
		// wff_f => 'F'.
		q(nt(59), (t(36)));
		// bf_rule => bf_matcher _ bf_def _ bf_body _ dot.
		q(nt(141), (nt(142)+nt(15)+nt(17)+nt(15)+nt(143)+nt(15)+nt(20)));
		// bf_matcher => bf.
		q(nt(142), (nt(79)));
		// bf_body => bf.
		q(nt(143), (nt(79)));
		// bf_body => bf_not_less_equal.
		q(nt(143), (nt(112)));
		// bf_body => bf_is_zero_cb.
		q(nt(143), (nt(144)));
		// bf_body => bf_is_one_cb.
		q(nt(143), (nt(145)));
		// bf_body => bf_has_subformula_cb.
		q(nt(143), (nt(146)));
		// bf_body => bf_remove_funiversal_cb.
		q(nt(143), (nt(147)));
		// bf_body => bf_remove_fexistential_cb.
		q(nt(143), (nt(148)));
		// bf_body => bf_and_cb.
		q(nt(143), (nt(149)));
		// bf_body => bf_or_cb.
		q(nt(143), (nt(150)));
		// bf_body => bf_xor_cb.
		q(nt(143), (nt(151)));
		// bf_body => bf_neg_cb.
		q(nt(143), (nt(152)));
		// bf => capture.
		q(nt(79), (nt(45)));
		// bf => variable.
		q(nt(79), (nt(47)));
		// bf => bf_ref.
		q(nt(79), (nt(153)));
		// bf => bf_constant.
		q(nt(79), (nt(154)));
		// bf => bf_and.
		q(nt(79), (nt(155)));
		// bf => bf_neg.
		q(nt(79), (nt(156)));
		// bf => bf_xor.
		q(nt(79), (nt(157)));
		// bf => bf_or.
		q(nt(79), (nt(158)));
		// bf => bf_all.
		q(nt(79), (nt(159)));
		// bf => bf_ex.
		q(nt(79), (nt(160)));
		// bf => bf_t.
		q(nt(79), (nt(161)));
		// bf => bf_f.
		q(nt(79), (nt(162)));
		// bf => bf_splitter.
		q(nt(79), (nt(163)));
		// __neg_31 => capture.
		q(nt(394), (nt(45)));
		// __neg_32 => variable.
		q(nt(395), (nt(47)));
		// __neg_33 => bf_eq.
		q(nt(396), (nt(106)));
		// __neg_34 => bf_neq.
		q(nt(397), (nt(107)));
		// __neg_35 => bf_constant.
		q(nt(398), (nt(154)));
		// __neg_36 => bf_and.
		q(nt(399), (nt(155)));
		// __neg_37 => bf_neg.
		q(nt(400), (nt(156)));
		// __neg_38 => bf_xor.
		q(nt(401), (nt(157)));
		// __neg_39 => bf_or.
		q(nt(402), (nt(158)));
		// __neg_40 => bf_all.
		q(nt(403), (nt(159)));
		// __neg_41 => bf_ex.
		q(nt(404), (nt(160)));
		// __neg_42 => bf_t.
		q(nt(405), (nt(161)));
		// __neg_43 => bf_f.
		q(nt(406), (nt(162)));
		// __neg_44 => bf_splitter.
		q(nt(407), (nt(163)));
		// _Rbf_rec_relation_25 => ~( __neg_31 ) & ~( __neg_32 ) & bf & ~( __neg_33 ) & ~( __neg_34 ) & ~( __neg_35 ) & ~( __neg_36 ) & ~( __neg_37 ) & ~( __neg_38 ) & ~( __neg_39 ) & ~( __neg_40 ) & ~( __neg_41 ) & ~( __neg_42 ) & ~( __neg_43 ) & ~( __neg_44 ).
		q(nt(165), ~(nt(394)) & ~(nt(395)) & (nt(79)) & ~(nt(396)) & ~(nt(397)) & ~(nt(398)) & ~(nt(399)) & ~(nt(400)) & ~(nt(401)) & ~(nt(402)) & ~(nt(403)) & ~(nt(404)) & ~(nt(405)) & ~(nt(406)) & ~(nt(407)));
		// bf_rec_relation => _Rbf_rec_relation_25 _ bf_def _ bf _ dot.
		q(nt(164), (nt(165)+nt(15)+nt(17)+nt(15)+nt(79)+nt(15)+nt(20)));
		// _Rbf_ref_26 => null.
		q(nt(166), (nul));
		// _Rbf_ref_26 => offsets.
		q(nt(166), (nt(40)));
		// bf_ref => sym _Rbf_ref_26 bf_ref_args.
		q(nt(153), (nt(39)+nt(166)+nt(167)));
		// _Rbf_ref_args_27 => _ bf_ref_arg.
		q(nt(169), (nt(15)+nt(168)));
		// _Rbf_ref_args_28 => null.
		q(nt(170), (nul));
		// _Rbf_ref_args_28 => _Rbf_ref_args_27 _Rbf_ref_args_28.
		q(nt(170), (nt(169)+nt(170)));
		// bf_ref_args => open_parenthesis _Rbf_ref_args_28 _ close_parenthesis.
		q(nt(167), (nt(21)+nt(170)+nt(15)+nt(22)));
		// bf_ref_arg => capture.
		q(nt(168), (nt(45)));
		// bf_ref_arg => variable.
		q(nt(168), (nt(47)));
		// bf_ref_arg => bf.
		q(nt(168), (nt(79)));
		// bf_and => open_parenthesis _ bf _ bf_and_sym _ bf _ close_parenthesis.
		q(nt(155), (nt(21)+nt(15)+nt(79)+nt(15)+nt(171)+nt(15)+nt(79)+nt(15)+nt(22)));
		// bf_or => open_parenthesis _ bf _ bf_or_sym _ bf _ close_parenthesis.
		q(nt(158), (nt(21)+nt(15)+nt(79)+nt(15)+nt(172)+nt(15)+nt(79)+nt(15)+nt(22)));
		// bf_xor => open_parenthesis _ bf _ bf_xor_sym _ bf _ close_parenthesis.
		q(nt(157), (nt(21)+nt(15)+nt(79)+nt(15)+nt(173)+nt(15)+nt(79)+nt(15)+nt(22)));
		// bf_neg => bf _ bf_neg_sym.
		q(nt(156), (nt(79)+nt(15)+nt(174)));
		// _Rbf_all_29 => capture.
		q(nt(176), (nt(45)));
		// _Rbf_all_29 => variable.
		q(nt(176), (nt(47)));
		// bf_all => bf_all_sym __ _Rbf_all_29 __ bf.
		q(nt(159), (nt(175)+nt(13)+nt(176)+nt(13)+nt(79)));
		// _Rbf_ex_30 => capture.
		q(nt(178), (nt(45)));
		// _Rbf_ex_30 => variable.
		q(nt(178), (nt(47)));
		// bf_ex => bf_ex_sym __ _Rbf_ex_30 __ bf.
		q(nt(160), (nt(177)+nt(13)+nt(178)+nt(13)+nt(79)));
		// bf_splitter => bf_splitter_sym _ open_parenthesis _ bf _ close_parenthesis.
		q(nt(163), (nt(179)+nt(15)+nt(21)+nt(15)+nt(79)+nt(15)+nt(22)));
		// bf_and_sym => '&'.
		q(nt(171), (t(24)));
		// bf_or_sym => '|'.
		q(nt(172), (t(25)));
		// bf_xor_sym => '+'.
		q(nt(173), (t(37)));
		// bf_neg_sym => apostrophe.
		q(nt(174), (nt(32)));
		// bf_equality_sym => '='.
		q(nt(135), (t(6)));
		// bf_nequality_sym => '!' '='.
		q(nt(136), (t(26)+t(6)));
		// bf_less_sym => '<'.
		q(nt(137), (t(16)));
		// bf_less_equal_sym => '<' '='.
		q(nt(138), (t(16)+t(6)));
		// bf_not_less_equal_sym => '!' '<' '='.
		q(nt(139), (t(26)+t(16)+t(6)));
		// bf_greater_sym => '>'.
		q(nt(140), (t(29)));
		// bf_all_sym => 'f' 'a' 'l' 'l'.
		q(nt(175), (t(38)+t(30)+t(31)+t(31)));
		// bf_ex_sym => 'f' 'e' 'x'.
		q(nt(177), (t(38)+t(32)+t(33)));
		// bf_splitter_sym => 'S'.
		q(nt(179), (t(39)));
		// bf_t => '1'.
		q(nt(161), (t(40)));
		// bf_f => '0'.
		q(nt(162), (t(41)));
		// bf_constant => open_brace _ constant _ close_brace.
		q(nt(154), (nt(25)+nt(15)+nt(180)+nt(15)+nt(26)));
		// constant => capture.
		q(nt(180), (nt(45)));
		// constant => binding.
		q(nt(180), (nt(181)));
		// binding => source_binding.
		q(nt(181), (nt(182)));
		// binding => named_binding.
		q(nt(181), (nt(183)));
		// named_binding => chars.
		q(nt(183), (nt(34)));
		// source_binding => type _ colon _ source.
		q(nt(182), (nt(184)+nt(15)+nt(28)+nt(15)+nt(185)));
		// type => null.
		q(nt(184), (nul));
		// type => chars.
		q(nt(184), (nt(34)));
		// source0 => space.
		q(nt(186), (nt(2)));
		// source0 => alnum.
		q(nt(186), (nt(6)));
		// source0 => punct.
		q(nt(186), (nt(7)));
		// _Rsource_31 => source0.
		q(nt(187), (nt(186)));
		// _Rsource_32 => _Rsource_31.
		q(nt(188), (nt(187)));
		// _Rsource_32 => _Rsource_31 _Rsource_32.
		q(nt(188), (nt(187)+nt(188)));
		// source => _Rsource_32.
		q(nt(185), (nt(188)));
		// bf_and_cb => bf_and_cb_sym __ bf_cb_arg __ bf_cb_arg.
		q(nt(149), (nt(189)+nt(13)+nt(190)+nt(13)+nt(190)));
		// bf_or_cb => bf_or_cb_sym __ bf_cb_arg __ bf_cb_arg.
		q(nt(150), (nt(191)+nt(13)+nt(190)+nt(13)+nt(190)));
		// bf_xor_cb => bf_xor_cb_sym __ bf_cb_arg __ bf_cb_arg.
		q(nt(151), (nt(192)+nt(13)+nt(190)+nt(13)+nt(190)));
		// bf_neg_cb => bf_neg_cb_sym __ bf_cb_arg.
		q(nt(152), (nt(193)+nt(13)+nt(190)));
		// bf_eq_cb => bf_eq_cb_sym __ bf_cb_arg __ wff_cb_arg __ wff_cb_arg.
		q(nt(87), (nt(194)+nt(13)+nt(190)+nt(13)+nt(195)+nt(13)+nt(195)));
		// bf_neq_cb => bf_neq_cb_sym __ bf_cb_arg __ wff_cb_arg __ wff_cb_arg.
		q(nt(88), (nt(196)+nt(13)+nt(190)+nt(13)+nt(195)+nt(13)+nt(195)));
		// bf_is_zero_cb => bf_is_zero_cb_sym __ bf_cb_arg __ bf_cb_arg.
		q(nt(144), (nt(197)+nt(13)+nt(190)+nt(13)+nt(190)));
		// bf_is_one_cb => bf_is_one_cb_sym __ bf_cb_arg __ bf_cb_arg.
		q(nt(145), (nt(198)+nt(13)+nt(190)+nt(13)+nt(190)));
		// bf_remove_funiversal_cb => bf_remove_funiversal_cb_sym __ bf_cb_arg __ bf_cb_arg __ bf_cb_arg __ bf_cb_arg.
		q(nt(147), (nt(199)+nt(13)+nt(190)+nt(13)+nt(190)+nt(13)+nt(190)+nt(13)+nt(190)));
		// bf_remove_fexistential_cb => bf_remove_fexistential_cb_sym __ bf_cb_arg __ bf_cb_arg __ bf_cb_arg __ bf_cb_arg.
		q(nt(148), (nt(200)+nt(13)+nt(190)+nt(13)+nt(190)+nt(13)+nt(190)+nt(13)+nt(190)));
		// wff_remove_existential_cb => wff_remove_existential_cb_sym __ wff_cb_arg __ wff_cb_arg.
		q(nt(91), (nt(201)+nt(13)+nt(195)+nt(13)+nt(195)));
		// wff_remove_bexistential_cb => wff_remove_bexistential_cb_sym __ wff_cb_arg __ wff_cb_arg __ wff_cb_arg __ wff_cb_arg.
		q(nt(92), (nt(202)+nt(13)+nt(195)+nt(13)+nt(195)+nt(13)+nt(195)+nt(13)+nt(195)));
		// wff_remove_buniversal_cb => wff_remove_buniversal_cb_sym __ wff_cb_arg __ wff_cb_arg __ wff_cb_arg __ wff_cb_arg.
		q(nt(93), (nt(203)+nt(13)+nt(195)+nt(13)+nt(195)+nt(13)+nt(195)+nt(13)+nt(195)));
		// wff_has_clashing_subformulas_cb => wff_has_clashing_subformulas_cb_sym __ wff_cb_arg __ wff_cb_arg.
		q(nt(89), (nt(204)+nt(13)+nt(195)+nt(13)+nt(195)));
		// bf_has_subformula_cb => bf_has_subformula_cb_sym __ bf_cb_arg __ bf_cb_arg __ bf_cb_arg.
		q(nt(146), (nt(205)+nt(13)+nt(190)+nt(13)+nt(190)+nt(13)+nt(190)));
		// wff_has_subformula_cb => wff_has_subformula_cb_sym __ wff_cb_arg __ wff_cb_arg __ wff_cb_arg.
		q(nt(90), (nt(206)+nt(13)+nt(195)+nt(13)+nt(195)+nt(13)+nt(195)));
		// bf_has_subformula_cb_sym => 'b' 'f' '_' 'h' 'a' 's' '_' 's' 'u' 'b' 'f' 'o' 'r' 'm' 'u' 'l' 'a' '_' 'c' 'b'.
		q(nt(205), (t(34)+t(38)+t(22)+t(42)+t(30)+t(43)+t(22)+t(43)+t(44)+t(34)+t(38)+t(23)+t(45)+t(46)+t(44)+t(31)+t(30)+t(22)+t(47)+t(34)));
		// wff_has_clashing_subformulas_cb_sym => 'w' 'f' 'f' '_' 'h' 'a' 's' '_' 'c' 'l' 'a' 's' 'h' 'i' 'n' 'g' '_' 's' 'u' 'b' 'f' 'o' 'r' 'm' 'u' 'l' 'a' 's' '_' 'c' 'b'.
		q(nt(204), (t(48)+t(38)+t(38)+t(22)+t(42)+t(30)+t(43)+t(22)+t(47)+t(31)+t(30)+t(43)+t(42)+t(21)+t(49)+t(50)+t(22)+t(43)+t(44)+t(34)+t(38)+t(23)+t(45)+t(46)+t(44)+t(31)+t(30)+t(43)+t(22)+t(47)+t(34)));
		// wff_has_subformula_cb_sym => 'w' 'f' 'f' '_' 'h' 'a' 's' '_' 's' 'u' 'b' 'f' 'o' 'r' 'm' 'u' 'l' 'a' '_' 'c' 'b'.
		q(nt(206), (t(48)+t(38)+t(38)+t(22)+t(42)+t(30)+t(43)+t(22)+t(43)+t(44)+t(34)+t(38)+t(23)+t(45)+t(46)+t(44)+t(31)+t(30)+t(22)+t(47)+t(34)));
		// wff_remove_existential_cb_sym => 'w' 'f' 'f' '_' 'r' 'e' 'm' 'o' 'v' 'e' '_' 'e' 'x' 'i' 's' 't' 'e' 'n' 't' 'i' 'a' 'l' '_' 'c' 'b'.
		q(nt(201), (t(48)+t(38)+t(38)+t(22)+t(45)+t(32)+t(46)+t(23)+t(51)+t(32)+t(22)+t(32)+t(33)+t(21)+t(43)+t(52)+t(32)+t(49)+t(52)+t(21)+t(30)+t(31)+t(22)+t(47)+t(34)));
		// wff_remove_bexistential_cb_sym => 'w' 'f' 'f' '_' 'r' 'e' 'm' 'o' 'v' 'e' '_' 'b' 'e' 'x' 'i' 's' 't' 'e' 'n' 't' 'i' 'a' 'l' '_' 'c' 'b'.
		q(nt(202), (t(48)+t(38)+t(38)+t(22)+t(45)+t(32)+t(46)+t(23)+t(51)+t(32)+t(22)+t(34)+t(32)+t(33)+t(21)+t(43)+t(52)+t(32)+t(49)+t(52)+t(21)+t(30)+t(31)+t(22)+t(47)+t(34)));
		// wff_remove_buniversal_cb_sym => 'w' 'f' 'f' '_' 'r' 'e' 'm' 'o' 'v' 'e' '_' 'b' 'u' 'n' 'i' 'v' 'e' 'r' 's' 'a' 'l' '_' 'c' 'b'.
		q(nt(203), (t(48)+t(38)+t(38)+t(22)+t(45)+t(32)+t(46)+t(23)+t(51)+t(32)+t(22)+t(34)+t(44)+t(49)+t(21)+t(51)+t(32)+t(45)+t(43)+t(30)+t(31)+t(22)+t(47)+t(34)));
		// bf_remove_fexistential_cb_sym => 'b' 'f' '_' 'r' 'e' 'm' 'o' 'v' 'e' '_' 'f' 'e' 'x' 'i' 's' 't' 'e' 'n' 't' 'i' 'a' 'l' '_' 'c' 'b'.
		q(nt(200), (t(34)+t(38)+t(22)+t(45)+t(32)+t(46)+t(23)+t(51)+t(32)+t(22)+t(38)+t(32)+t(33)+t(21)+t(43)+t(52)+t(32)+t(49)+t(52)+t(21)+t(30)+t(31)+t(22)+t(47)+t(34)));
		// bf_remove_funiversal_cb_sym => 'b' 'f' '_' 'r' 'e' 'm' 'o' 'v' 'e' '_' 'f' 'u' 'n' 'i' 'v' 'e' 'r' 's' 'a' 'l' '_' 'c' 'b'.
		q(nt(199), (t(34)+t(38)+t(22)+t(45)+t(32)+t(46)+t(23)+t(51)+t(32)+t(22)+t(38)+t(44)+t(49)+t(21)+t(51)+t(32)+t(45)+t(43)+t(30)+t(31)+t(22)+t(47)+t(34)));
		// bf_cb_arg => bf.
		q(nt(190), (nt(79)));
		// wff_cb_arg => wff.
		q(nt(195), (nt(83)));
		// bf_and_cb_sym => 'b' 'f' '_' 'a' 'n' 'd' '_' 'c' 'b'.
		q(nt(189), (t(34)+t(38)+t(22)+t(30)+t(49)+t(53)+t(22)+t(47)+t(34)));
		// bf_or_cb_sym => 'b' 'f' '_' 'o' 'r' '_' 'c' 'b'.
		q(nt(191), (t(34)+t(38)+t(22)+t(23)+t(45)+t(22)+t(47)+t(34)));
		// bf_xor_cb_sym => 'b' 'f' '_' 'x' 'o' 'r' '_' 'c' 'b'.
		q(nt(192), (t(34)+t(38)+t(22)+t(33)+t(23)+t(45)+t(22)+t(47)+t(34)));
		// bf_neg_cb_sym => 'b' 'f' '_' 'n' 'e' 'g' '_' 'c' 'b'.
		q(nt(193), (t(34)+t(38)+t(22)+t(49)+t(32)+t(50)+t(22)+t(47)+t(34)));
		// bf_eq_cb_sym => 'b' 'f' '_' 'e' 'q' '_' 'c' 'b'.
		q(nt(194), (t(34)+t(38)+t(22)+t(32)+t(54)+t(22)+t(47)+t(34)));
		// bf_neq_cb_sym => 'b' 'f' '_' 'n' 'e' 'q' '_' 'c' 'b'.
		q(nt(196), (t(34)+t(38)+t(22)+t(49)+t(32)+t(54)+t(22)+t(47)+t(34)));
		// bf_is_zero_cb_sym => 'b' 'f' '_' 'i' 's' '_' 'z' 'e' 'r' 'o' '_' 'c' 'b'.
		q(nt(197), (t(34)+t(38)+t(22)+t(21)+t(43)+t(22)+t(55)+t(32)+t(45)+t(23)+t(22)+t(47)+t(34)));
		// bf_is_one_cb_sym => 'b' 'f' '_' 'i' 's' '_' 'o' 'n' 'e' '_' 'c' 'b'.
		q(nt(198), (t(34)+t(38)+t(22)+t(21)+t(43)+t(22)+t(23)+t(49)+t(32)+t(22)+t(47)+t(34)));
		// _Rtau_collapse_positives_cb_33 => tau_collapse_positives_cb_sym __ tau_cb_arg __ tau_cb_arg __ tau_cb_arg.
		q(nt(209), (nt(207)+nt(13)+nt(208)+nt(13)+nt(208)+nt(13)+nt(208)));
		// _Rtau_collapse_positives_cb_34 => tau_collapse_positives_cb_sym __ tau_cb_arg __ tau_cb_arg.
		q(nt(210), (nt(207)+nt(13)+nt(208)+nt(13)+nt(208)));
		// tau_collapse_positives_cb => _Rtau_collapse_positives_cb_33.
		q(nt(65), (nt(209)));
		// tau_collapse_positives_cb => _Rtau_collapse_positives_cb_34.
		q(nt(65), (nt(210)));
		// tau_positives_upwards_cb => tau_positives_upwards_cb_sym __ tau_cb_arg __ tau_cb_arg.
		q(nt(66), (nt(211)+nt(13)+nt(208)+nt(13)+nt(208)));
		// tau_cb_arg => capture.
		q(nt(208), (nt(45)));
		// tau_cb_arg => tau.
		q(nt(208), (nt(64)));
		// tau_collapse_positives_cb_sym => 't' 'a' 'u' '_' 'c' 'o' 'l' 'l' 'a' 'p' 's' 'e' '_' 'p' 'o' 's' 'i' 't' 'i' 'v' 'e' 's' '_' 'c' 'b'.
		q(nt(207), (t(52)+t(30)+t(44)+t(22)+t(47)+t(23)+t(31)+t(31)+t(30)+t(56)+t(43)+t(32)+t(22)+t(56)+t(23)+t(43)+t(21)+t(52)+t(21)+t(51)+t(32)+t(43)+t(22)+t(47)+t(34)));
		// tau_positives_upwards_cb_sym => 't' 'a' 'u' '_' 'p' 'o' 's' 'i' 't' 'i' 'v' 'e' 's' '_' 'u' 'p' 'w' 'a' 'r' 'd' 's' '_' 'c' 'b'.
		q(nt(211), (t(52)+t(30)+t(44)+t(22)+t(56)+t(23)+t(43)+t(21)+t(52)+t(21)+t(51)+t(32)+t(43)+t(22)+t(44)+t(56)+t(48)+t(30)+t(45)+t(53)+t(43)+t(22)+t(47)+t(34)));
		// _Rinputs_35 => _ input.
		q(nt(214), (nt(15)+nt(213)));
		// _Rinputs_36 => null.
		q(nt(215), (nul));
		// _Rinputs_36 => _Rinputs_35 _Rinputs_36.
		q(nt(215), (nt(214)+nt(215)));
		// inputs => _ less _ input _Rinputs_36 _ dot.
		q(nt(212), (nt(15)+nt(30)+nt(15)+nt(213)+nt(215)+nt(15)+nt(20)));
		// input => in _ colon _ open_brace _ source_binding _ close_brace.
		q(nt(213), (nt(53)+nt(15)+nt(28)+nt(15)+nt(25)+nt(15)+nt(182)+nt(15)+nt(26)));
		// builder => _ builder_head _ builder_body _ dot.
		q(nt(216), (nt(15)+nt(217)+nt(15)+nt(218)+nt(15)+nt(20)));
		// _Rbuilder_head_37 => __ capture.
		q(nt(219), (nt(13)+nt(45)));
		// _Rbuilder_head_38 => null.
		q(nt(220), (nul));
		// _Rbuilder_head_38 => _Rbuilder_head_37 _Rbuilder_head_38.
		q(nt(220), (nt(219)+nt(220)));
		// builder_head => open_parenthesis _ capture _Rbuilder_head_38 _ close_parenthesis.
		q(nt(217), (nt(21)+nt(15)+nt(45)+nt(220)+nt(15)+nt(22)));
		// builder_body => bf_builder_body.
		q(nt(218), (nt(221)));
		// builder_body => wff_builder_body.
		q(nt(218), (nt(222)));
		// builder_body => tau_builder_body.
		q(nt(218), (nt(223)));
		// bf_builder_body => bf_def _ bf.
		q(nt(221), (nt(17)+nt(15)+nt(79)));
		// wff_builder_body => wff_def _ wff.
		q(nt(222), (nt(18)+nt(15)+nt(83)));
		// tau_builder_body => tau_def _ tau.
		q(nt(223), (nt(19)+nt(15)+nt(64)));
		// library => rules.
		q(nt(224), (nt(225)));
		// _Rrules_39 => _ rule.
		q(nt(227), (nt(15)+nt(226)));
		// _Rrules_40 => null.
		q(nt(228), (nul));
		// _Rrules_40 => _Rrules_39 _Rrules_40.
		q(nt(228), (nt(227)+nt(228)));
		// rules => _Rrules_40.
		q(nt(225), (nt(228)));
		// rule => tau_rule.
		q(nt(226), (nt(61)));
		// rule => wff_rule.
		q(nt(226), (nt(84)));
		// rule => bf_rule.
		q(nt(226), (nt(141)));
		// nso_rr => nso_rec_relations nso_main.
		q(nt(229), (nt(230)+nt(231)));
		// _Rnso_rec_relations_41 => _ nso_rec_relation.
		q(nt(233), (nt(15)+nt(232)));
		// _Rnso_rec_relations_42 => null.
		q(nt(234), (nul));
		// _Rnso_rec_relations_42 => _Rnso_rec_relations_41 _Rnso_rec_relations_42.
		q(nt(234), (nt(233)+nt(234)));
		// nso_rec_relations => _Rnso_rec_relations_42.
		q(nt(230), (nt(234)));
		// nso_rec_relation => wff_rec_relation.
		q(nt(232), (nt(94)));
		// nso_rec_relation => bf_rec_relation.
		q(nt(232), (nt(164)));
		// nso_main => _ wff _ dot.
		q(nt(231), (nt(15)+nt(83)+nt(15)+nt(20)));
		// gssotc_rr => gssotc_rec_relations gssotc_main.
		q(nt(235), (nt(236)+nt(237)));
		// _Rgssotc_rec_relations_43 => _ gssotc_rec_relation.
		q(nt(239), (nt(15)+nt(238)));
		// _Rgssotc_rec_relations_44 => null.
		q(nt(240), (nul));
		// _Rgssotc_rec_relations_44 => _Rgssotc_rec_relations_43 _Rgssotc_rec_relations_44.
		q(nt(240), (nt(239)+nt(240)));
		// gssotc_rec_relations => _Rgssotc_rec_relations_44.
		q(nt(236), (nt(240)));
		// gssotc_rec_relation => tau_rec_relation.
		q(nt(238), (nt(67)));
		// gssotc_rec_relation => wff_rec_relation.
		q(nt(238), (nt(94)));
		// gssotc_rec_relation => bf_rec_relation.
		q(nt(238), (nt(164)));
		// gssotc_main => _ tau _ semicolon.
		q(nt(237), (nt(15)+nt(64)+nt(15)+nt(29)));
		// _Rstart_45 => inputs.
		q(nt(242), (nt(212)));
		// _Rstart_45 => builder.
		q(nt(242), (nt(216)));
		// _Rstart_45 => library.
		q(nt(242), (nt(224)));
		// _Rstart_45 => nso_rr.
		q(nt(242), (nt(229)));
		// _Rstart_45 => gssotc_rr.
		q(nt(242), (nt(235)));
		// start => _Rstart_45 _.
		q(nt(241), (nt(242)+nt(15)));
		// file => file_sym quote file_path quote.
		q(nt(243), (nt(244)+nt(33)+nt(245)+nt(33)));
		// _Rcli_46 => _ dot _ cli_command.
		q(nt(248), (nt(15)+nt(20)+nt(15)+nt(247)));
		// _Rcli_47 => null.
		q(nt(249), (nul));
		// _Rcli_47 => _Rcli_46 _Rcli_47.
		q(nt(249), (nt(248)+nt(249)));
		// _Rcli_48 => null.
		q(nt(250), (nul));
		// _Rcli_48 => _ dot.
		q(nt(250), (nt(15)+nt(20)));
		// cli => _ cli_command _Rcli_47 _Rcli_48 _.
		q(nt(246), (nt(15)+nt(247)+nt(249)+nt(250)+nt(15)));
		// __neg_45 => help.
		q(nt(408), (nt(265)));
		// __neg_46 => version.
		q(nt(409), (nt(266)));
		// __neg_47 => quit.
		q(nt(410), (nt(267)));
		// __neg_48 => get.
		q(nt(411), (nt(268)));
		// __neg_49 => list_outputs.
		q(nt(412), (nt(269)));
		// _Rcli_command_49 => bf & ~( __neg_45 ) & ~( __neg_46 ) & ~( __neg_47 ) & ~( __neg_48 ) & ~( __neg_49 ).
		q(nt(270), (nt(79)) & ~(nt(408)) & ~(nt(409)) & ~(nt(410)) & ~(nt(411)) & ~(nt(412)));
		// cli_command => wff.
		q(nt(247), (nt(83)));
		// cli_command => wff_onf_cmd.
		q(nt(247), (nt(251)));
		// cli_command => wff_dnf_cmd.
		q(nt(247), (nt(252)));
		// cli_command => wff_cnf_cmd.
		q(nt(247), (nt(253)));
		// cli_command => wff_anf_cmd.
		q(nt(247), (nt(254)));
		// cli_command => wff_nnf_cmd.
		q(nt(247), (nt(255)));
		// cli_command => wff_pnf_cmd.
		q(nt(247), (nt(256)));
		// cli_command => wff_mnf_cmd.
		q(nt(247), (nt(257)));
		// cli_command => bf_dnf_cmd.
		q(nt(247), (nt(258)));
		// cli_command => bf_cnf_cmd.
		q(nt(247), (nt(259)));
		// cli_command => bf_anf_cmd.
		q(nt(247), (nt(260)));
		// cli_command => bf_nnf_cmd.
		q(nt(247), (nt(261)));
		// cli_command => bf_pnf_cmd.
		q(nt(247), (nt(262)));
		// cli_command => bf_mnf_cmd.
		q(nt(247), (nt(263)));
		// cli_command => rr_nso.
		q(nt(247), (nt(264)));
		// cli_command => _Rcli_command_49.
		q(nt(247), (nt(270)));
		// cli_command => wff_substitute_cmd.
		q(nt(247), (nt(271)));
		// cli_command => wff_instantiate_cmd.
		q(nt(247), (nt(272)));
		// cli_command => bf_substitute_cmd.
		q(nt(247), (nt(273)));
		// cli_command => bf_instantiate_cmd.
		q(nt(247), (nt(274)));
		// cli_command => normalize_cmd.
		q(nt(247), (nt(275)));
		// cli_command => list_outputs_cmd.
		q(nt(247), (nt(276)));
		// cli_command => clear_outputs_cmd.
		q(nt(247), (nt(277)));
		// cli_command => print_output_cmd.
		q(nt(247), (nt(278)));
		// cli_command => file_cmd.
		q(nt(247), (nt(279)));
		// cli_command => toggle_cmd.
		q(nt(247), (nt(280)));
		// cli_command => set_cmd.
		q(nt(247), (nt(281)));
		// cli_command => get_cmd.
		q(nt(247), (nt(282)));
		// cli_command => help_cmd.
		q(nt(247), (nt(283)));
		// cli_command => version_cmd.
		q(nt(247), (nt(284)));
		// cli_command => quit_cmd.
		q(nt(247), (nt(285)));
		// _Rnormalize_cmd_50 => wff.
		q(nt(289), (nt(83)));
		// _Rnormalize_cmd_50 => nso_rr.
		q(nt(289), (nt(229)));
		// _Rnormalize_cmd_50 => output.
		q(nt(289), (nt(287)));
		// _Rnormalize_cmd_50 => wff_selection.
		q(nt(289), (nt(288)));
		// normalize_cmd => normalize_cmd_sym __ _Rnormalize_cmd_50.
		q(nt(275), (nt(286)+nt(13)+nt(289)));
		// _Rbf_instantiate_cmd_51 => bf.
		q(nt(292), (nt(79)));
		// _Rbf_instantiate_cmd_51 => output.
		q(nt(292), (nt(287)));
		// _Rbf_instantiate_cmd_51 => bf_selection.
		q(nt(292), (nt(291)));
		// _Rbf_instantiate_cmd_52 => output.
		q(nt(293), (nt(287)));
		// _Rbf_instantiate_cmd_52 => bf_selection.
		q(nt(293), (nt(291)));
		// bf_instantiate_cmd => instantiate_cmd_sym __ variable __ _Rbf_instantiate_cmd_51 __ _Rbf_instantiate_cmd_52.
		q(nt(274), (nt(290)+nt(13)+nt(47)+nt(13)+nt(292)+nt(13)+nt(293)));
		// _Rwff_instantiate_cmd_53 => wff.
		q(nt(294), (nt(83)));
		// _Rwff_instantiate_cmd_53 => output.
		q(nt(294), (nt(287)));
		// _Rwff_instantiate_cmd_53 => wff_selection.
		q(nt(294), (nt(288)));
		// _Rwff_instantiate_cmd_54 => output.
		q(nt(295), (nt(287)));
		// _Rwff_instantiate_cmd_54 => wff_selection.
		q(nt(295), (nt(288)));
		// wff_instantiate_cmd => instantiate_cmd_sym __ variable __ _Rwff_instantiate_cmd_53 __ _Rwff_instantiate_cmd_54.
		q(nt(272), (nt(290)+nt(13)+nt(47)+nt(13)+nt(294)+nt(13)+nt(295)));
		// _Rbf_substitute_cmd_55 => bf.
		q(nt(297), (nt(79)));
		// _Rbf_substitute_cmd_55 => output.
		q(nt(297), (nt(287)));
		// _Rbf_substitute_cmd_55 => bf_selection.
		q(nt(297), (nt(291)));
		// _Rbf_substitute_cmd_56 => output.
		q(nt(298), (nt(287)));
		// _Rbf_substitute_cmd_56 => bf_selection.
		q(nt(298), (nt(291)));
		// _Rbf_substitute_cmd_57 => output.
		q(nt(299), (nt(287)));
		// _Rbf_substitute_cmd_57 => bf_selection.
		q(nt(299), (nt(291)));
		// bf_substitute_cmd => substitute_cmd_sym __ _Rbf_substitute_cmd_55 __ _Rbf_substitute_cmd_56 _Rbf_substitute_cmd_57.
		q(nt(273), (nt(296)+nt(13)+nt(297)+nt(13)+nt(298)+nt(299)));
		// _Rwff_substitute_cmd_58 => wff.
		q(nt(301), (nt(83)));
		// _Rwff_substitute_cmd_58 => output.
		q(nt(301), (nt(287)));
		// _Rwff_substitute_cmd_58 => wff_selection.
		q(nt(301), (nt(288)));
		// _Rwff_substitute_cmd_59 => output.
		q(nt(302), (nt(287)));
		// _Rwff_substitute_cmd_59 => wff_selection.
		q(nt(302), (nt(288)));
		// _Rwff_substitute_cmd_60 => output.
		q(nt(303), (nt(287)));
		// _Rwff_substitute_cmd_60 => wff_selection.
		q(nt(303), (nt(288)));
		// wff_substitute_cmd => substitutecmd__sym __ _Rwff_substitute_cmd_58 __ _Rwff_substitute_cmd_59 _Rwff_substitute_cmd_60.
		q(nt(271), (nt(300)+nt(13)+nt(301)+nt(13)+nt(302)+nt(303)));
		// _Rbf_dnf_cmd_61 => bf.
		q(nt(305), (nt(79)));
		// _Rbf_dnf_cmd_61 => output.
		q(nt(305), (nt(287)));
		// _Rbf_dnf_cmd_61 => bf_selection.
		q(nt(305), (nt(291)));
		// bf_dnf_cmd => dnf_cmd_sym __ _Rbf_dnf_cmd_61.
		q(nt(258), (nt(304)+nt(13)+nt(305)));
		// _Rbf_cnf_cmd_62 => bf.
		q(nt(307), (nt(79)));
		// _Rbf_cnf_cmd_62 => output.
		q(nt(307), (nt(287)));
		// _Rbf_cnf_cmd_62 => bf_selection.
		q(nt(307), (nt(291)));
		// bf_cnf_cmd => cnf_cmd_sym __ _Rbf_cnf_cmd_62.
		q(nt(259), (nt(306)+nt(13)+nt(307)));
		// _Rbf_anf_cmd_63 => bf.
		q(nt(309), (nt(79)));
		// _Rbf_anf_cmd_63 => output.
		q(nt(309), (nt(287)));
		// _Rbf_anf_cmd_63 => bf_selection.
		q(nt(309), (nt(291)));
		// bf_anf_cmd => anf_cmd_sym __ _Rbf_anf_cmd_63.
		q(nt(260), (nt(308)+nt(13)+nt(309)));
		// _Rbf_nnf_cmd_64 => bf.
		q(nt(311), (nt(79)));
		// _Rbf_nnf_cmd_64 => output.
		q(nt(311), (nt(287)));
		// _Rbf_nnf_cmd_64 => bf_selection.
		q(nt(311), (nt(291)));
		// bf_nnf_cmd => nnf_cmd_sym __ _Rbf_nnf_cmd_64.
		q(nt(261), (nt(310)+nt(13)+nt(311)));
		// _Rbf_pnf_cmd_65 => bf.
		q(nt(313), (nt(79)));
		// _Rbf_pnf_cmd_65 => output.
		q(nt(313), (nt(287)));
		// _Rbf_pnf_cmd_65 => bf_selection.
		q(nt(313), (nt(291)));
		// bf_pnf_cmd => pnf_cmd_sym __ _Rbf_pnf_cmd_65.
		q(nt(262), (nt(312)+nt(13)+nt(313)));
		// _Rbf_mnf_cmd_66 => bf.
		q(nt(315), (nt(79)));
		// _Rbf_mnf_cmd_66 => output.
		q(nt(315), (nt(287)));
		// _Rbf_mnf_cmd_66 => bf_selection.
		q(nt(315), (nt(291)));
		// bf_mnf_cmd => mnf_cmd_sym __ _Rbf_mnf_cmd_66.
		q(nt(263), (nt(314)+nt(13)+nt(315)));
		// _Rwff_onf_cmd_67 => wff.
		q(nt(317), (nt(83)));
		// _Rwff_onf_cmd_67 => output.
		q(nt(317), (nt(287)));
		// _Rwff_onf_cmd_67 => wff_selection.
		q(nt(317), (nt(288)));
		// wff_onf_cmd => onf_cmd_sym __ variable _Rwff_onf_cmd_67.
		q(nt(251), (nt(316)+nt(13)+nt(47)+nt(317)));
		// _Rwff_dnf_cmd_68 => wff.
		q(nt(318), (nt(83)));
		// _Rwff_dnf_cmd_68 => output.
		q(nt(318), (nt(287)));
		// _Rwff_dnf_cmd_68 => wff_selection.
		q(nt(318), (nt(288)));
		// wff_dnf_cmd => dnf_cmd_sym __ _Rwff_dnf_cmd_68.
		q(nt(252), (nt(304)+nt(13)+nt(318)));
		// _Rwff_cnf_cmd_69 => wff.
		q(nt(319), (nt(83)));
		// _Rwff_cnf_cmd_69 => output.
		q(nt(319), (nt(287)));
		// _Rwff_cnf_cmd_69 => wff_selection.
		q(nt(319), (nt(288)));
		// wff_cnf_cmd => cnf_cmd_sym __ _Rwff_cnf_cmd_69.
		q(nt(253), (nt(306)+nt(13)+nt(319)));
		// _Rwff_anf_cmd_70 => wff.
		q(nt(320), (nt(83)));
		// _Rwff_anf_cmd_70 => output.
		q(nt(320), (nt(287)));
		// _Rwff_anf_cmd_70 => wff_selection.
		q(nt(320), (nt(288)));
		// wff_anf_cmd => anf_cmd_sym __ _Rwff_anf_cmd_70.
		q(nt(254), (nt(308)+nt(13)+nt(320)));
		// _Rwff_nnf_cmd_71 => wff.
		q(nt(321), (nt(83)));
		// _Rwff_nnf_cmd_71 => output.
		q(nt(321), (nt(287)));
		// _Rwff_nnf_cmd_71 => wff_selection.
		q(nt(321), (nt(288)));
		// wff_nnf_cmd => nnf_cmd_sym __ _Rwff_nnf_cmd_71.
		q(nt(255), (nt(310)+nt(13)+nt(321)));
		// _Rwff_pnf_cmd_72 => wff.
		q(nt(322), (nt(83)));
		// _Rwff_pnf_cmd_72 => output.
		q(nt(322), (nt(287)));
		// _Rwff_pnf_cmd_72 => wff_selection.
		q(nt(322), (nt(288)));
		// wff_pnf_cmd => pnf_cmd_sym __ _Rwff_pnf_cmd_72.
		q(nt(256), (nt(312)+nt(13)+nt(322)));
		// _Rwff_mnf_cmd_73 => wff.
		q(nt(323), (nt(83)));
		// _Rwff_mnf_cmd_73 => output.
		q(nt(323), (nt(287)));
		// _Rwff_mnf_cmd_73 => wff_selection.
		q(nt(323), (nt(288)));
		// wff_mnf_cmd => mnf_cmd_sym __ _Rwff_mnf_cmd_73.
		q(nt(257), (nt(314)+nt(13)+nt(323)));
		// _Rhelp_cmd_74 => null.
		q(nt(326), (nul));
		// _Rhelp_cmd_74 => __ cli_cmd_sym.
		q(nt(326), (nt(13)+nt(325)));
		// help_cmd => help_cmd_sym _Rhelp_cmd_74.
		q(nt(283), (nt(324)+nt(326)));
		// version_cmd => version_cmd_sym.
		q(nt(284), (nt(327)));
		// quit_cmd => quit_cmd_sym.
		q(nt(285), (nt(328)));
		// wff_selection => selection_sym __ digits.
		q(nt(288), (nt(329)+nt(13)+nt(37)));
		// bf_selection => selection_sym __ digits.
		q(nt(291), (nt(329)+nt(13)+nt(37)));
		// bf_var_selection => selection_sym __ digits.
		q(nt(330), (nt(329)+nt(13)+nt(37)));
		// wff_var_selection => selection_sym __ digits.
		q(nt(331), (nt(329)+nt(13)+nt(37)));
		// file_path => chars.
		q(nt(245), (nt(34)));
		// output => absolute_output.
		q(nt(287), (nt(332)));
		// output => relative_output.
		q(nt(287), (nt(333)));
		// _Rabsolute_output_75 => absolute_output_sym.
		q(nt(336), (nt(334)));
		// _Rabsolute_output_75 => output_sym __.
		q(nt(336), (nt(335)+nt(13)));
		// absolute_output => _Rabsolute_output_75 output_id.
		q(nt(332), (nt(336)+nt(337)));
		// relative_output => relative_output_sym output_id.
		q(nt(333), (nt(338)+nt(337)));
		// output_id => digits.
		q(nt(337), (nt(37)));
		// list_outputs_cmd => absolute_output_sym.
		q(nt(276), (nt(334)));
		// list_outputs_cmd => output_sym.
		q(nt(276), (nt(335)));
		// list_outputs_cmd => relative_output_sym.
		q(nt(276), (nt(338)));
		// _Rclear_outputs_cmd_76 => absolute_output_sym.
		q(nt(339), (nt(334)));
		// _Rclear_outputs_cmd_76 => output_sym __.
		q(nt(339), (nt(335)+nt(13)));
		// _Rclear_outputs_cmd_76 => relative_output_sym.
		q(nt(339), (nt(338)));
		// clear_outputs_cmd => _Rclear_outputs_cmd_76 clear_sym.
		q(nt(277), (nt(339)+nt(340)));
		// print_output_cmd => output.
		q(nt(278), (nt(287)));
		// cli_cmd_sym => normalize_cmd_sym.
		q(nt(325), (nt(286)));
		// cli_cmd_sym => instantiate_cmd_sym.
		q(nt(325), (nt(290)));
		// cli_cmd_sym => substitute_cmd_sym.
		q(nt(325), (nt(296)));
		// cli_cmd_sym => help_cmd_sym.
		q(nt(325), (nt(324)));
		// cli_cmd_sym => version_cmd_sym.
		q(nt(325), (nt(327)));
		// cli_cmd_sym => quit_cmd_sym.
		q(nt(325), (nt(328)));
		// cli_cmd_sym => selection_sym.
		q(nt(325), (nt(329)));
		// cli_cmd_sym => absolute_output_sym.
		q(nt(325), (nt(334)));
		// cli_cmd_sym => output_sym.
		q(nt(325), (nt(335)));
		// cli_cmd_sym => relative_output_sym.
		q(nt(325), (nt(338)));
		// cli_cmd_sym => file_cmd_sym.
		q(nt(325), (nt(341)));
		// cli_cmd_sym => get_cmd_sym.
		q(nt(325), (nt(342)));
		// cli_cmd_sym => set_cmd_sym.
		q(nt(325), (nt(343)));
		// cli_cmd_sym => toggle_cmd_sym.
		q(nt(325), (nt(344)));
		// help_cmd_sym => 'h'.
		q(nt(324), (t(42)));
		// help_cmd_sym => 'h' 'e' 'l' 'p'.
		q(nt(324), (t(42)+t(32)+t(31)+t(56)));
		// version_cmd_sym => 'v'.
		q(nt(327), (t(51)));
		// version_cmd_sym => 'v' 'e' 'r' 's' 'i' 'o' 'n'.
		q(nt(327), (t(51)+t(32)+t(45)+t(43)+t(21)+t(23)+t(49)));
		// quit_cmd_sym => 'e'.
		q(nt(328), (t(32)));
		// quit_cmd_sym => 'e' 'x' 'i' 't'.
		q(nt(328), (t(32)+t(33)+t(21)+t(52)));
		// quit_cmd_sym => 'q'.
		q(nt(328), (t(54)));
		// quit_cmd_sym => 'q' 'u' 'i' 't'.
		q(nt(328), (t(54)+t(44)+t(21)+t(52)));
		// instantiate_sym => 'i'.
		q(nt(345), (t(21)));
		// instantiate_sym => 'i' 'n' 's' 't' 'a' 'n' 't' 'i' 'a' 't' 'e'.
		q(nt(345), (t(21)+t(49)+t(43)+t(52)+t(30)+t(49)+t(52)+t(21)+t(30)+t(52)+t(32)));
		// substitute_sym => 's'.
		q(nt(346), (t(43)));
		// substitute_sym => 's' 'u' 'b' 's' 't' 'i' 't' 'u' 't' 'e'.
		q(nt(346), (t(43)+t(44)+t(34)+t(43)+t(52)+t(21)+t(52)+t(44)+t(52)+t(32)));
		// normalize_cmd_sym => 'n'.
		q(nt(286), (t(49)));
		// normalize_cmd_sym => 'n' 'o' 'r' 'm' 'a' 'l' 'i' 'z' 'e'.
		q(nt(286), (t(49)+t(23)+t(45)+t(46)+t(30)+t(31)+t(21)+t(55)+t(32)));
		// file_cmd_sym => 'r'.
		q(nt(341), (t(45)));
		// file_cmd_sym => 'r' 'e' 'a' 'd'.
		q(nt(341), (t(45)+t(32)+t(30)+t(53)));
		// clear_cmd_sym => 'c'.
		q(nt(347), (t(47)));
		// clear_cmd_sym => 'c' 'l' 'e' 'a' 'r'.
		q(nt(347), (t(47)+t(31)+t(32)+t(30)+t(45)));
		// onf_cmd_sym => 'o' 'n' 'f'.
		q(nt(316), (t(23)+t(49)+t(38)));
		// dnf_cmd_sym => 'd' 'n' 'f'.
		q(nt(304), (t(53)+t(49)+t(38)));
		// cnf_cmd_sym => 'c' 'n' 'f'.
		q(nt(306), (t(47)+t(49)+t(38)));
		// anf_cmd_sym => 'a' 'n' 'f'.
		q(nt(308), (t(30)+t(49)+t(38)));
		// nnf_cmd_sym => 'n' 'n' 'f'.
		q(nt(310), (t(49)+t(49)+t(38)));
		// pnf_cmd_sym => 'p' 'n' 'f'.
		q(nt(312), (t(56)+t(49)+t(38)));
		// mnf_cmd_sym => 'm' 'n' 'f'.
		q(nt(314), (t(46)+t(49)+t(38)));
		// selection_sym => 's'.
		q(nt(329), (t(43)));
		// selection_sym => 's' 'e' 'l' 'e' 'c' 't' 'i' 'o' 'n'.
		q(nt(329), (t(43)+t(32)+t(31)+t(32)+t(47)+t(52)+t(21)+t(23)+t(49)));
		// output_sym => 'o'.
		q(nt(335), (t(23)));
		// output_sym => 'o' 'u' 't' 'p' 'u' 't'.
		q(nt(335), (t(23)+t(44)+t(52)+t(56)+t(44)+t(52)));
		// absolute_output_sym => '&'.
		q(nt(334), (t(24)));
		// relative_output_sym => '%'.
		q(nt(338), (t(57)));
		// _Rget_cmd_77 => null.
		q(nt(349), (nul));
		// _Rget_cmd_77 => __ option.
		q(nt(349), (nt(13)+nt(348)));
		// get_cmd => get_cmd_sym _Rget_cmd_77.
		q(nt(282), (nt(342)+nt(349)));
		// _Rset_cmd_78 => __.
		q(nt(350), (nt(13)));
		// _Rset_cmd_78 => _ '=' _.
		q(nt(350), (nt(15)+t(6)+nt(15)));
		// set_cmd => set_cmd_sym __ option _Rset_cmd_78 option_value.
		q(nt(281), (nt(343)+nt(13)+nt(348)+nt(350)+nt(351)));
		// toggle_cmd => toggle_cmd_sym __ bool_option.
		q(nt(280), (nt(344)+nt(13)+nt(352)));
		// get_cmd_sym => 'g' 'e' 't'.
		q(nt(342), (t(50)+t(32)+t(52)));
		// set_cmd_sym => 's' 'e' 't'.
		q(nt(343), (t(43)+t(32)+t(52)));
		// toggle_cmd_sym => 't' 'o' 'g' 'g' 'l' 'e'.
		q(nt(344), (t(52)+t(23)+t(50)+t(50)+t(31)+t(32)));
		// option => bool_option.
		q(nt(348), (nt(352)));
		// option => severity_opt.
		q(nt(348), (nt(353)));
		// bool_option => status_opt.
		q(nt(352), (nt(354)));
		// bool_option => colors_opt.
		q(nt(352), (nt(355)));
		// status_opt => 's'.
		q(nt(354), (t(43)));
		// status_opt => 's' 't' 'a' 't' 'u' 's'.
		q(nt(354), (t(43)+t(52)+t(30)+t(52)+t(44)+t(43)));
		// colors_opt => 'c'.
		q(nt(355), (t(47)));
		// colors_opt => 'c' 'o' 'l' 'o' 'r'.
		q(nt(355), (t(47)+t(23)+t(31)+t(23)+t(45)));
		// colors_opt => 'c' 'o' 'l' 'o' 'r' 's'.
		q(nt(355), (t(47)+t(23)+t(31)+t(23)+t(45)+t(43)));
		// severity_opt => 's' 'e' 'v'.
		q(nt(353), (t(43)+t(32)+t(51)));
		// severity_opt => 's' 'e' 'v' 'e' 'r' 'i' 't' 'y'.
		q(nt(353), (t(43)+t(32)+t(51)+t(32)+t(45)+t(21)+t(52)+t(58)));
		// option_value => option_value_true.
		q(nt(351), (nt(356)));
		// option_value => option_value_false.
		q(nt(351), (nt(357)));
		// option_value => severity.
		q(nt(351), (nt(358)));
		// option_value_true => '1'.
		q(nt(356), (t(40)));
		// option_value_true => 'o' 'n'.
		q(nt(356), (t(23)+t(49)));
		// option_value_true => 't'.
		q(nt(356), (t(52)));
		// option_value_true => 't' 'r' 'u' 'e'.
		q(nt(356), (t(52)+t(45)+t(44)+t(32)));
		// option_value_true => 'y'.
		q(nt(356), (t(58)));
		// option_value_true => 'y' 'e' 's'.
		q(nt(356), (t(58)+t(32)+t(43)));
		// option_value_false => '0'.
		q(nt(357), (t(41)));
		// option_value_false => 'f'.
		q(nt(357), (t(38)));
		// option_value_false => 'f' 'a' 'l' 's' 'e'.
		q(nt(357), (t(38)+t(30)+t(31)+t(43)+t(32)));
		// option_value_false => 'n'.
		q(nt(357), (t(49)));
		// option_value_false => 'n' 'o'.
		q(nt(357), (t(49)+t(23)));
		// option_value_false => 'o' 'f' 'f'.
		q(nt(357), (t(23)+t(38)+t(38)));
		// severity => error_sym.
		q(nt(358), (nt(359)));
		// severity => debug_sym.
		q(nt(358), (nt(360)));
		// severity => trace_sym.
		q(nt(358), (nt(361)));
		// severity => info_sym.
		q(nt(358), (nt(362)));
		// error_sym => 'e'.
		q(nt(359), (t(32)));
		// error_sym => 'e' 'r' 'r' 'o' 'r'.
		q(nt(359), (t(32)+t(45)+t(45)+t(23)+t(45)));
		// info_sym => 'i'.
		q(nt(362), (t(21)));
		// info_sym => 'i' 'n' 'f' 'o'.
		q(nt(362), (t(21)+t(49)+t(38)+t(23)));
		// debug_sym => 'd'.
		q(nt(360), (t(53)));
		// debug_sym => 'd' 'e' 'b' 'u' 'g'.
		q(nt(360), (t(53)+t(32)+t(34)+t(44)+t(50)));
		// trace_sym => 't'.
		q(nt(361), (t(52)));
		// trace_sym => 't' 'r' 'a' 'c' 'e'.
		q(nt(361), (t(52)+t(45)+t(30)+t(47)+t(32)));
		return q;
	}
};
#endif // __TAU_PARSER_H__
