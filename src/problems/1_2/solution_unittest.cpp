// Copyright 2021 Long Le Phi. All rights reserved.
// Use of this source code is governed by a MIT license that can be
// found in the LICENSE file.

#include "problems/1_2/solution.hpp"

#include <array>
#include <vector>

#include "doctest/doctest.h"

namespace {
  using longlp::solution::Problem_1_2;
}   // namespace

// NOLINTNEXTLINE(modernize-use-trailing-return-type)
TEST_SUITE("Solution 1.2") {
  TEST_CASE("Small numbers") {
    const std::vector<std::array<uintmax_t, 2>> pairs = {
      {61, 93}, {68, 97}, {85, 31}, {83, 88}, {91, 28}, {100, 45}, {94, 89},
      {87, 20}, {55, 81}, {62, 34}, {18, 3},  {1, 79},  {39, 6},   {75, 43},
      {33, 2},  {17, 44}, {14, 48}, {49, 24}, {7, 84},  {72, 32},  {98, 50},
      {69, 8},  {11, 13}, {95, 41}, {51, 12}, {63, 10}, {76, 30},  {70, 80},
      {19, 78}, {23, 53}, {15, 90}, {5, 37},  {27, 29}, {64, 58},  {9, 60},
      {56, 74}, {22, 25}, {42, 92}, {96, 82}, {4, 59},  {67, 52},  {54, 71},
      {86, 26}, {46, 65}, {99, 16}, {36, 21}, {40, 73}, {38, 66},  {77, 57},
      {35, 47},
    };
    for (const auto& pair : pairs) {
      CAPTURE(pair);
      const auto standard = Problem_1_2::StandardGCD(pair.front(), pair.back());
      const auto binary   = Problem_1_2::BinaryGCD(pair.front(), pair.back());
      CAPTURE(standard);
      CAPTURE(binary);

      REQUIRE_EQ(standard, binary);
    }
  }

  TEST_CASE("Big numbers") {
    const std::vector<std::array<uintmax_t, 2>> pairs = {
      {11600, 14938}, {17800, 19790}, {21185, 21405}, {21573, 21689},
      {23116, 24166}, {25907, 25958}, {27485, 27556}, {29470, 31409},
      {35409, 38034}, {40145, 43124}, {43177, 43919}, {44044, 47572},
      {49040, 50115}, {50147, 50251}, {57330, 58656}, {60279, 61748},
      {62875, 65858}, {69192, 69207}, {70901, 70962}, {72658, 76922},
      {78169, 79792}, {80287, 80376}, {80500, 83359}, {84571, 88670},
      {90497, 97307}};
    for (const auto& pair : pairs) {
      CAPTURE(pair);
      const auto standard = Problem_1_2::StandardGCD(pair.front(), pair.back());
      const auto binary   = Problem_1_2::BinaryGCD(pair.front(), pair.back());
      CAPTURE(standard);
      CAPTURE(binary);

      REQUIRE_EQ(standard, binary);
    }
  }
}
