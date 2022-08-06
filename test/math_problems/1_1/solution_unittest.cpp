// Copyright 2022 Long Le Phi. All rights reserved.
// Use of this source code is governed by a MIT license that can be
// found in the LICENSE file.

#include "math_problems/1_1/solution.hpp"

#include <array>
#include <catch2/catch_test_macros.hpp>
#include <catch2/generators/catch_generators_all.hpp>

namespace {
  auto GroundTruthSolution(const uintmax_t upper_limit) {
    uintmax_t sum = 0;
    for (uintmax_t i = 3; i <= upper_limit; i += 3) {
      sum += i;
    }
    for (uintmax_t i = 5; i <= upper_limit; i += 5) {
      sum += i;
    }
    for (uintmax_t i = 15; i <= upper_limit; i += 15) {
      sum -= i;
    }
    return sum;
  }
}   // namespace

TEST_CASE("Solution 1.1") {
  const auto origin =
    GENERATE(take(50, random(uintmax_t{100'000}, uintmax_t{999'999})));

  SECTION("[mod15 == 0]") {
    const auto input    = origin * 15;
    const auto expected = GroundTruthSolution(input);
    const auto actual   = longlp::Solve_1_1(input);
    CAPTURE(input);
    CAPTURE(expected);
    REQUIRE(expected == actual);
  }

  SECTION("[mod3 != 0, mod5 == 0]") {
    const auto input    = origin * 15 + 5;
    const auto expected = GroundTruthSolution(input);
    const auto actual   = longlp::Solve_1_1(input);
    CAPTURE(input);
    CAPTURE(expected);
    REQUIRE(expected == actual);
  }

  SECTION("[mod3 == 0, mod5 != 0]") {
    const auto input    = origin * 15 + 3;
    const auto expected = GroundTruthSolution(input);
    const auto actual   = longlp::Solve_1_1(input);
    CAPTURE(input);
    CAPTURE(expected);
    REQUIRE(expected == actual);
  }

  SECTION("[mod15 != 0]") {
    const auto input    = origin * 15 + 1;
    const auto expected = GroundTruthSolution(input);
    const auto actual   = longlp::Solve_1_1(input);
    CAPTURE(input);
    CAPTURE(expected);
    REQUIRE(expected == actual);
  }
}
