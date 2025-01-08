// This file is generated from a file parser/tau.tgf by
//       https://github.com/IDNI/parser/tools/tgf
//
#ifndef __TAU_PARSER_H__
#define __TAU_PARSER_H__

#include "parser.h"

namespace tau_parser_data {

using char_type     = char;
using terminal_type = char;

inline std::vector<std::string> symbol_names{
	"", "eof", "space", "digit", "xdigit", "alpha", "alnum", "punct", "printable", "start", 
	"rr", "_", "rec_relations", "main", "wff", "__E_rec_relations_0", "rec_relation", "__E_rec_relations_1", "ref", "__E_rec_relation_2", 
	"capture", "bf", "sym", "__E_ref_3", "offsets", "ref_args", "__E_ref_4", "__", "fp_fallback", "first_sym", 
	"last_sym", "__E_ref_args_5", "__E___E_ref_args_5_6", "ref_arg", "__E___E_ref_args_5_7", "__E___E_ref_args_5_8", "library", "rules", "__E_library_9", "__E___E_library_9_10", 
	"rule", "__E___E___E_library_9_10_11", "wff_rule", "bf_rule", "__E___E_library_9_12", "wff_matcher", "wff_body", "__E_wff_rule_13", "bf_matcher", "bf_body", 
	"__E_bf_rule_14", "builder", "builder_head", "builder_body", "__E_builder_head_15", "__E_builder_head_16", "bf_builder_body", "__E_builder_body_17", "wff_builder_body", "__E_builder_body_18", 
	"tau_constant_source", "__E_tau_constant_source_19", "wff_parenthesis", "__E_wff_20", "wff_sometimes", "__E_wff_21", "__E___E_wff_21_22", "wff_always", "__E_wff_23", "__E___E_wff_23_24", 
	"wff_conditional", "__E_wff_25", "wff_all", "__E_wff_26", "q_vars", "wff_ex", "__E_wff_27", "wff_ref", "constraint", "wff_imply", 
	"__E_wff_28", "wff_equiv", "__E_wff_29", "wff_or", "__E_wff_30", "wff_xor", "__E_wff_31", "wff_and", "__E_wff_32", "wff_neg", 
	"__E_wff_33", "wff_t", "wff_f", "bf_interval", "__E_wff_34", "bf_eq", "__E_wff_35", "bf_neq", "__E_wff_36", "bf_less_equal", 
	"__E_wff_37", "bf_nleq", "__E_wff_38", "bf_greater", "__E_wff_39", "bf_ngreater", "__E_wff_40", "bf_greater_equal", "__E_wff_41", "bf_ngeq", 
	"__E_wff_42", "bf_less", "__E_wff_43", "bf_nless", "__E_wff_44", "bf_parenthesis", "__E_bf_45", "bf_constant", "variable", "bf_splitter", 
	"__E_bf_46", "bf_ref", "bf_or", "__E_bf_47", "bf_xor", "__E_bf_48", "bf_t", "__E_bf_49", "__E___E_bf_49_50", "type", 
	"bf_f", "__E_bf_51", "__E___E_bf_51_52", "bf_and", "__E_bf_53", "__E___E_bf_53_54", "__E_bf_55", "bf_and_nosep_1st_op", "__E___E_bf_55_56", "bf_neg", 
	"__E_bf_57", "ctn_neq", "__E_constraint_58", "ctnvar", "num", "ctn_eq", "__E_constraint_59", "ctn_greater_equal", "__E_constraint_60", "ctn_greater", 
	"__E_constraint_61", "ctn_less_equal", "__E_constraint_62", "ctn_less", "__E_constraint_63", "__E_variable_64", "__E_variable_65", "__E_variable_66", "__E_variable_67", "__E_variable_68", 
	"io_var", "__E_variable_69", "in", "out", "uninterpreted_constant", "in_var_name", "__E_in_70", "__E___E_in_70_71", "offset", "out_var_name", 
	"__E_out_72", "__E___E_out_72_73", "chars", "q_var", "__E_q_vars_74", "__E_q_vars_75", "__E_offsets_76", "__E_offsets_77", "shift", "__E_offset_78", 
	"__E_shift_79", "__E___E_shift_79_80", "digits", "uninter_const_name", "__E_uninterpreted_constant_81", "__E___E_uninterpreted_constant_81_82", "constant", "__E_bf_constant_83", "binding", "__E_bf_constant_84", 
	"source", "__E_binding_85", "src_c", "__E___E_binding_85_86", "__E___E___E_binding_85_86_87", "__E___E___E_binding_85_86_88", "__E_src_c_89", "__E_src_c_90", "__E_chars_91", "__E_chars_92", 
	"__E_digits_93", "comment", "__E_comment_94", "__E_comment_95", "__E_comment_96", "__E____97", "__E___98", "cli", "cli_command", "__E_cli_99", 
	"__E_cli_100", "quit_cmd", "quit_sym", "__E_cli_command_101", "version_cmd", "version_sym", "__E_cli_command_102", "clear_cmd", "clear_sym", "__E_cli_command_103", 
	"help_cmd", "__E_cli_command_104", "help_sym", "__E___E_cli_command_104_105", "__E___E_cli_command_104_106", "help_arg", "file_cmd", "__E_cli_command_107", "file_sym", "q_string", 
	"valid_cmd", "__E_cli_command_108", "valid_sym", "normalize_cmd_arg", "sat_cmd", "__E_cli_command_109", "sat_sym", "unsat_cmd", "__E_cli_command_110", "unsat_sym", 
	"solve_cmd", "__E_cli_command_111", "solve_sym", "__E___E_cli_command_111_112", "solve_cmd_arg", "run_cmd", "__E_cli_command_113", "run_sym", "__E___E_cli_command_113_114", "__E___E_cli_command_113_115", 
	"memory", "normalize_cmd", "__E_cli_command_116", "normalize_sym", "__E___E_cli_command_116_117", "subst_cmd", "__E_cli_command_118", "subst_sym", "__E___E_cli_command_118_119", "nf_cmd_arg", 
	"inst_cmd", "__E_cli_command_120", "inst_sym", "__E___E_cli_command_120_121", "inst_args", "dnf_cmd", "__E_cli_command_122", "dnf_sym", "cnf_cmd", "__E_cli_command_123", 
	"cnf_sym", "anf_cmd", "__E_cli_command_124", "anf_sym", "nnf_cmd", "__E_cli_command_125", "nnf_sym", "pnf_cmd", "__E_cli_command_126", "pnf_sym", 
	"mnf_cmd", "__E_cli_command_127", "mnf_sym", "snf_cmd", "__E_cli_command_128", "snf_sym", "onf_cmd", "__E_cli_command_129", "onf_sym", "onf_cmd_arg", 
	"def_list_cmd", "__E_cli_command_130", "def_sym", "__E___E_cli_command_130_131", "def_print_cmd", "__E_cli_command_132", "number", "def_rr_cmd", "qelim_cmd", "__E_cli_command_133", 
	"qelim_sym", "wff_cmd_arg", "get_cmd", "__E_cli_command_134", "get_sym", "__E___E_cli_command_134_135", "option_name", "set_cmd", "__E_cli_command_136", "set_sym", 
	"__E___E_cli_command_136_137", "option_value", "enable_cmd", "__E_cli_command_138", "enable_sym", "disable_cmd", "__E_cli_command_139", "disable_sym", "toggle_cmd", "__E_cli_command_140", 
	"toggle_sym", "def_input_cmd", "__E_cli_command_141", "input_stream", "def_output_cmd", "__E_cli_command_142", "output_stream", "history_list_cmd", "__E_cli_command_143", "history_sym", 
	"__E___E_cli_command_143_144", "history_print_cmd", "__E_cli_command_145", "history_store_cmd", "__E_cli_command_146", "__E_input_stream_147", "q_file_name", "console_sym", "__E_output_stream_148", "file_name", 
	"__E_file_name_149", "__E_option_name_150", "__E_option_value_151", "bf_cmd_arg", "abs_memory_sym", "rel_memory_sym", "selection_sym", "execute_sym", "examples_sym", "__E_help_arg_152", 
	"__E___E_help_arg_152_153", "rel_memory", "__E_memory_154", "__E___E_memory_154_155", "memory_id", "abs_memory", "__E_memory_156", "named_binding", "__N_0", "__N_1", 
	"__N_2", "__N_3", "__N_4", "__N_5", "__N_6", "__N_7", "__N_8", 
};

inline ::idni::nonterminals<char_type, terminal_type> nts{symbol_names};

inline std::vector<terminal_type> terminals{
	'\0', '.', ':', '=', 'f', 'a', 'l', 'b', 'c', 
	'k', 'i', 'r', 's', 't', ',', '(', ')', 'o', 'm', 
	'e', '<', '>', 'w', 'y', '[', ']', '?', 'x', '-', 
	'|', '^', '&', '!', 'T', 'F', 'S', '+', '1', '0', 
	'\'', '_', '$', '{', '}', '\t', '\n', '\r', '#', 'q', 
	'u', 'v', 'n', 'h', 'p', 'd', 'z', '/', 'g', '"', 
	'%', 
};

inline ::idni::char_class_fns<terminal_type> char_classes =
	::idni::predefined_char_classes<char_type, terminal_type>({
		"eof",
		"space",
		"digit",
		"xdigit",
		"alpha",
		"alnum",
		"punct",
		"printable",
	}, nts);

inline struct ::idni::grammar<char_type, terminal_type>::options
	grammar_options
{
	.transform_negation = false,
	.auto_disambiguate = true,
	.shaping = {
		.to_trim = {
			11, 27
		},
		.trim_terminals = true,
		.dont_trim_terminals_of = {
			20, 22, 118, 129, 143, 165, 169, 182, 183, 190,
			306, 311, 339, 357
		},
		.to_inline = {
			{ 14, 62, 14 },
			{ 21, 115, 21 },
			{ 137, 115, 21 },
			{ 172 },
			{ 173 },
			{ 192 },
			{ 233 },
			{ 244 },
			{ 259 },
			{ 264 },
			{ 289 },
			{ 301 },
			{ 343 }
		},
		.inline_char_classes = true
	},
	.enabled_guards = {
		"charvar"
	}
};

inline ::idni::parser<char_type, terminal_type>::options parser_options{
};

inline ::idni::prods<char_type, terminal_type> start_symbol{ nts(9) };

inline idni::prods<char_type, terminal_type>& productions() {
	static bool loaded = false;
	static idni::prods<char_type, terminal_type>
		p, nul(idni::lit<char_type, terminal_type>{});
	if (loaded) return p;
	#define  T(x) (idni::prods<char_type, terminal_type>{ terminals[x] })
	#define NT(x) (idni::prods<char_type, terminal_type>{ nts(x) })
//G0:   start(9)             => rr(10) _(11).
	p(NT(9), (NT(10)+NT(11)));
//G1:   main(13)             => wff(14).
	p(NT(13), (NT(14)));
//G2:   rr(10)               => rec_relations(12) _(11) main(13) _(11) '.'.
	p(NT(10), (NT(12)+NT(11)+NT(13)+NT(11)+T(1)));
//G3:   __E_rec_relations_0(15) => _(11) rec_relation(16) _(11) '.'.
	p(NT(15), (NT(11)+NT(16)+NT(11)+T(1)));
//G4:   __E_rec_relations_1(17) => null.
	p(NT(17), (nul));
//G5:   __E_rec_relations_1(17) => __E_rec_relations_0(15) __E_rec_relations_1(17).
	p(NT(17), (NT(15)+NT(17)));
//G6:   rec_relations(12)    => __E_rec_relations_1(17).
	p(NT(12), (NT(17)));
//G7:   __E_rec_relation_2(19) => capture(20).
	p(NT(19), (NT(20)));
//G8:   __E_rec_relation_2(19) => ref(18).
	p(NT(19), (NT(18)));
//G9:   __E_rec_relation_2(19) => wff(14).
	p(NT(19), (NT(14)));
//G10:  __E_rec_relation_2(19) => bf(21).
	p(NT(19), (NT(21)));
//G11:  rec_relation(16)     => ref(18) _(11) ':' '=' _(11) __E_rec_relation_2(19).
	p(NT(16), (NT(18)+NT(11)+T(2)+T(3)+NT(11)+NT(19)));
//G12:  __E_ref_3(23)        => _(11) offsets(24).
	p(NT(23), (NT(11)+NT(24)));
//G13:  __E_ref_3(23)        => null.
	p(NT(23), (nul));
//G14:  __E_ref_4(26)        => _(11) 'f' 'a' 'l' 'l' 'b' 'a' 'c' 'k' __(27) fp_fallback(28).
	p(NT(26), (NT(11)+T(4)+T(5)+T(6)+T(6)+T(7)+T(5)+T(8)+T(9)+NT(27)+NT(28)));
//G15:  __E_ref_4(26)        => null.
	p(NT(26), (nul));
//G16:  ref(18)              => sym(22) __E_ref_3(23) _(11) ref_args(25) __E_ref_4(26).
	p(NT(18), (NT(22)+NT(23)+NT(11)+NT(25)+NT(26)));
//G17:  first_sym(29)        => 'f' 'i' 'r' 's' 't'.
	p(NT(29), (T(4)+T(10)+T(11)+T(12)+T(13)));
//G18:  fp_fallback(28)      => first_sym(29).
	p(NT(28), (NT(29)));
//G19:  last_sym(30)         => 'l' 'a' 's' 't'.
	p(NT(30), (T(6)+T(5)+T(12)+T(13)));
//G20:  fp_fallback(28)      => last_sym(30).
	p(NT(28), (NT(30)));
//G21:  fp_fallback(28)      => capture(20).
	p(NT(28), (NT(20)));
//G22:  fp_fallback(28)      => ref(18).
	p(NT(28), (NT(18)));
//G23:  fp_fallback(28)      => wff(14).
	p(NT(28), (NT(14)));
//G24:  fp_fallback(28)      => bf(21).
	p(NT(28), (NT(21)));
//G25:  ref_arg(33)          => bf(21).
	p(NT(33), (NT(21)));
//G26:  __E___E_ref_args_5_6(32) => _(11) ref_arg(33).
	p(NT(32), (NT(11)+NT(33)));
//G27:  __E___E_ref_args_5_7(34) => _(11) ',' _(11) ref_arg(33).
	p(NT(34), (NT(11)+T(14)+NT(11)+NT(33)));
//G28:  __E___E_ref_args_5_8(35) => null.
	p(NT(35), (nul));
//G29:  __E___E_ref_args_5_8(35) => __E___E_ref_args_5_7(34) __E___E_ref_args_5_8(35).
	p(NT(35), (NT(34)+NT(35)));
//G30:  __E_ref_args_5(31)   => __E___E_ref_args_5_6(32) __E___E_ref_args_5_8(35).
	p(NT(31), (NT(32)+NT(35)));
//G31:  __E_ref_args_5(31)   => null.
	p(NT(31), (nul));
//G32:  ref_args(25)         => '(' __E_ref_args_5(31) _(11) ')'.
	p(NT(25), (T(15)+NT(31)+NT(11)+T(16)));
//G33:  __E___E___E_library_9_10_11(41) => wff_rule(42).
	p(NT(41), (NT(42)));
//G34:  __E___E___E_library_9_10_11(41) => bf_rule(43).
	p(NT(41), (NT(43)));
//G35:  rule(40)             => __E___E___E_library_9_10_11(41).
	p(NT(40), (NT(41)));
//G36:  __E___E_library_9_10(39) => _(11) rule(40).
	p(NT(39), (NT(11)+NT(40)));
//G37:  __E___E_library_9_12(44) => null.
	p(NT(44), (nul));
//G38:  __E___E_library_9_12(44) => __E___E_library_9_10(39) __E___E_library_9_12(44).
	p(NT(44), (NT(39)+NT(44)));
//G39:  __E_library_9(38)    => __E___E_library_9_12(44).
	p(NT(38), (NT(44)));
//G40:  rules(37)            => __E_library_9(38).
	p(NT(37), (NT(38)));
//G41:  library(36)          => rules(37).
	p(NT(36), (NT(37)));
//G42:  wff_matcher(45)      => wff(14).
	p(NT(45), (NT(14)));
//G43:  __E_wff_rule_13(47)  => wff(14).
	p(NT(47), (NT(14)));
//G44:  wff_body(46)         => __E_wff_rule_13(47).
	p(NT(46), (NT(47)));
//G45:  wff_rule(42)         => wff_matcher(45) _(11) ':' ':' '=' _(11) wff_body(46) _(11) '.'.
	p(NT(42), (NT(45)+NT(11)+T(2)+T(2)+T(3)+NT(11)+NT(46)+NT(11)+T(1)));
//G46:  bf_matcher(48)       => bf(21).
	p(NT(48), (NT(21)));
//G47:  __E_bf_rule_14(50)   => bf(21).
	p(NT(50), (NT(21)));
//G48:  bf_body(49)          => __E_bf_rule_14(50).
	p(NT(49), (NT(50)));
//G49:  bf_rule(43)          => bf_matcher(48) _(11) ':' '=' _(11) bf_body(49) _(11) '.'.
	p(NT(43), (NT(48)+NT(11)+T(2)+T(3)+NT(11)+NT(49)+NT(11)+T(1)));
//G50:  builder(51)          => _(11) builder_head(52) _(11) builder_body(53) _(11) '.'.
	p(NT(51), (NT(11)+NT(52)+NT(11)+NT(53)+NT(11)+T(1)));
//G51:  __E_builder_head_15(54) => __(27) capture(20).
	p(NT(54), (NT(27)+NT(20)));
//G52:  __E_builder_head_16(55) => null.
	p(NT(55), (nul));
//G53:  __E_builder_head_16(55) => __E_builder_head_15(54) __E_builder_head_16(55).
	p(NT(55), (NT(54)+NT(55)));
//G54:  builder_head(52)     => '(' _(11) capture(20) __E_builder_head_16(55) _(11) ')'.
	p(NT(52), (T(15)+NT(11)+NT(20)+NT(55)+NT(11)+T(16)));
//G55:  __E_builder_body_17(57) => '=' ':' _(11) bf(21).
	p(NT(57), (T(3)+T(2)+NT(11)+NT(21)));
//G56:  bf_builder_body(56)  => __E_builder_body_17(57).
	p(NT(56), (NT(57)));
//G57:  builder_body(53)     => bf_builder_body(56).
	p(NT(53), (NT(56)));
//G58:  __E_builder_body_18(59) => '=' ':' ':' _(11) wff(14).
	p(NT(59), (T(3)+T(2)+T(2)+NT(11)+NT(14)));
//G59:  wff_builder_body(58) => __E_builder_body_18(59).
	p(NT(58), (NT(59)));
//G60:  builder_body(53)     => wff_builder_body(58).
	p(NT(53), (NT(58)));
//G61:  __E_tau_constant_source_19(61) => '.' _(11).
	p(NT(61), (T(1)+NT(11)));
//G62:  __E_tau_constant_source_19(61) => null.
	p(NT(61), (nul));
//G63:  tau_constant_source(60) => rec_relations(12) _(11) main(13) _(11) __E_tau_constant_source_19(61).
	p(NT(60), (NT(12)+NT(11)+NT(13)+NT(11)+NT(61)));
//G64:  __E_wff_20(63)       => '(' _(11) wff(14) _(11) ')'.
	p(NT(63), (T(15)+NT(11)+NT(14)+NT(11)+T(16)));
//G65:  wff_parenthesis(62)  => __E_wff_20(63).
	p(NT(62), (NT(63)));
//G66:  wff(14)              => wff_parenthesis(62).
	p(NT(14), (NT(62)));
//G67:  __E___E_wff_21_22(66) => 's' 'o' 'm' 'e' 't' 'i' 'm' 'e' 's'.
	p(NT(66), (T(12)+T(17)+T(18)+T(19)+T(13)+T(10)+T(18)+T(19)+T(12)));
//G68:  __E___E_wff_21_22(66) => '<' '>'.
	p(NT(66), (T(20)+T(21)));
//G69:  __E_wff_21(65)       => __E___E_wff_21_22(66) _(11) wff(14).
	p(NT(65), (NT(66)+NT(11)+NT(14)));
//G70:  wff_sometimes(64)    => __E_wff_21(65).
	p(NT(64), (NT(65)));
//G71:  wff(14)              => wff_sometimes(64).
	p(NT(14), (NT(64)));
//G72:  __E___E_wff_23_24(69) => 'a' 'l' 'w' 'a' 'y' 's'.
	p(NT(69), (T(5)+T(6)+T(22)+T(5)+T(23)+T(12)));
//G73:  __E___E_wff_23_24(69) => '[' ']'.
	p(NT(69), (T(24)+T(25)));
//G74:  __E_wff_23(68)       => __E___E_wff_23_24(69) _(11) wff(14).
	p(NT(68), (NT(69)+NT(11)+NT(14)));
//G75:  wff_always(67)       => __E_wff_23(68).
	p(NT(67), (NT(68)));
//G76:  wff(14)              => wff_always(67).
	p(NT(14), (NT(67)));
//G77:  __E_wff_25(71)       => wff(14) _(11) '?' _(11) wff(14) _(11) ':' _(11) wff(14).
	p(NT(71), (NT(14)+NT(11)+T(26)+NT(11)+NT(14)+NT(11)+T(2)+NT(11)+NT(14)));
//G78:  wff_conditional(70)  => __E_wff_25(71).
	p(NT(70), (NT(71)));
//G79:  wff(14)              => wff_conditional(70).
	p(NT(14), (NT(70)));
//G80:  __E_wff_26(73)       => 'a' 'l' 'l' __(27) q_vars(74) __(27) wff(14).
	p(NT(73), (T(5)+T(6)+T(6)+NT(27)+NT(74)+NT(27)+NT(14)));
//G81:  wff_all(72)          => __E_wff_26(73).
	p(NT(72), (NT(73)));
//G82:  wff(14)              => wff_all(72).
	p(NT(14), (NT(72)));
//G83:  __E_wff_27(76)       => 'e' 'x' __(27) q_vars(74) __(27) wff(14).
	p(NT(76), (T(19)+T(27)+NT(27)+NT(74)+NT(27)+NT(14)));
//G84:  wff_ex(75)           => __E_wff_27(76).
	p(NT(75), (NT(76)));
//G85:  wff(14)              => wff_ex(75).
	p(NT(14), (NT(75)));
//G86:  wff_ref(77)          => ref(18).
	p(NT(77), (NT(18)));
//G87:  wff(14)              => wff_ref(77).
	p(NT(14), (NT(77)));
//G88:  wff(14)              => constraint(78).
	p(NT(14), (NT(78)));
//G89:  __E_wff_28(80)       => wff(14) _(11) '-' '>' _(11) wff(14).
	p(NT(80), (NT(14)+NT(11)+T(28)+T(21)+NT(11)+NT(14)));
//G90:  wff_imply(79)        => __E_wff_28(80).
	p(NT(79), (NT(80)));
//G91:  wff(14)              => wff_imply(79).
	p(NT(14), (NT(79)));
//G92:  __E_wff_29(82)       => wff(14) _(11) '<' '-' '>' _(11) wff(14).
	p(NT(82), (NT(14)+NT(11)+T(20)+T(28)+T(21)+NT(11)+NT(14)));
//G93:  wff_equiv(81)        => __E_wff_29(82).
	p(NT(81), (NT(82)));
//G94:  wff(14)              => wff_equiv(81).
	p(NT(14), (NT(81)));
//G95:  __E_wff_30(84)       => wff(14) _(11) '|' '|' _(11) wff(14).
	p(NT(84), (NT(14)+NT(11)+T(29)+T(29)+NT(11)+NT(14)));
//G96:  wff_or(83)           => __E_wff_30(84).
	p(NT(83), (NT(84)));
//G97:  wff(14)              => wff_or(83).
	p(NT(14), (NT(83)));
//G98:  __E_wff_31(86)       => wff(14) _(11) '^' _(11) wff(14).
	p(NT(86), (NT(14)+NT(11)+T(30)+NT(11)+NT(14)));
//G99:  wff_xor(85)          => __E_wff_31(86).
	p(NT(85), (NT(86)));
//G100: wff(14)              => wff_xor(85).
	p(NT(14), (NT(85)));
//G101: __E_wff_32(88)       => wff(14) _(11) '&' '&' _(11) wff(14).
	p(NT(88), (NT(14)+NT(11)+T(31)+T(31)+NT(11)+NT(14)));
//G102: wff_and(87)          => __E_wff_32(88).
	p(NT(87), (NT(88)));
//G103: wff(14)              => wff_and(87).
	p(NT(14), (NT(87)));
//G104: __E_wff_33(90)       => '!' _(11) wff(14).
	p(NT(90), (T(32)+NT(11)+NT(14)));
//G105: wff_neg(89)          => __E_wff_33(90).
	p(NT(89), (NT(90)));
//G106: wff(14)              => wff_neg(89).
	p(NT(14), (NT(89)));
//G107: wff_t(91)            => 'T'.
	p(NT(91), (T(33)));
//G108: wff(14)              => wff_t(91).
	p(NT(14), (NT(91)));
//G109: wff_f(92)            => 'F'.
	p(NT(92), (T(34)));
//G110: wff(14)              => wff_f(92).
	p(NT(14), (NT(92)));
//G111: __E_wff_34(94)       => bf(21) _(11) '<' '=' _(11) bf(21) _(11) '<' '=' _(11) bf(21).
	p(NT(94), (NT(21)+NT(11)+T(20)+T(3)+NT(11)+NT(21)+NT(11)+T(20)+T(3)+NT(11)+NT(21)));
//G112: bf_interval(93)      => __E_wff_34(94).
	p(NT(93), (NT(94)));
//G113: wff(14)              => bf_interval(93).
	p(NT(14), (NT(93)));
//G114: __E_wff_35(96)       => bf(21) _(11) '=' _(11) bf(21).
	p(NT(96), (NT(21)+NT(11)+T(3)+NT(11)+NT(21)));
//G115: bf_eq(95)            => __E_wff_35(96).
	p(NT(95), (NT(96)));
//G116: wff(14)              => bf_eq(95).
	p(NT(14), (NT(95)));
//G117: __E_wff_36(98)       => bf(21) _(11) '!' '=' _(11) bf(21).
	p(NT(98), (NT(21)+NT(11)+T(32)+T(3)+NT(11)+NT(21)));
//G118: bf_neq(97)           => __E_wff_36(98).
	p(NT(97), (NT(98)));
//G119: wff(14)              => bf_neq(97).
	p(NT(14), (NT(97)));
//G120: __E_wff_37(100)      => bf(21) _(11) '<' '=' _(11) bf(21).
	p(NT(100), (NT(21)+NT(11)+T(20)+T(3)+NT(11)+NT(21)));
//G121: bf_less_equal(99)    => __E_wff_37(100).
	p(NT(99), (NT(100)));
//G122: wff(14)              => bf_less_equal(99).
	p(NT(14), (NT(99)));
//G123: __E_wff_38(102)      => bf(21) _(11) '!' '<' '=' _(11) bf(21).
	p(NT(102), (NT(21)+NT(11)+T(32)+T(20)+T(3)+NT(11)+NT(21)));
//G124: bf_nleq(101)         => __E_wff_38(102).
	p(NT(101), (NT(102)));
//G125: wff(14)              => bf_nleq(101).
	p(NT(14), (NT(101)));
//G126: __E_wff_39(104)      => bf(21) _(11) '>' _(11) bf(21).
	p(NT(104), (NT(21)+NT(11)+T(21)+NT(11)+NT(21)));
//G127: bf_greater(103)      => __E_wff_39(104).
	p(NT(103), (NT(104)));
//G128: wff(14)              => bf_greater(103).
	p(NT(14), (NT(103)));
//G129: __E_wff_40(106)      => bf(21) _(11) '!' '>' _(11) bf(21).
	p(NT(106), (NT(21)+NT(11)+T(32)+T(21)+NT(11)+NT(21)));
//G130: bf_ngreater(105)     => __E_wff_40(106).
	p(NT(105), (NT(106)));
//G131: wff(14)              => bf_ngreater(105).
	p(NT(14), (NT(105)));
//G132: __E_wff_41(108)      => bf(21) _(11) '>' '=' _(11) bf(21).
	p(NT(108), (NT(21)+NT(11)+T(21)+T(3)+NT(11)+NT(21)));
//G133: bf_greater_equal(107) => __E_wff_41(108).
	p(NT(107), (NT(108)));
//G134: wff(14)              => bf_greater_equal(107).
	p(NT(14), (NT(107)));
//G135: __E_wff_42(110)      => bf(21) _(11) '!' '>' '=' _(11) bf(21).
	p(NT(110), (NT(21)+NT(11)+T(32)+T(21)+T(3)+NT(11)+NT(21)));
//G136: bf_ngeq(109)         => __E_wff_42(110).
	p(NT(109), (NT(110)));
//G137: wff(14)              => bf_ngeq(109).
	p(NT(14), (NT(109)));
//G138: __E_wff_43(112)      => bf(21) _(11) '<' _(11) bf(21).
	p(NT(112), (NT(21)+NT(11)+T(20)+NT(11)+NT(21)));
//G139: bf_less(111)         => __E_wff_43(112).
	p(NT(111), (NT(112)));
//G140: wff(14)              => bf_less(111).
	p(NT(14), (NT(111)));
//G141: __E_wff_44(114)      => bf(21) _(11) '!' '<' _(11) bf(21).
	p(NT(114), (NT(21)+NT(11)+T(32)+T(20)+NT(11)+NT(21)));
//G142: bf_nless(113)        => __E_wff_44(114).
	p(NT(113), (NT(114)));
//G143: wff(14)              => bf_nless(113).
	p(NT(14), (NT(113)));
//G144: wff(14)              => capture(20).
	p(NT(14), (NT(20)));
//G145: __E_bf_45(116)       => '(' _(11) bf(21) _(11) ')'.
	p(NT(116), (T(15)+NT(11)+NT(21)+NT(11)+T(16)));
//G146: bf_parenthesis(115)  => __E_bf_45(116).
	p(NT(115), (NT(116)));
//G147: bf(21)               => bf_parenthesis(115).
	p(NT(21), (NT(115)));
//G148: bf(21)               => bf_constant(117).
	p(NT(21), (NT(117)));
//G149: bf(21)               => variable(118).
	p(NT(21), (NT(118)));
//G150: __E_bf_46(120)       => 'S' _(11) '(' _(11) bf(21) _(11) ')'.
	p(NT(120), (T(35)+NT(11)+T(15)+NT(11)+NT(21)+NT(11)+T(16)));
//G151: bf_splitter(119)     => __E_bf_46(120).
	p(NT(119), (NT(120)));
//G152: bf(21)               => bf_splitter(119).
	p(NT(21), (NT(119)));
//G153: bf_ref(121)          => ref(18).
	p(NT(121), (NT(18)));
//G154: bf(21)               => bf_ref(121).
	p(NT(21), (NT(121)));
//G155: __E_bf_47(123)       => bf(21) _(11) '|' _(11) bf(21).
	p(NT(123), (NT(21)+NT(11)+T(29)+NT(11)+NT(21)));
//G156: bf_or(122)           => __E_bf_47(123).
	p(NT(122), (NT(123)));
//G157: bf(21)               => bf_or(122).
	p(NT(21), (NT(122)));
//G158: __E_bf_48(125)       => bf(21) _(11) '+' _(11) bf(21).
	p(NT(125), (NT(21)+NT(11)+T(36)+NT(11)+NT(21)));
//G159: bf_xor(124)          => __E_bf_48(125).
	p(NT(124), (NT(125)));
//G160: bf(21)               => bf_xor(124).
	p(NT(21), (NT(124)));
//G161: __E___E_bf_49_50(128) => _(11) ':' _(11) type(129).
	p(NT(128), (NT(11)+T(2)+NT(11)+NT(129)));
//G162: __E___E_bf_49_50(128) => null.
	p(NT(128), (nul));
//G163: __E_bf_49(127)       => '1' __E___E_bf_49_50(128).
	p(NT(127), (T(37)+NT(128)));
//G164: bf_t(126)            => __E_bf_49(127).
	p(NT(126), (NT(127)));
//G165: bf(21)               => bf_t(126).
	p(NT(21), (NT(126)));
//G166: __E___E_bf_51_52(132) => _(11) ':' _(11) type(129).
	p(NT(132), (NT(11)+T(2)+NT(11)+NT(129)));
//G167: __E___E_bf_51_52(132) => null.
	p(NT(132), (nul));
//G168: __E_bf_51(131)       => '0' __E___E_bf_51_52(132).
	p(NT(131), (T(38)+NT(132)));
//G169: bf_f(130)            => __E_bf_51(131).
	p(NT(130), (NT(131)));
//G170: bf(21)               => bf_f(130).
	p(NT(21), (NT(130)));
//G171: __E___E_bf_53_54(135) => _(11) '&' _(11).
	p(NT(135), (NT(11)+T(31)+NT(11)));
//G172: __E___E_bf_53_54(135) => __(27).
	p(NT(135), (NT(27)));
//G173: __E_bf_53(134)       => bf(21) __E___E_bf_53_54(135) bf(21).
	p(NT(134), (NT(21)+NT(135)+NT(21)));
//G174: bf_and(133)          => __E_bf_53(134).
	p(NT(133), (NT(134)));
//G175: bf(21)               => bf_and(133).
	p(NT(21), (NT(133)));
//G176: __E___E_bf_55_56(138) => bf_parenthesis(115).
	p(NT(138), (NT(115)));
//G177: __E___E_bf_55_56(138) => variable(118).
	p(NT(138), (NT(118)));
//G178: __E___E_bf_55_56(138) => bf_splitter(119).
	p(NT(138), (NT(119)));
//G179: __E___E_bf_55_56(138) => bf_ref(121).
	p(NT(138), (NT(121)));
//G180: __E___E_bf_55_56(138) => bf_or(122).
	p(NT(138), (NT(122)));
//G181: __E___E_bf_55_56(138) => bf_xor(124).
	p(NT(138), (NT(124)));
//G182: __E___E_bf_55_56(138) => bf_neg(139).
	p(NT(138), (NT(139)));
//G183: __E___E_bf_55_56(138) => capture(20).
	p(NT(138), (NT(20)));
//G184: bf_and_nosep_1st_op(137) => __E___E_bf_55_56(138).
	p(NT(137), (NT(138)));
//G185: __E_bf_55(136)       => bf_and_nosep_1st_op(137) bf(21).
	p(NT(136), (NT(137)+NT(21)));
//G186: bf_and(133)          => __E_bf_55(136).
	p(NT(133), (NT(136)));
//G187: bf(21)               => bf_and(133).
	p(NT(21), (NT(133)));
//G188: __E_bf_57(140)       => bf(21) _(11) '\''.
	p(NT(140), (NT(21)+NT(11)+T(39)));
//G189: bf_neg(139)          => __E_bf_57(140).
	p(NT(139), (NT(140)));
//G190: bf(21)               => bf_neg(139).
	p(NT(21), (NT(139)));
//G191: bf(21)               => capture(20).
	p(NT(21), (NT(20)));
//G192: __E_constraint_58(142) => '[' ctnvar(143) _(11) '!' '=' _(11) num(144) ']'.
	p(NT(142), (T(24)+NT(143)+NT(11)+T(32)+T(3)+NT(11)+NT(144)+T(25)));
//G193: __E_constraint_58(142) => '[' num(144) _(11) '!' '=' _(11) ctnvar(143) ']'.
	p(NT(142), (T(24)+NT(144)+NT(11)+T(32)+T(3)+NT(11)+NT(143)+T(25)));
//G194: ctn_neq(141)         => __E_constraint_58(142).
	p(NT(141), (NT(142)));
//G195: constraint(78)       => ctn_neq(141).
	p(NT(78), (NT(141)));
//G196: __E_constraint_59(146) => '[' ctnvar(143) _(11) '=' _(11) num(144) ']'.
	p(NT(146), (T(24)+NT(143)+NT(11)+T(3)+NT(11)+NT(144)+T(25)));
//G197: __E_constraint_59(146) => '[' num(144) _(11) '=' _(11) ctnvar(143) ']'.
	p(NT(146), (T(24)+NT(144)+NT(11)+T(3)+NT(11)+NT(143)+T(25)));
//G198: ctn_eq(145)          => __E_constraint_59(146).
	p(NT(145), (NT(146)));
//G199: constraint(78)       => ctn_eq(145).
	p(NT(78), (NT(145)));
//G200: __E_constraint_60(148) => '[' ctnvar(143) _(11) '>' '=' _(11) num(144) ']'.
	p(NT(148), (T(24)+NT(143)+NT(11)+T(21)+T(3)+NT(11)+NT(144)+T(25)));
//G201: __E_constraint_60(148) => '[' num(144) _(11) '>' '=' _(11) ctnvar(143) ']'.
	p(NT(148), (T(24)+NT(144)+NT(11)+T(21)+T(3)+NT(11)+NT(143)+T(25)));
//G202: ctn_greater_equal(147) => __E_constraint_60(148).
	p(NT(147), (NT(148)));
//G203: constraint(78)       => ctn_greater_equal(147).
	p(NT(78), (NT(147)));
//G204: __E_constraint_61(150) => '[' ctnvar(143) _(11) '>' _(11) num(144) ']'.
	p(NT(150), (T(24)+NT(143)+NT(11)+T(21)+NT(11)+NT(144)+T(25)));
//G205: __E_constraint_61(150) => '[' num(144) _(11) '>' _(11) ctnvar(143) ']'.
	p(NT(150), (T(24)+NT(144)+NT(11)+T(21)+NT(11)+NT(143)+T(25)));
//G206: ctn_greater(149)     => __E_constraint_61(150).
	p(NT(149), (NT(150)));
//G207: constraint(78)       => ctn_greater(149).
	p(NT(78), (NT(149)));
//G208: __E_constraint_62(152) => '[' ctnvar(143) _(11) '<' '=' _(11) num(144) ']'.
	p(NT(152), (T(24)+NT(143)+NT(11)+T(20)+T(3)+NT(11)+NT(144)+T(25)));
//G209: __E_constraint_62(152) => '[' num(144) _(11) '<' '=' _(11) ctnvar(143) ']'.
	p(NT(152), (T(24)+NT(144)+NT(11)+T(20)+T(3)+NT(11)+NT(143)+T(25)));
//G210: ctn_less_equal(151)  => __E_constraint_62(152).
	p(NT(151), (NT(152)));
//G211: constraint(78)       => ctn_less_equal(151).
	p(NT(78), (NT(151)));
//G212: __E_constraint_63(154) => '[' ctnvar(143) _(11) '<' _(11) num(144) ']'.
	p(NT(154), (T(24)+NT(143)+NT(11)+T(20)+NT(11)+NT(144)+T(25)));
//G213: __E_constraint_63(154) => '[' num(144) _(11) '<' _(11) ctnvar(143) ']'.
	p(NT(154), (T(24)+NT(144)+NT(11)+T(20)+NT(11)+NT(143)+T(25)));
//G214: ctn_less(153)        => __E_constraint_63(154).
	p(NT(153), (NT(154)));
//G215: constraint(78)       => ctn_less(153).
	p(NT(78), (NT(153)));
//G216: __N_0(358)           => 'F'.
	p(NT(358), (T(34)));
//G217: __N_1(359)           => 'T'.
	p(NT(359), (T(33)));
//G218: __E_variable_64(155) => ~( __N_0(358) ) & ~( __N_1(359) ) & alpha(5).	 # conjunctive
	p(NT(155), ~(NT(358)) & ~(NT(359)) & (NT(5)));
//G219: __E_variable_65(156) => null.
	p(NT(156), (nul));
//G220: __E_variable_65(156) => digit(3) __E_variable_65(156).
	p(NT(156), (NT(3)+NT(156)));
//G221: variable(118)        => __E_variable_64(155) __E_variable_65(156).	 # guarded: charvar
	p(NT(118), (NT(155)+NT(156)));
	p.back().guard = "charvar";
//G222: __N_2(360)           => 'F'.
	p(NT(360), (T(34)));
//G223: __N_3(361)           => 'T'.
	p(NT(361), (T(33)));
//G224: __E_variable_66(157) => ~( __N_2(360) ) & ~( __N_3(361) ) & alpha(5).	 # conjunctive
	p(NT(157), ~(NT(360)) & ~(NT(361)) & (NT(5)));
//G225: __E_variable_67(158) => alnum(6).
	p(NT(158), (NT(6)));
//G226: __E_variable_67(158) => '_'.
	p(NT(158), (T(40)));
//G227: __E_variable_68(159) => null.
	p(NT(159), (nul));
//G228: __E_variable_68(159) => __E_variable_67(158) __E_variable_68(159).
	p(NT(159), (NT(158)+NT(159)));
//G229: variable(118)        => __E_variable_66(157) __E_variable_68(159).	 # guarded: var
	p(NT(118), (NT(157)+NT(159)));
	p.back().guard = "var";
//G230: __E_variable_69(161) => in(162).
	p(NT(161), (NT(162)));
//G231: __E_variable_69(161) => out(163).
	p(NT(161), (NT(163)));
//G232: io_var(160)          => __E_variable_69(161).
	p(NT(160), (NT(161)));
//G233: variable(118)        => io_var(160).
	p(NT(118), (NT(160)));
//G234: variable(118)        => uninterpreted_constant(164).
	p(NT(118), (NT(164)));
//G235: __E___E_in_70_71(167) => digit(3).
	p(NT(167), (NT(3)));
//G236: __E___E_in_70_71(167) => digit(3) __E___E_in_70_71(167).
	p(NT(167), (NT(3)+NT(167)));
//G237: __E_in_70(166)       => 'i' __E___E_in_70_71(167).
	p(NT(166), (T(10)+NT(167)));
//G238: in_var_name(165)     => __E_in_70(166).
	p(NT(165), (NT(166)));
//G239: in(162)              => in_var_name(165) '[' offset(168) ']'.
	p(NT(162), (NT(165)+T(24)+NT(168)+T(25)));
//G240: __E___E_out_72_73(171) => digit(3).
	p(NT(171), (NT(3)));
//G241: __E___E_out_72_73(171) => digit(3) __E___E_out_72_73(171).
	p(NT(171), (NT(3)+NT(171)));
//G242: __E_out_72(170)      => 'o' __E___E_out_72_73(171).
	p(NT(170), (T(17)+NT(171)));
//G243: out_var_name(169)    => __E_out_72(170).
	p(NT(169), (NT(170)));
//G244: out(163)             => out_var_name(169) '[' offset(168) ']'.
	p(NT(163), (NT(169)+T(24)+NT(168)+T(25)));
//G245: ctnvar(143)          => chars(172).
	p(NT(143), (NT(172)));
//G246: capture(20)          => '$' chars(172).
	p(NT(20), (T(41)+NT(172)));
//G247: __E_q_vars_74(174)   => _(11) ',' _(11) q_var(173).
	p(NT(174), (NT(11)+T(14)+NT(11)+NT(173)));
//G248: __E_q_vars_75(175)   => null.
	p(NT(175), (nul));
//G249: __E_q_vars_75(175)   => __E_q_vars_74(174) __E_q_vars_75(175).
	p(NT(175), (NT(174)+NT(175)));
//G250: q_vars(74)           => q_var(173) __E_q_vars_75(175).
	p(NT(74), (NT(173)+NT(175)));
//G251: q_var(173)           => capture(20).
	p(NT(173), (NT(20)));
//G252: __N_4(362)           => uninterpreted_constant(164).
	p(NT(362), (NT(164)));
//G253: q_var(173)           => variable(118) & ~( __N_4(362) ).	 # conjunctive
	p(NT(173), (NT(118)) & ~(NT(362)));
//G254: __E_offsets_76(176)  => _(11) ',' _(11) offset(168).
	p(NT(176), (NT(11)+T(14)+NT(11)+NT(168)));
//G255: __E_offsets_77(177)  => null.
	p(NT(177), (nul));
//G256: __E_offsets_77(177)  => __E_offsets_76(176) __E_offsets_77(177).
	p(NT(177), (NT(176)+NT(177)));
//G257: offsets(24)          => '[' _(11) offset(168) __E_offsets_77(177) _(11) ']'.
	p(NT(24), (T(24)+NT(11)+NT(168)+NT(177)+NT(11)+T(25)));
//G258: offset(168)          => num(144).
	p(NT(168), (NT(144)));
//G259: offset(168)          => capture(20).
	p(NT(168), (NT(20)));
//G260: offset(168)          => shift(178).
	p(NT(168), (NT(178)));
//G261: __N_5(363)           => io_var(160).
	p(NT(363), (NT(160)));
//G262: __E_offset_78(179)   => variable(118) & ~( __N_5(363) ).	 # conjunctive
	p(NT(179), (NT(118)) & ~(NT(363)));
//G263: offset(168)          => __E_offset_78(179).
	p(NT(168), (NT(179)));
//G264: __E_shift_79(180)    => capture(20).
	p(NT(180), (NT(20)));
//G265: __N_6(364)           => io_var(160).
	p(NT(364), (NT(160)));
//G266: __E___E_shift_79_80(181) => variable(118) & ~( __N_6(364) ).	 # conjunctive
	p(NT(181), (NT(118)) & ~(NT(364)));
//G267: __E_shift_79(180)    => __E___E_shift_79_80(181).
	p(NT(180), (NT(181)));
//G268: shift(178)           => __E_shift_79(180) _(11) '-' _(11) num(144).
	p(NT(178), (NT(180)+NT(11)+T(28)+NT(11)+NT(144)));
//G269: num(144)             => digits(182).
	p(NT(144), (NT(182)));
//G270: __E___E_uninterpreted_constant_81_82(185) => chars(172).
	p(NT(185), (NT(172)));
//G271: __E___E_uninterpreted_constant_81_82(185) => _(11).
	p(NT(185), (NT(11)));
//G272: __E_uninterpreted_constant_81(184) => __E___E_uninterpreted_constant_81_82(185) ':' chars(172).
	p(NT(184), (NT(185)+T(2)+NT(172)));
//G273: uninter_const_name(183) => __E_uninterpreted_constant_81(184).
	p(NT(183), (NT(184)));
//G274: uninterpreted_constant(164) => '<' uninter_const_name(183) _(11) '>'.
	p(NT(164), (T(20)+NT(183)+NT(11)+T(21)));
//G275: __E_bf_constant_83(187) => capture(20).
	p(NT(187), (NT(20)));
//G276: __E_bf_constant_83(187) => binding(188).
	p(NT(187), (NT(188)));
//G277: constant(186)        => __E_bf_constant_83(187).
	p(NT(186), (NT(187)));
//G278: type(129)            => chars(172).
	p(NT(129), (NT(172)));
//G279: __E_bf_constant_84(189) => _(11) ':' _(11) type(129).
	p(NT(189), (NT(11)+T(2)+NT(11)+NT(129)));
//G280: __E_bf_constant_84(189) => null.
	p(NT(189), (nul));
//G281: bf_constant(117)     => '{' _(11) constant(186) _(11) '}' __E_bf_constant_84(189).
	p(NT(117), (T(42)+NT(11)+NT(186)+NT(11)+T(43)+NT(189)));
//G282: __E___E___E_binding_85_86_87(194) => src_c(192).
	p(NT(194), (NT(192)));
//G283: __E___E___E_binding_85_86_87(194) => space(2).
	p(NT(194), (NT(2)));
//G284: __E___E___E_binding_85_86_88(195) => null.
	p(NT(195), (nul));
//G285: __E___E___E_binding_85_86_88(195) => __E___E___E_binding_85_86_87(194) __E___E___E_binding_85_86_88(195).
	p(NT(195), (NT(194)+NT(195)));
//G286: __E___E_binding_85_86(193) => __E___E___E_binding_85_86_88(195) src_c(192).
	p(NT(193), (NT(195)+NT(192)));
//G287: __E___E_binding_85_86(193) => null.
	p(NT(193), (nul));
//G288: __E_binding_85(191)  => src_c(192) __E___E_binding_85_86(193).
	p(NT(191), (NT(192)+NT(193)));
//G289: source(190)          => __E_binding_85(191).
	p(NT(190), (NT(191)));
//G290: binding(188)         => source(190).
	p(NT(188), (NT(190)));
//G291: src_c(192)           => alnum(6).
	p(NT(192), (NT(6)));
//G292: __N_7(365)           => '{'.
	p(NT(365), (T(42)));
//G293: __N_8(366)           => '}'.
	p(NT(366), (T(43)));
//G294: src_c(192)           => ~( __N_7(365) ) & ~( __N_8(366) ) & punct(7).	 # conjunctive
	p(NT(192), ~(NT(365)) & ~(NT(366)) & (NT(7)));
//G295: __E_src_c_89(196)    => src_c(192).
	p(NT(196), (NT(192)));
//G296: __E_src_c_89(196)    => space(2).
	p(NT(196), (NT(2)));
//G297: __E_src_c_90(197)    => null.
	p(NT(197), (nul));
//G298: __E_src_c_90(197)    => __E_src_c_89(196) __E_src_c_90(197).
	p(NT(197), (NT(196)+NT(197)));
//G299: src_c(192)           => '{' __E_src_c_90(197) '}'.
	p(NT(192), (T(42)+NT(197)+T(43)));
//G300: __E_chars_91(198)    => alnum(6).
	p(NT(198), (NT(6)));
//G301: __E_chars_91(198)    => '_'.
	p(NT(198), (T(40)));
//G302: __E_chars_92(199)    => null.
	p(NT(199), (nul));
//G303: __E_chars_92(199)    => __E_chars_91(198) __E_chars_92(199).
	p(NT(199), (NT(198)+NT(199)));
//G304: chars(172)           => alpha(5) __E_chars_92(199).
	p(NT(172), (NT(5)+NT(199)));
//G305: __E_digits_93(200)   => digit(3).
	p(NT(200), (NT(3)));
//G306: __E_digits_93(200)   => digit(3) __E_digits_93(200).
	p(NT(200), (NT(3)+NT(200)));
//G307: digits(182)          => __E_digits_93(200).
	p(NT(182), (NT(200)));
//G308: sym(22)              => chars(172).
	p(NT(22), (NT(172)));
//G309: __E_comment_94(202)  => printable(8).
	p(NT(202), (NT(8)));
//G310: __E_comment_94(202)  => '\t'.
	p(NT(202), (T(44)));
//G311: __E_comment_95(203)  => null.
	p(NT(203), (nul));
//G312: __E_comment_95(203)  => __E_comment_94(202) __E_comment_95(203).
	p(NT(203), (NT(202)+NT(203)));
//G313: __E_comment_96(204)  => '\n'.
	p(NT(204), (T(45)));
//G314: __E_comment_96(204)  => '\r'.
	p(NT(204), (T(46)));
//G315: __E_comment_96(204)  => eof(1).
	p(NT(204), (NT(1)));
//G316: comment(201)         => '#' __E_comment_95(203) __E_comment_96(204).
	p(NT(201), (T(47)+NT(203)+NT(204)));
//G317: __E____97(205)       => space(2).
	p(NT(205), (NT(2)));
//G318: __E____97(205)       => comment(201).
	p(NT(205), (NT(201)));
//G319: __(27)               => __E____97(205) _(11).
	p(NT(27), (NT(205)+NT(11)));
//G320: __E___98(206)        => __(27).
	p(NT(206), (NT(27)));
//G321: __E___98(206)        => null.
	p(NT(206), (nul));
//G322: _(11)                => __E___98(206).
	p(NT(11), (NT(206)));
//G323: cli(207)             => _(11).
	p(NT(207), (NT(11)));
//G324: __E_cli_99(209)      => '.' _(11) cli_command(208) _(11).
	p(NT(209), (T(1)+NT(11)+NT(208)+NT(11)));
//G325: __E_cli_100(210)     => null.
	p(NT(210), (nul));
//G326: __E_cli_100(210)     => __E_cli_99(209) __E_cli_100(210).
	p(NT(210), (NT(209)+NT(210)));
//G327: cli(207)             => _(11) cli_command(208) _(11) __E_cli_100(210).
	p(NT(207), (NT(11)+NT(208)+NT(11)+NT(210)));
//G328: __E_cli_command_101(213) => 'q'.
	p(NT(213), (T(48)));
//G329: __E_cli_command_101(213) => 'q' 'u' 'i' 't'.
	p(NT(213), (T(48)+T(49)+T(10)+T(13)));
//G330: quit_sym(212)        => __E_cli_command_101(213).
	p(NT(212), (NT(213)));
//G331: quit_cmd(211)        => quit_sym(212).
	p(NT(211), (NT(212)));
//G332: cli_command(208)     => quit_cmd(211).
	p(NT(208), (NT(211)));
//G333: __E_cli_command_102(216) => 'v'.
	p(NT(216), (T(50)));
//G334: __E_cli_command_102(216) => 'v' 'e' 'r' 's' 'i' 'o' 'n'.
	p(NT(216), (T(50)+T(19)+T(11)+T(12)+T(10)+T(17)+T(51)));
//G335: version_sym(215)     => __E_cli_command_102(216).
	p(NT(215), (NT(216)));
//G336: version_cmd(214)     => version_sym(215).
	p(NT(214), (NT(215)));
//G337: cli_command(208)     => version_cmd(214).
	p(NT(208), (NT(214)));
//G338: __E_cli_command_103(219) => 'c'.
	p(NT(219), (T(8)));
//G339: __E_cli_command_103(219) => 'c' 'l' 'e' 'a' 'r'.
	p(NT(219), (T(8)+T(6)+T(19)+T(5)+T(11)));
//G340: clear_sym(218)       => __E_cli_command_103(219).
	p(NT(218), (NT(219)));
//G341: clear_cmd(217)       => clear_sym(218).
	p(NT(217), (NT(218)));
//G342: cli_command(208)     => clear_cmd(217).
	p(NT(208), (NT(217)));
//G343: __E___E_cli_command_104_105(223) => 'h'.
	p(NT(223), (T(52)));
//G344: __E___E_cli_command_104_105(223) => 'h' 'e' 'l' 'p'.
	p(NT(223), (T(52)+T(19)+T(6)+T(53)));
//G345: help_sym(222)        => __E___E_cli_command_104_105(223).
	p(NT(222), (NT(223)));
//G346: __E___E_cli_command_104_106(224) => __(27) help_arg(225).
	p(NT(224), (NT(27)+NT(225)));
//G347: __E___E_cli_command_104_106(224) => null.
	p(NT(224), (nul));
//G348: __E_cli_command_104(221) => help_sym(222) __E___E_cli_command_104_106(224).
	p(NT(221), (NT(222)+NT(224)));
//G349: help_cmd(220)        => __E_cli_command_104(221).
	p(NT(220), (NT(221)));
//G350: cli_command(208)     => help_cmd(220).
	p(NT(208), (NT(220)));
//G351: file_sym(228)        => 'f' 'i' 'l' 'e'.
	p(NT(228), (T(4)+T(10)+T(6)+T(19)));
//G352: __E_cli_command_107(227) => file_sym(228) __(27) q_string(229).
	p(NT(227), (NT(228)+NT(27)+NT(229)));
//G353: file_cmd(226)        => __E_cli_command_107(227).
	p(NT(226), (NT(227)));
//G354: cli_command(208)     => file_cmd(226).
	p(NT(208), (NT(226)));
//G355: valid_sym(232)       => 'v' 'a' 'l' 'i' 'd'.
	p(NT(232), (T(50)+T(5)+T(6)+T(10)+T(54)));
//G356: __E_cli_command_108(231) => valid_sym(232) __(27) normalize_cmd_arg(233).
	p(NT(231), (NT(232)+NT(27)+NT(233)));
//G357: valid_cmd(230)       => __E_cli_command_108(231).
	p(NT(230), (NT(231)));
//G358: cli_command(208)     => valid_cmd(230).
	p(NT(208), (NT(230)));
//G359: sat_sym(236)         => 's' 'a' 't'.
	p(NT(236), (T(12)+T(5)+T(13)));
//G360: __E_cli_command_109(235) => sat_sym(236) __(27) normalize_cmd_arg(233).
	p(NT(235), (NT(236)+NT(27)+NT(233)));
//G361: sat_cmd(234)         => __E_cli_command_109(235).
	p(NT(234), (NT(235)));
//G362: cli_command(208)     => sat_cmd(234).
	p(NT(208), (NT(234)));
//G363: unsat_sym(239)       => 'u' 'n' 's' 'a' 't'.
	p(NT(239), (T(49)+T(51)+T(12)+T(5)+T(13)));
//G364: __E_cli_command_110(238) => unsat_sym(239) __(27) normalize_cmd_arg(233).
	p(NT(238), (NT(239)+NT(27)+NT(233)));
//G365: unsat_cmd(237)       => __E_cli_command_110(238).
	p(NT(237), (NT(238)));
//G366: cli_command(208)     => unsat_cmd(237).
	p(NT(208), (NT(237)));
//G367: solve_sym(242)       => 's' 'o' 'l' 'v' 'e'.
	p(NT(242), (T(12)+T(17)+T(6)+T(50)+T(19)));
//G368: __E___E_cli_command_111_112(243) => __(27) type(129).
	p(NT(243), (NT(27)+NT(129)));
//G369: __E___E_cli_command_111_112(243) => null.
	p(NT(243), (nul));
//G370: __E_cli_command_111(241) => solve_sym(242) __E___E_cli_command_111_112(243) __(27) solve_cmd_arg(244).
	p(NT(241), (NT(242)+NT(243)+NT(27)+NT(244)));
//G371: solve_cmd(240)       => __E_cli_command_111(241).
	p(NT(240), (NT(241)));
//G372: cli_command(208)     => solve_cmd(240).
	p(NT(208), (NT(240)));
//G373: __E___E_cli_command_113_114(248) => 'r'.
	p(NT(248), (T(11)));
//G374: __E___E_cli_command_113_114(248) => 'r' 'u' 'n'.
	p(NT(248), (T(11)+T(49)+T(51)));
//G375: run_sym(247)         => __E___E_cli_command_113_114(248).
	p(NT(247), (NT(248)));
//G376: __E___E_cli_command_113_115(249) => memory(250).
	p(NT(249), (NT(250)));
//G377: __E___E_cli_command_113_115(249) => wff(14).
	p(NT(249), (NT(14)));
//G378: __E_cli_command_113(246) => run_sym(247) __(27) __E___E_cli_command_113_115(249).
	p(NT(246), (NT(247)+NT(27)+NT(249)));
//G379: run_cmd(245)         => __E_cli_command_113(246).
	p(NT(245), (NT(246)));
//G380: cli_command(208)     => run_cmd(245).
	p(NT(208), (NT(245)));
//G381: __E___E_cli_command_116_117(254) => 'n'.
	p(NT(254), (T(51)));
//G382: __E___E_cli_command_116_117(254) => 'n' 'o' 'r' 'm' 'a' 'l' 'i' 'z' 'e'.
	p(NT(254), (T(51)+T(17)+T(11)+T(18)+T(5)+T(6)+T(10)+T(55)+T(19)));
//G383: normalize_sym(253)   => __E___E_cli_command_116_117(254).
	p(NT(253), (NT(254)));
//G384: __E_cli_command_116(252) => normalize_sym(253) __(27) normalize_cmd_arg(233).
	p(NT(252), (NT(253)+NT(27)+NT(233)));
//G385: normalize_cmd(251)   => __E_cli_command_116(252).
	p(NT(251), (NT(252)));
//G386: cli_command(208)     => normalize_cmd(251).
	p(NT(208), (NT(251)));
//G387: __E___E_cli_command_118_119(258) => 's'.
	p(NT(258), (T(12)));
//G388: __E___E_cli_command_118_119(258) => 's' 'u' 'b' 's' 't'.
	p(NT(258), (T(12)+T(49)+T(7)+T(12)+T(13)));
//G389: __E___E_cli_command_118_119(258) => 's' 'u' 'b' 's' 't' 'i' 't' 'u' 't' 'e'.
	p(NT(258), (T(12)+T(49)+T(7)+T(12)+T(13)+T(10)+T(13)+T(49)+T(13)+T(19)));
//G390: subst_sym(257)       => __E___E_cli_command_118_119(258).
	p(NT(257), (NT(258)));
//G391: __E_cli_command_118(256) => subst_sym(257) __(27) nf_cmd_arg(259) _(11) '[' _(11) nf_cmd_arg(259) _(11) '/' _(11) nf_cmd_arg(259) _(11) ']'.
	p(NT(256), (NT(257)+NT(27)+NT(259)+NT(11)+T(24)+NT(11)+NT(259)+NT(11)+T(56)+NT(11)+NT(259)+NT(11)+T(25)));
//G392: subst_cmd(255)       => __E_cli_command_118(256).
	p(NT(255), (NT(256)));
//G393: cli_command(208)     => subst_cmd(255).
	p(NT(208), (NT(255)));
//G394: __E___E_cli_command_120_121(263) => 'i'.
	p(NT(263), (T(10)));
//G395: __E___E_cli_command_120_121(263) => 'i' 'n' 's' 't'.
	p(NT(263), (T(10)+T(51)+T(12)+T(13)));
//G396: __E___E_cli_command_120_121(263) => 'i' 'n' 's' 't' 'a' 'n' 't' 'i' 'a' 't' 'e'.
	p(NT(263), (T(10)+T(51)+T(12)+T(13)+T(5)+T(51)+T(13)+T(10)+T(5)+T(13)+T(19)));
//G397: inst_sym(262)        => __E___E_cli_command_120_121(263).
	p(NT(262), (NT(263)));
//G398: __E_cli_command_120(261) => inst_sym(262) __(27) inst_args(264).
	p(NT(261), (NT(262)+NT(27)+NT(264)));
//G399: inst_cmd(260)        => __E_cli_command_120(261).
	p(NT(260), (NT(261)));
//G400: cli_command(208)     => inst_cmd(260).
	p(NT(208), (NT(260)));
//G401: dnf_sym(267)         => 'd' 'n' 'f'.
	p(NT(267), (T(54)+T(51)+T(4)));
//G402: __E_cli_command_122(266) => dnf_sym(267) __(27) nf_cmd_arg(259).
	p(NT(266), (NT(267)+NT(27)+NT(259)));
//G403: dnf_cmd(265)         => __E_cli_command_122(266).
	p(NT(265), (NT(266)));
//G404: cli_command(208)     => dnf_cmd(265).
	p(NT(208), (NT(265)));
//G405: cnf_sym(270)         => 'c' 'n' 'f'.
	p(NT(270), (T(8)+T(51)+T(4)));
//G406: __E_cli_command_123(269) => cnf_sym(270) __(27) nf_cmd_arg(259).
	p(NT(269), (NT(270)+NT(27)+NT(259)));
//G407: cnf_cmd(268)         => __E_cli_command_123(269).
	p(NT(268), (NT(269)));
//G408: cli_command(208)     => cnf_cmd(268).
	p(NT(208), (NT(268)));
//G409: anf_sym(273)         => 'a' 'n' 'f'.
	p(NT(273), (T(5)+T(51)+T(4)));
//G410: __E_cli_command_124(272) => anf_sym(273) __(27) nf_cmd_arg(259).
	p(NT(272), (NT(273)+NT(27)+NT(259)));
//G411: anf_cmd(271)         => __E_cli_command_124(272).
	p(NT(271), (NT(272)));
//G412: cli_command(208)     => anf_cmd(271).
	p(NT(208), (NT(271)));
//G413: nnf_sym(276)         => 'n' 'n' 'f'.
	p(NT(276), (T(51)+T(51)+T(4)));
//G414: __E_cli_command_125(275) => nnf_sym(276) __(27) nf_cmd_arg(259).
	p(NT(275), (NT(276)+NT(27)+NT(259)));
//G415: nnf_cmd(274)         => __E_cli_command_125(275).
	p(NT(274), (NT(275)));
//G416: cli_command(208)     => nnf_cmd(274).
	p(NT(208), (NT(274)));
//G417: pnf_sym(279)         => 'p' 'n' 'f'.
	p(NT(279), (T(53)+T(51)+T(4)));
//G418: __E_cli_command_126(278) => pnf_sym(279) __(27) nf_cmd_arg(259).
	p(NT(278), (NT(279)+NT(27)+NT(259)));
//G419: pnf_cmd(277)         => __E_cli_command_126(278).
	p(NT(277), (NT(278)));
//G420: cli_command(208)     => pnf_cmd(277).
	p(NT(208), (NT(277)));
//G421: mnf_sym(282)         => 'm' 'n' 'f'.
	p(NT(282), (T(18)+T(51)+T(4)));
//G422: __E_cli_command_127(281) => mnf_sym(282) __(27) nf_cmd_arg(259).
	p(NT(281), (NT(282)+NT(27)+NT(259)));
//G423: mnf_cmd(280)         => __E_cli_command_127(281).
	p(NT(280), (NT(281)));
//G424: cli_command(208)     => mnf_cmd(280).
	p(NT(208), (NT(280)));
//G425: snf_sym(285)         => 's' 'n' 'f'.
	p(NT(285), (T(12)+T(51)+T(4)));
//G426: __E_cli_command_128(284) => snf_sym(285) __(27) nf_cmd_arg(259).
	p(NT(284), (NT(285)+NT(27)+NT(259)));
//G427: snf_cmd(283)         => __E_cli_command_128(284).
	p(NT(283), (NT(284)));
//G428: cli_command(208)     => snf_cmd(283).
	p(NT(208), (NT(283)));
//G429: onf_sym(288)         => 'o' 'n' 'f'.
	p(NT(288), (T(17)+T(51)+T(4)));
//G430: __E_cli_command_129(287) => onf_sym(288) __(27) variable(118) __(27) onf_cmd_arg(289).
	p(NT(287), (NT(288)+NT(27)+NT(118)+NT(27)+NT(289)));
//G431: onf_cmd(286)         => __E_cli_command_129(287).
	p(NT(286), (NT(287)));
//G432: cli_command(208)     => onf_cmd(286).
	p(NT(208), (NT(286)));
//G433: __E___E_cli_command_130_131(293) => 'd' 'e' 'f' 's'.
	p(NT(293), (T(54)+T(19)+T(4)+T(12)));
//G434: __E___E_cli_command_130_131(293) => 'd' 'e' 'f' 'i' 'n' 'i' 't' 'i' 'o' 'n' 's'.
	p(NT(293), (T(54)+T(19)+T(4)+T(10)+T(51)+T(10)+T(13)+T(10)+T(17)+T(51)+T(12)));
//G435: def_sym(292)         => __E___E_cli_command_130_131(293).
	p(NT(292), (NT(293)));
//G436: __E_cli_command_130(291) => def_sym(292).
	p(NT(291), (NT(292)));
//G437: def_list_cmd(290)    => __E_cli_command_130(291).
	p(NT(290), (NT(291)));
//G438: cli_command(208)     => def_list_cmd(290).
	p(NT(208), (NT(290)));
//G439: __E_cli_command_132(295) => def_sym(292) __(27) number(296).
	p(NT(295), (NT(292)+NT(27)+NT(296)));
//G440: def_print_cmd(294)   => __E_cli_command_132(295).
	p(NT(294), (NT(295)));
//G441: cli_command(208)     => def_print_cmd(294).
	p(NT(208), (NT(294)));
//G442: def_rr_cmd(297)      => rec_relation(16).
	p(NT(297), (NT(16)));
//G443: cli_command(208)     => def_rr_cmd(297).
	p(NT(208), (NT(297)));
//G444: qelim_sym(300)       => 'q' 'e' 'l' 'i' 'm'.
	p(NT(300), (T(48)+T(19)+T(6)+T(10)+T(18)));
//G445: __E_cli_command_133(299) => qelim_sym(300) __(27) wff_cmd_arg(301).
	p(NT(299), (NT(300)+NT(27)+NT(301)));
//G446: qelim_cmd(298)       => __E_cli_command_133(299).
	p(NT(298), (NT(299)));
//G447: cli_command(208)     => qelim_cmd(298).
	p(NT(208), (NT(298)));
//G448: get_sym(304)         => 'g' 'e' 't'.
	p(NT(304), (T(57)+T(19)+T(13)));
//G449: __E___E_cli_command_134_135(305) => __(27) option_name(306).
	p(NT(305), (NT(27)+NT(306)));
//G450: __E___E_cli_command_134_135(305) => null.
	p(NT(305), (nul));
//G451: __E_cli_command_134(303) => get_sym(304) __E___E_cli_command_134_135(305).
	p(NT(303), (NT(304)+NT(305)));
//G452: get_cmd(302)         => __E_cli_command_134(303).
	p(NT(302), (NT(303)));
//G453: cli_command(208)     => get_cmd(302).
	p(NT(208), (NT(302)));
//G454: set_sym(309)         => 's' 'e' 't'.
	p(NT(309), (T(12)+T(19)+T(13)));
//G455: __E___E_cli_command_136_137(310) => __(27).
	p(NT(310), (NT(27)));
//G456: __E___E_cli_command_136_137(310) => _(11) '=' _(11).
	p(NT(310), (NT(11)+T(3)+NT(11)));
//G457: __E_cli_command_136(308) => set_sym(309) __(27) option_name(306) __E___E_cli_command_136_137(310) option_value(311).
	p(NT(308), (NT(309)+NT(27)+NT(306)+NT(310)+NT(311)));
//G458: set_cmd(307)         => __E_cli_command_136(308).
	p(NT(307), (NT(308)));
//G459: cli_command(208)     => set_cmd(307).
	p(NT(208), (NT(307)));
//G460: enable_sym(314)      => 'e' 'n' 'a' 'b' 'l' 'e'.
	p(NT(314), (T(19)+T(51)+T(5)+T(7)+T(6)+T(19)));
//G461: __E_cli_command_138(313) => enable_sym(314) __(27) option_name(306).
	p(NT(313), (NT(314)+NT(27)+NT(306)));
//G462: enable_cmd(312)      => __E_cli_command_138(313).
	p(NT(312), (NT(313)));
//G463: cli_command(208)     => enable_cmd(312).
	p(NT(208), (NT(312)));
//G464: disable_sym(317)     => 'd' 'i' 's' 'a' 'b' 'l' 'e'.
	p(NT(317), (T(54)+T(10)+T(12)+T(5)+T(7)+T(6)+T(19)));
//G465: __E_cli_command_139(316) => disable_sym(317) __(27) option_name(306).
	p(NT(316), (NT(317)+NT(27)+NT(306)));
//G466: disable_cmd(315)     => __E_cli_command_139(316).
	p(NT(315), (NT(316)));
//G467: cli_command(208)     => disable_cmd(315).
	p(NT(208), (NT(315)));
//G468: toggle_sym(320)      => 't' 'o' 'g' 'g' 'l' 'e'.
	p(NT(320), (T(13)+T(17)+T(57)+T(57)+T(6)+T(19)));
//G469: __E_cli_command_140(319) => toggle_sym(320) __(27) option_name(306).
	p(NT(319), (NT(320)+NT(27)+NT(306)));
//G470: toggle_cmd(318)      => __E_cli_command_140(319).
	p(NT(318), (NT(319)));
//G471: cli_command(208)     => toggle_cmd(318).
	p(NT(208), (NT(318)));
//G472: __E_cli_command_141(322) => type(129) __(27) in_var_name(165) _(11) '=' _(11) input_stream(323).
	p(NT(322), (NT(129)+NT(27)+NT(165)+NT(11)+T(3)+NT(11)+NT(323)));
//G473: def_input_cmd(321)   => __E_cli_command_141(322).
	p(NT(321), (NT(322)));
//G474: cli_command(208)     => def_input_cmd(321).
	p(NT(208), (NT(321)));
//G475: __E_cli_command_142(325) => type(129) __(27) out_var_name(169) _(11) '=' _(11) output_stream(326).
	p(NT(325), (NT(129)+NT(27)+NT(169)+NT(11)+T(3)+NT(11)+NT(326)));
//G476: def_output_cmd(324)  => __E_cli_command_142(325).
	p(NT(324), (NT(325)));
//G477: cli_command(208)     => def_output_cmd(324).
	p(NT(208), (NT(324)));
//G478: __E___E_cli_command_143_144(330) => 'h' 'i' 's' 't'.
	p(NT(330), (T(52)+T(10)+T(12)+T(13)));
//G479: __E___E_cli_command_143_144(330) => 'h' 'i' 's' 't' 'o' 'r' 'y'.
	p(NT(330), (T(52)+T(10)+T(12)+T(13)+T(17)+T(11)+T(23)));
//G480: history_sym(329)     => __E___E_cli_command_143_144(330).
	p(NT(329), (NT(330)));
//G481: __E_cli_command_143(328) => history_sym(329).
	p(NT(328), (NT(329)));
//G482: history_list_cmd(327) => __E_cli_command_143(328).
	p(NT(327), (NT(328)));
//G483: cli_command(208)     => history_list_cmd(327).
	p(NT(208), (NT(327)));
//G484: __E_cli_command_145(332) => history_sym(329) __(27) memory(250).
	p(NT(332), (NT(329)+NT(27)+NT(250)));
//G485: history_print_cmd(331) => __E_cli_command_145(332).
	p(NT(331), (NT(332)));
//G486: cli_command(208)     => history_print_cmd(331).
	p(NT(208), (NT(331)));
//G487: __E_cli_command_146(334) => wff(14).
	p(NT(334), (NT(14)));
//G488: __E_cli_command_146(334) => bf(21).
	p(NT(334), (NT(21)));
//G489: history_store_cmd(333) => __E_cli_command_146(334).
	p(NT(333), (NT(334)));
//G490: cli_command(208)     => history_store_cmd(333).
	p(NT(208), (NT(333)));
//G491: __E_input_stream_147(335) => 'i' 'f' 'i' 'l' 'e' _(11) '(' _(11) q_file_name(336) _(11) ')'.
	p(NT(335), (T(10)+T(4)+T(10)+T(6)+T(19)+NT(11)+T(15)+NT(11)+NT(336)+NT(11)+T(16)));
//G492: input_stream(323)    => __E_input_stream_147(335).
	p(NT(323), (NT(335)));
//G493: console_sym(337)     => 'c' 'o' 'n' 's' 'o' 'l' 'e'.
	p(NT(337), (T(8)+T(17)+T(51)+T(12)+T(17)+T(6)+T(19)));
//G494: input_stream(323)    => console_sym(337).
	p(NT(323), (NT(337)));
//G495: __E_output_stream_148(338) => 'o' 'f' 'i' 'l' 'e' _(11) '(' _(11) q_file_name(336) _(11) ')'.
	p(NT(338), (T(17)+T(4)+T(10)+T(6)+T(19)+NT(11)+T(15)+NT(11)+NT(336)+NT(11)+T(16)));
//G496: output_stream(326)   => __E_output_stream_148(338).
	p(NT(326), (NT(338)));
//G497: output_stream(326)   => console_sym(337).
	p(NT(326), (NT(337)));
//G498: q_file_name(336)     => '"' file_name(339) '"'.
	p(NT(336), (T(58)+NT(339)+T(58)));
//G499: __E_file_name_149(340) => printable(8).
	p(NT(340), (NT(8)));
//G500: __E_file_name_149(340) => printable(8) __E_file_name_149(340).
	p(NT(340), (NT(8)+NT(340)));
//G501: file_name(339)       => __E_file_name_149(340).
	p(NT(339), (NT(340)));
//G502: __E_option_name_150(341) => alnum(6).
	p(NT(341), (NT(6)));
//G503: __E_option_name_150(341) => alnum(6) __E_option_name_150(341).
	p(NT(341), (NT(6)+NT(341)));
//G504: option_name(306)     => __E_option_name_150(341).
	p(NT(306), (NT(341)));
//G505: __E_option_value_151(342) => alnum(6).
	p(NT(342), (NT(6)));
//G506: __E_option_value_151(342) => alnum(6) __E_option_value_151(342).
	p(NT(342), (NT(6)+NT(342)));
//G507: option_value(311)    => __E_option_value_151(342).
	p(NT(311), (NT(342)));
//G508: number(296)          => digits(182).
	p(NT(296), (NT(182)));
//G509: bf_cmd_arg(343)      => memory(250).
	p(NT(343), (NT(250)));
//G510: bf_cmd_arg(343)      => bf(21).
	p(NT(343), (NT(21)));
//G511: wff_cmd_arg(301)     => memory(250).
	p(NT(301), (NT(250)));
//G512: wff_cmd_arg(301)     => wff(14).
	p(NT(301), (NT(14)));
//G513: solve_cmd_arg(244)   => memory(250).
	p(NT(244), (NT(250)));
//G514: solve_cmd_arg(244)   => wff(14).
	p(NT(244), (NT(14)));
//G515: nf_cmd_arg(259)      => memory(250).
	p(NT(259), (NT(250)));
//G516: nf_cmd_arg(259)      => ref(18).
	p(NT(259), (NT(18)));
//G517: nf_cmd_arg(259)      => wff(14).
	p(NT(259), (NT(14)));
//G518: nf_cmd_arg(259)      => bf(21).
	p(NT(259), (NT(21)));
//G519: onf_cmd_arg(289)     => memory(250).
	p(NT(289), (NT(250)));
//G520: onf_cmd_arg(289)     => wff(14).
	p(NT(289), (NT(14)));
//G521: normalize_cmd_arg(233) => memory(250).
	p(NT(233), (NT(250)));
//G522: normalize_cmd_arg(233) => rr(10).
	p(NT(233), (NT(10)));
//G523: normalize_cmd_arg(233) => ref(18).
	p(NT(233), (NT(18)));
//G524: normalize_cmd_arg(233) => wff(14).
	p(NT(233), (NT(14)));
//G525: normalize_cmd_arg(233) => bf(21).
	p(NT(233), (NT(21)));
//G526: inst_args(264)       => wff_cmd_arg(301) _(11) '[' _(11) variable(118) _(11) '/' _(11) bf_cmd_arg(343) _(11) ']'.
	p(NT(264), (NT(301)+NT(11)+T(24)+NT(11)+NT(118)+NT(11)+T(56)+NT(11)+NT(343)+NT(11)+T(25)));
//G527: inst_args(264)       => bf_cmd_arg(343) _(11) '[' _(11) variable(118) _(11) '/' _(11) bf_cmd_arg(343) _(11) ']'.
	p(NT(264), (NT(343)+NT(11)+T(24)+NT(11)+NT(118)+NT(11)+T(56)+NT(11)+NT(343)+NT(11)+T(25)));
//G528: help_arg(225)        => help_sym(222).
	p(NT(225), (NT(222)));
//G529: help_arg(225)        => version_sym(215).
	p(NT(225), (NT(215)));
//G530: help_arg(225)        => quit_sym(212).
	p(NT(225), (NT(212)));
//G531: help_arg(225)        => clear_sym(218).
	p(NT(225), (NT(218)));
//G532: help_arg(225)        => get_sym(304).
	p(NT(225), (NT(304)));
//G533: help_arg(225)        => set_sym(309).
	p(NT(225), (NT(309)));
//G534: help_arg(225)        => enable_sym(314).
	p(NT(225), (NT(314)));
//G535: help_arg(225)        => disable_sym(317).
	p(NT(225), (NT(317)));
//G536: help_arg(225)        => toggle_sym(320).
	p(NT(225), (NT(320)));
//G537: help_arg(225)        => file_sym(228).
	p(NT(225), (NT(228)));
//G538: help_arg(225)        => history_sym(329).
	p(NT(225), (NT(329)));
//G539: help_arg(225)        => abs_memory_sym(344).
	p(NT(225), (NT(344)));
//G540: help_arg(225)        => rel_memory_sym(345).
	p(NT(225), (NT(345)));
//G541: help_arg(225)        => selection_sym(346).
	p(NT(225), (NT(346)));
//G542: help_arg(225)        => def_sym(292).
	p(NT(225), (NT(292)));
//G543: help_arg(225)        => inst_sym(262).
	p(NT(225), (NT(262)));
//G544: help_arg(225)        => subst_sym(257).
	p(NT(225), (NT(257)));
//G545: help_arg(225)        => normalize_sym(253).
	p(NT(225), (NT(253)));
//G546: help_arg(225)        => execute_sym(347).
	p(NT(225), (NT(347)));
//G547: help_arg(225)        => solve_sym(242).
	p(NT(225), (NT(242)));
//G548: help_arg(225)        => valid_sym(232).
	p(NT(225), (NT(232)));
//G549: help_arg(225)        => sat_sym(236).
	p(NT(225), (NT(236)));
//G550: help_arg(225)        => unsat_sym(239).
	p(NT(225), (NT(239)));
//G551: help_arg(225)        => run_sym(247).
	p(NT(225), (NT(247)));
//G552: help_arg(225)        => dnf_sym(267).
	p(NT(225), (NT(267)));
//G553: help_arg(225)        => cnf_sym(270).
	p(NT(225), (NT(270)));
//G554: help_arg(225)        => anf_sym(273).
	p(NT(225), (NT(273)));
//G555: help_arg(225)        => snf_sym(285).
	p(NT(225), (NT(285)));
//G556: help_arg(225)        => nnf_sym(276).
	p(NT(225), (NT(276)));
//G557: help_arg(225)        => pnf_sym(279).
	p(NT(225), (NT(279)));
//G558: help_arg(225)        => mnf_sym(282).
	p(NT(225), (NT(282)));
//G559: help_arg(225)        => onf_sym(288).
	p(NT(225), (NT(288)));
//G560: help_arg(225)        => qelim_sym(300).
	p(NT(225), (NT(300)));
//G561: __E___E_help_arg_152_153(350) => 's'.
	p(NT(350), (T(12)));
//G562: __E___E_help_arg_152_153(350) => null.
	p(NT(350), (nul));
//G563: __E_help_arg_152(349) => 'e' 'x' 'a' 'm' 'p' 'l' 'e' __E___E_help_arg_152_153(350).
	p(NT(349), (T(19)+T(27)+T(5)+T(18)+T(53)+T(6)+T(19)+NT(350)));
//G564: examples_sym(348)    => __E_help_arg_152(349).
	p(NT(348), (NT(349)));
//G565: help_arg(225)        => examples_sym(348).
	p(NT(225), (NT(348)));
//G566: __E_memory_154(352)  => '%'.
	p(NT(352), (T(59)));
//G567: rel_memory_sym(345)  => '%' '-'.
	p(NT(345), (T(59)+T(28)));
//G568: memory_id(354)       => digits(182).
	p(NT(354), (NT(182)));
//G569: __E___E_memory_154_155(353) => memory_id(354).
	p(NT(353), (NT(354)));
//G570: __E___E_memory_154_155(353) => null.
	p(NT(353), (nul));
//G571: __E_memory_154(352)  => rel_memory_sym(345) __E___E_memory_154_155(353).
	p(NT(352), (NT(345)+NT(353)));
//G572: rel_memory(351)      => __E_memory_154(352).
	p(NT(351), (NT(352)));
//G573: memory(250)          => rel_memory(351).
	p(NT(250), (NT(351)));
//G574: abs_memory_sym(344)  => '%'.
	p(NT(344), (T(59)));
//G575: __E_memory_156(356)  => abs_memory_sym(344) memory_id(354).
	p(NT(356), (NT(344)+NT(354)));
//G576: abs_memory(355)      => __E_memory_156(356).
	p(NT(355), (NT(356)));
//G577: memory(250)          => abs_memory(355).
	p(NT(250), (NT(355)));
	#undef T
	#undef NT
	return loaded = true, p;
}

inline ::idni::grammar<char_type, terminal_type> grammar(
	nts, productions(), start_symbol, char_classes, grammar_options);

} // namespace tau_parser_data

