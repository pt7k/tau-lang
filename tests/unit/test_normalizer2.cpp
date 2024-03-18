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

#include "../../src/doctest.h"
#include "../../src/normalizer2.h"
#include "../../src/bdd_handle.h"

using namespace idni::rewriter;
using namespace idni::tau;

namespace testing = doctest;

TEST_SUITE("steps parsing") {

	TEST_CASE("apply_defs") {
		CHECK( apply_defs<Bool>.size() == 7 );
	}

	TEST_CASE("apply_defs_once") {
		CHECK( apply_defs_once<Bool>.size() == 5 );
	}

	TEST_CASE("elim_for_all") {
		CHECK( elim_for_all<Bool>.size() == 1 );
	}

	TEST_CASE("to_dnf_wff") {
		CHECK( to_dnf_wff<Bool>.size() == 7 );
	}

	TEST_CASE("simplify_bf") {
		CHECK( simplify_bf<Bool>.size() == 16 );
	}

	TEST_CASE("simplify_wff") {
		CHECK( simplify_wff<Bool>.size() == 16 );
	}

	TEST_CASE("apply_cb") {
		CHECK( apply_cb<Bool>.size() == 6 );
	}

	TEST_CASE("squeeze_positives") {
		CHECK( squeeze_positives<Bool>.size() == 1 );
	}

	TEST_CASE("wff_remove_existential") {
		CHECK( wff_remove_existential<Bool>.size() == 1 );
	}

	TEST_CASE("bf_positives_upwards") {
		CHECK( bf_positives_upwards<Bool>.size() == 5 );
	}

	TEST_CASE("bf_positives_upwards") {
		CHECK( bf_positives_upwards<Bool>.size() == 5 );
	}

	TEST_CASE("bf_elim_quantifiers") {
		CHECK( bf_elim_quantifiers<Bool>.size() == 2 );
	}

	TEST_CASE("trivialities") {
		CHECK( trivialities<Bool>.size() == 4 );
	}
}

// TODO (HIGH) write tests to check simplify_dnfs
// TODO (HIGH) write tests to check simplify_dnf
// TODO (HIGH) write tests to check build_dnf_from_clauses
// TODO (HIGH) write tests to check has_dnf_clause_clashing_literals
// TODO (HIGH) write tests to check get_dnf_clauses
// TODO (HIGH) write tests to check get_positive_negative_literals
// TODO (HIGH) write tests to check get_literals

// TODO (VERY LOW) write tests to check make_tau_source
// TODO (VERY LOW) write tests to check make_tau_source_from_file
// TODO (VERY LOW) write tests to check process_digits
// TODO (VERY LOW) write tests to check make_tau_code
// TODO (VERY LOW) write tests to check make_library
// TODO (VERY LOW) write tests to check make_nso_rr_using_binder
// TODO (VERY LOW) write tests to check make_nso_rr_using_bindings
// TODO (VERY LOW) write tests to check make_nso_rr_using_factory
// TODO (VERY LOW) write tests to check make_builder

// TODO (VERY LOW) write tests to check tau_apply_builder
// TODO (VERY LOW) write tests to check trim
// TODO (VERY LOW) write tests to check wrap

// TODO (VERY LOW) write tests to check nso_rr_apply_if
// TODO (VERY LOW) write tests to check nso_rr_apply

// TODO (VERY LOW) write tests to check operator<< (all versions)


// TODO (LOW) write tests to check steps
// TODO (LOW) write tests to check repeat_each
// TODO (LOW) write tests to check repeat_all
// TODO (LOW) write tests to check repeat
// TODO (LOW) write tests to check operator| (all versions)

// TODO (LOW) write tests to check get_free_vars_from_nso
