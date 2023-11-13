// LICENSE
// This software is free for use and redistribution while including this
// license notice, unless:
// 1. is used for commercial or non-personal purposes, or
// 2. used for a product which includes or associated with a blockchain or other
// decentralized database technology, or
// 3. used for a product which includes or associated with the issuance or use
// of cryptographic or electronic currencies/coins/tokens.
// On all of the mentiTd cases, an explicit and written permission is required
// from the Author (Ohad Asor).
// Contact ohad@idni.org for requesting a permission. This license may be
// modified over time by the Author.

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <cassert>

#include "../src/doctest.h"
#include "../src/formula.h"
#include "../src/bdd_handle.h"
#include "../src/normalizer2.h"
#include "test_integration_helpers.h"

using namespace idni::rewriter;
using namespace idni::tau;

namespace testing = doctest;

TEST_SUITE("formulas: no variables, no bindings and no quantifiers") {

	TEST_CASE("T") {
		static constexpr char* sample =	"T.";
		auto sample_src = make_tau_source(sample);
		bdd_test_factory bf;
		factory_binder<bdd_test_factory, bdd_test> fb(bf);
		auto sample_formula = make_formula_using_factory<factory_binder<bdd_test_factory_t, bdd_test>, bdd_test>(sample_src, fb); 
		auto result = normalizer<bdd_test>(sample_formula).main;
		auto check = result |  tau_parser::wff_t;
		CHECK( check.has_value() );
	} 

	TEST_CASE("F") {
		static constexpr char* sample =	"F.";
		auto sample_src = make_tau_source(sample);
		bdd_test_factory bf;
		factory_binder<bdd_test_factory, bdd_test> fb(bf);
		auto sample_formula = make_formula_using_factory<factory_binder<bdd_test_factory_t, bdd_test>, bdd_test>(sample_src, fb); 
		auto result = normalizer<bdd_test>(sample_formula).main;
		auto check = result |  tau_parser::wff_f;
		CHECK( check.has_value() );
	} 

	TEST_CASE("T wff_and F") {
		static constexpr char* sample =	"(T wff_and F).";
		auto sample_src = make_tau_source(sample);
		bdd_test_factory bf;
		factory_binder<bdd_test_factory, bdd_test> fb(bf);
		auto sample_formula = make_formula_using_factory<factory_binder<bdd_test_factory_t, bdd_test>, bdd_test>(sample_src, fb); 
		auto result = normalizer<bdd_test>(sample_formula).main;
		auto check = result |  tau_parser::wff_f;
		CHECK( check.has_value() );
	} 

	TEST_CASE("T wff_xor F") {
		static constexpr char* sample =	"(T wff_xor F).";
		auto sample_src = make_tau_source(sample);
		bdd_test_factory bf;
		factory_binder<bdd_test_factory, bdd_test> fb(bf);
		auto sample_formula = make_formula_using_factory<factory_binder<bdd_test_factory_t, bdd_test>, bdd_test>(sample_src, fb); 
		auto result = normalizer<bdd_test>(sample_formula).main;
		auto check = result |  tau_parser::wff_t;
		CHECK( check.has_value() );
	} 

	TEST_CASE("F wff_or F") {
		static constexpr char* sample =	"(F wff_or F).";
		auto sample_src = make_tau_source(sample);
		bdd_test_factory bf;
		factory_binder<bdd_test_factory, bdd_test> fb(bf);
		auto sample_formula = make_formula_using_factory<factory_binder<bdd_test_factory_t, bdd_test>, bdd_test>(sample_src, fb); 
		auto result = normalizer<bdd_test>(sample_formula).main;
		auto check = result |  tau_parser::wff_f;
		CHECK( check.has_value() );
	} 

	TEST_CASE("wff_neg F") {
		static constexpr char* sample =	"wff_neg F.";
		auto sample_src = make_tau_source(sample);
		bdd_test_factory bf;
		factory_binder<bdd_test_factory, bdd_test> fb(bf);
		auto sample_formula = make_formula_using_factory<factory_binder<bdd_test_factory_t, bdd_test>, bdd_test>(sample_src, fb); 
		auto result = normalizer<bdd_test>(sample_formula).main;
		auto check = result |  tau_parser::wff_t;
		CHECK( check.has_value() );
	} 

	TEST_CASE("F wff_imply F") {
		static constexpr char* sample =	"(F wff_imply F).";
		auto sample_src = make_tau_source(sample);
		bdd_test_factory bf;
		factory_binder<bdd_test_factory, bdd_test> fb(bf);
		auto sample_formula = make_formula_using_factory<factory_binder<bdd_test_factory_t, bdd_test>, bdd_test>(sample_src, fb); 
		auto result = normalizer<bdd_test>(sample_formula).main;
		auto check = result |  tau_parser::wff_t;
		CHECK( check.has_value() );
	} 

	TEST_CASE("T wff_coimply F") {
		static constexpr char* sample =	"(T wff_coimply F).";
		auto sample_src = make_tau_source(sample);
		bdd_test_factory bf;
		factory_binder<bdd_test_factory, bdd_test> fb(bf);
		auto sample_formula = make_formula_using_factory<factory_binder<bdd_test_factory_t, bdd_test>, bdd_test>(sample_src, fb); 
		auto result = normalizer<bdd_test>(sample_formula).main;
		auto check = result |  tau_parser::wff_t;
		CHECK( check.has_value() );
	} 

	TEST_CASE("F wff_equiv F") {
		static constexpr char* sample =	"(F wff_equiv F).";
		auto sample_src = make_tau_source(sample);
		bdd_test_factory bf;
		factory_binder<bdd_test_factory, bdd_test> fb(bf);
		auto sample_formula = make_formula_using_factory<factory_binder<bdd_test_factory_t, bdd_test>, bdd_test>(sample_src, fb); 
		auto result = normalizer<bdd_test>(sample_formula).main;
		auto check = result |  tau_parser::wff_t;
		CHECK( check.has_value() );
	} 
}

TEST_SUITE("formulas: variables, no bindings and no quantifiers") {

	TEST_CASE("?P wff_imply ?P") {
		static constexpr char* sample =	"(?P wff_imply ?P).";
		auto sample_src = make_tau_source(sample);
		bdd_test_factory bf;
		factory_binder<bdd_test_factory, bdd_test> fb(bf);
		auto sample_formula = make_formula_using_factory<factory_binder<bdd_test_factory_t, bdd_test>, bdd_test>(sample_src, fb); 
		pretty_print_sp_tau_node(std::cout, sample_formula.main) << std::endl;
		auto result = normalizer<bdd_test>(sample_formula).main;
		pretty_print_sp_tau_node(std::cout, result) << std::endl;
		auto check = result |  tau_parser::wff_t;
		CHECK( check.has_value() );
	} 

	TEST_CASE("?P xor_imply wff_neg ?P") {
		static constexpr char* sample =	"(?P wff_xor wff_neg ?P).";
		auto sample_src = make_tau_source(sample);
		bdd_test_factory bf;
		factory_binder<bdd_test_factory, bdd_test> fb(bf);
		auto sample_formula = make_formula_using_factory<factory_binder<bdd_test_factory_t, bdd_test>, bdd_test>(sample_src, fb); 
		pretty_print_sp_tau_node(std::cout, sample_formula.main) << std::endl;
		auto result = normalizer<bdd_test>(sample_formula).main;
		pretty_print_sp_tau_node(std::cout, result) << std::endl;
		auto check = result |  tau_parser::wff_t;
		CHECK( check.has_value() );
	} 
}