struct tau_parser : public idni::parser<char, char> {
	enum nonterminal {
		nul, eof, space, digit, xdigit, alpha, alnum, punct, printable, start, 
		rr, _, rec_relations, main, wff, __E_rec_relations_0, rec_relation, __E_rec_relations_1, ref, __E_rec_relation_2, 
		capture, bf, sym, __E_ref_3, offsets, ref_args, __E_ref_4, __, fp_fallback, first_sym, 
		last_sym, __E_ref_args_5, __E___E_ref_args_5_6, ref_arg, __E___E_ref_args_5_7, __E___E_ref_args_5_8, library, rules, __E_library_9, __E___E_library_9_10, 
		rule, __E___E___E_library_9_10_11, wff_rule, bf_rule, __E___E_library_9_12, wff_matcher, wff_body, __E_wff_rule_13, bf_matcher, bf_body, 
		__E_bf_rule_14, builder, builder_head, builder_body, __E_builder_head_15, __E_builder_head_16, bf_builder_body, __E_builder_body_17, wff_builder_body, __E_builder_body_18, 
		tau_constant_source, __E_tau_constant_source_19, wff_parenthesis, __E_wff_20, wff_sometimes, __E_wff_21, __E___E_wff_21_22, wff_always, __E_wff_23, __E___E_wff_23_24, 
		wff_conditional, __E_wff_25, wff_all, __E_wff_26, q_vars, wff_ex, __E_wff_27, wff_ref, constraint, wff_imply, 
		__E_wff_28, wff_equiv, __E_wff_29, wff_or, __E_wff_30, wff_xor, __E_wff_31, wff_and, __E_wff_32, wff_neg, 
		__E_wff_33, wff_t, wff_f, bf_interval, __E_wff_34, bf_eq, __E_wff_35, bf_neq, __E_wff_36, bf_less_equal, 
		__E_wff_37, bf_nleq, __E_wff_38, bf_greater, __E_wff_39, bf_ngreater, __E_wff_40, bf_greater_equal, __E_wff_41, bf_ngeq, 
		__E_wff_42, bf_less, __E_wff_43, bf_nless, __E_wff_44, bf_parenthesis, __E_bf_45, bf_constant, variable, bf_splitter, 
		__E_bf_46, bf_ref, bf_or, __E_bf_47, bf_xor, __E_bf_48, bf_t, __E_bf_49, __E___E_bf_49_50, type, 
		bf_f, __E_bf_51, __E___E_bf_51_52, bf_and, __E_bf_53, __E___E_bf_53_54, __E_bf_55, bf_and_nosep_1st_op, __E___E_bf_55_56, bf_neg, 
		__E_bf_57, ctn_neq, __E_constraint_58, ctnvar, num, ctn_eq, __E_constraint_59, ctn_greater_equal, __E_constraint_60, ctn_greater, 
		__E_constraint_61, ctn_less_equal, __E_constraint_62, ctn_less, __E_constraint_63, __E_variable_64, __E_variable_65, __E_variable_66, __E_variable_67, __E_variable_68, 
		io_var, __E_variable_69, in, out, uninterpreted_constant, in_var_name, __E_in_70, __E___E_in_70_71, offset, out_var_name, 
		__E_out_72, __E___E_out_72_73, chars, q_var, __E_q_vars_74, __E_q_vars_75, __E_offsets_76, __E_offsets_77, shift, __E_offset_78, 
		__E_shift_79, __E___E_shift_79_80, digits, uninter_const_name, __E_uninterpreted_constant_81, __E___E_uninterpreted_constant_81_82, constant, __E_bf_constant_83, binding, __E_bf_constant_84, 
		source, __E_binding_85, src_c, __E___E_binding_85_86, __E___E___E_binding_85_86_87, __E___E___E_binding_85_86_88, __E_src_c_89, __E_src_c_90, __E_chars_91, __E_chars_92, 
		__E_digits_93, comment, __E_comment_94, __E_comment_95, __E_comment_96, __E____97, __E___98, cli, cli_command, __E_cli_99, 
		__E_cli_100, quit_cmd, quit_sym, __E_cli_command_101, version_cmd, version_sym, __E_cli_command_102, clear_cmd, clear_sym, __E_cli_command_103, 
		help_cmd, __E_cli_command_104, help_sym, __E___E_cli_command_104_105, __E___E_cli_command_104_106, help_arg, file_cmd, __E_cli_command_107, file_sym, q_string, 
		valid_cmd, __E_cli_command_108, valid_sym, normalize_cmd_arg, sat_cmd, __E_cli_command_109, sat_sym, unsat_cmd, __E_cli_command_110, unsat_sym, 
		solve_cmd, __E_cli_command_111, solve_sym, __E___E_cli_command_111_112, solve_cmd_arg, run_cmd, __E_cli_command_113, run_sym, __E___E_cli_command_113_114, __E___E_cli_command_113_115, 
		memory, normalize_cmd, __E_cli_command_116, normalize_sym, __E___E_cli_command_116_117, subst_cmd, __E_cli_command_118, subst_sym, __E___E_cli_command_118_119, nf_cmd_arg, 
		inst_cmd, __E_cli_command_120, inst_sym, __E___E_cli_command_120_121, inst_args, dnf_cmd, __E_cli_command_122, dnf_sym, cnf_cmd, __E_cli_command_123, 
		cnf_sym, anf_cmd, __E_cli_command_124, anf_sym, nnf_cmd, __E_cli_command_125, nnf_sym, pnf_cmd, __E_cli_command_126, pnf_sym, 
		mnf_cmd, __E_cli_command_127, mnf_sym, snf_cmd, __E_cli_command_128, snf_sym, onf_cmd, __E_cli_command_129, onf_sym, onf_cmd_arg, 
		def_list_cmd, __E_cli_command_130, def_sym, __E___E_cli_command_130_131, def_print_cmd, __E_cli_command_132, number, def_rr_cmd, qelim_cmd, __E_cli_command_133, 
		qelim_sym, wff_cmd_arg, get_cmd, __E_cli_command_134, get_sym, __E___E_cli_command_134_135, option_name, set_cmd, __E_cli_command_136, set_sym, 
		__E___E_cli_command_136_137, option_value, enable_cmd, __E_cli_command_138, enable_sym, disable_cmd, __E_cli_command_139, disable_sym, toggle_cmd, __E_cli_command_140, 
		toggle_sym, def_input_cmd, __E_cli_command_141, input_stream, def_output_cmd, __E_cli_command_142, output_stream, history_list_cmd, __E_cli_command_143, history_sym, 
		__E___E_cli_command_143_144, history_print_cmd, __E_cli_command_145, history_store_cmd, __E_cli_command_146, __E_input_stream_147, q_file_name, console_sym, __E_output_stream_148, file_name, 
		__E_file_name_149, __E_option_name_150, __E_option_value_151, bf_cmd_arg, abs_memory_sym, rel_memory_sym, selection_sym, execute_sym, examples_sym, __E_help_arg_152, 
		__E___E_help_arg_152_153, rel_memory, __E_memory_154, __E___E_memory_154_155, memory_id, abs_memory, __E_memory_156, named_binding, __N_0, __N_1, 
		__N_2, __N_3, __N_4, __N_5, __N_6, __N_7, __N_8, 
	};
	static tau_parser& instance() {
		static tau_parser inst;
		return inst;
	}
	tau_parser() : idni::parser<char_type, terminal_type>(
		tau_parser_data::grammar,
		tau_parser_data::parser_options) {}
	size_t id(const std::basic_string<char_type>& name) {
		return tau_parser_data::nts.get(name);
	}
	const std::basic_string<char_type>& name(size_t id) {
		return tau_parser_data::nts.get(id);
	}
	symbol_type literal(const nonterminal& nt) {
		return symbol_type(nt, &tau_parser_data::nts);
	}
};

#endif // __TAU_PARSER_H__
