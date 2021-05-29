// Copyright 2021 Long Le Phi. All rights reserved.
// Use of this source code is governed by a MIT license that can be
// found in the LICENSE file.

#include "problems/1_1/solution.hpp"

#include <array>

#include "doctest/doctest.h"

namespace {
  using longlp::solution::Problem_1_1;
}   // namespace

// NOLINTNEXTLINE(modernize-use-trailing-return-type)
TEST_SUITE("Solution 1.1") {
  TEST_CASE("Number is divisible by 15") {
    constexpr std::array<uintmax_t, 3> limits{15, 15 * 123, 15 * 567'891};
    for (const auto upper_limit : limits) {
      CAPTURE(upper_limit);

      const auto it_with_branch =
        Problem_1_1::IterationWithBranches(upper_limit);
      const auto it_no_branch =
        Problem_1_1::IterationWithNoBranches(upper_limit);
      const auto formula = Problem_1_1::UseFormula(upper_limit);

      CAPTURE(it_with_branch);
      CAPTURE(it_no_branch);
      CAPTURE(formula);

      REQUIRE_EQ(it_with_branch, it_no_branch);
      REQUIRE_EQ(it_with_branch, formula);
    }
  }

  TEST_CASE("Number is divisible by 3, not divisible by 5") {
    constexpr std::array<uintmax_t, 3> limits{3, 3 * 1234, 3 * 567'891};
    for (const auto upper_limit : limits) {
      CAPTURE(upper_limit);

      const auto it_with_branch =
        Problem_1_1::IterationWithBranches(upper_limit);
      const auto it_no_branch =
        Problem_1_1::IterationWithNoBranches(upper_limit);
      const auto formula = Problem_1_1::UseFormula(upper_limit);

      CAPTURE(it_with_branch);
      CAPTURE(it_no_branch);
      CAPTURE(formula);

      REQUIRE_EQ(Problem_1_1::UseFormula(upper_limit),
                 Problem_1_1::IterationWithBranches(upper_limit));
      REQUIRE_EQ(Problem_1_1::IterationWithNoBranches(upper_limit),
                 Problem_1_1::IterationWithBranches(upper_limit));
    }
  }

  TEST_CASE("Number is not divisible by 3, divisible by 5") {
    constexpr std::array<uintmax_t, 3> limits{5, 5 * 1234, 5 * 567'892};
    for (const auto upper_limit : limits) {
      CAPTURE(upper_limit);

      const auto it_with_branch =
        Problem_1_1::IterationWithBranches(upper_limit);
      const auto it_no_branch =
        Problem_1_1::IterationWithNoBranches(upper_limit);
      const auto formula = Problem_1_1::UseFormula(upper_limit);

      CAPTURE(it_with_branch);
      CAPTURE(it_no_branch);
      CAPTURE(formula);

      REQUIRE_EQ(Problem_1_1::UseFormula(upper_limit),
                 Problem_1_1::IterationWithBranches(upper_limit));
      REQUIRE_EQ(Problem_1_1::IterationWithNoBranches(upper_limit),
                 Problem_1_1::IterationWithBranches(upper_limit));
    }
  }

  TEST_CASE("Number is not divisible by 15") {
    constexpr std::array<uintmax_t, 3> limits{15 + 1,
                                              15 * 123 + 1,
                                              15 * 567'891 + 1};
    for (const auto upper_limit : limits) {
      CAPTURE(upper_limit);

      const auto it_with_branch =
        Problem_1_1::IterationWithBranches(upper_limit);
      const auto it_no_branch =
        Problem_1_1::IterationWithNoBranches(upper_limit);
      const auto formula = Problem_1_1::UseFormula(upper_limit);

      CAPTURE(it_with_branch);
      CAPTURE(it_no_branch);
      CAPTURE(formula);

      REQUIRE_EQ(Problem_1_1::UseFormula(upper_limit),
                 Problem_1_1::IterationWithBranches(upper_limit));
      REQUIRE_EQ(Problem_1_1::IterationWithNoBranches(upper_limit),
                 Problem_1_1::IterationWithBranches(upper_limit));
    }
  }
}
