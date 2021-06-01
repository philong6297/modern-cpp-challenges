// Copyright 2021 Long Le Phi. All rights reserved.
// Use of this source code is governed by a MIT license that can be
// found in the LICENSE file.

#include "problems/1_3/solution.hpp"

#include <vector>

#include "doctest/doctest.h"

namespace {
  using longlp::solution::Problem_1_3;
}   // namespace

// NOLINTNEXTLINE(modernize-use-trailing-return-type)
TEST_SUITE("Solution 1.3") {
  TEST_CASE("Params size = 0") {
    const std::vector<uintmax_t> params{};
    REQUIRE(params.empty());

    const auto binary   = Problem_1_3::BinaryLCM(params);
    const auto standard = Problem_1_3::StandardLCM(params);

    CAPTURE(binary);
    CAPTURE(standard);
    REQUIRE_EQ(binary, standard);
    REQUIRE_EQ(binary, 0);
    REQUIRE_EQ(standard, 0);
  }

  TEST_CASE("Params size = 1") {
    SUBCASE("Small numbers") {
      const std::vector<uintmax_t> params{1019};
      REQUIRE_EQ(params.size(), 1);

      const auto binary   = Problem_1_3::BinaryLCM(params);
      const auto standard = Problem_1_3::StandardLCM(params);

      CAPTURE(binary);
      CAPTURE(standard);
      CAPTURE(params.front());

      REQUIRE_EQ(binary, standard);
      REQUIRE_EQ(binary, params.front());
      REQUIRE_EQ(standard, params.front());
    }

    SUBCASE("Big numbers") {
      const std::vector<uintmax_t> params{1'123'456};
      REQUIRE_EQ(params.size(), 1);

      const auto binary   = Problem_1_3::BinaryLCM(params);
      const auto standard = Problem_1_3::StandardLCM(params);

      CAPTURE(binary);
      CAPTURE(standard);
      CAPTURE(params.front());

      REQUIRE_EQ(binary, standard);
      REQUIRE_EQ(binary, params.front());
      REQUIRE_EQ(standard, params.front());
    }
  }

  TEST_CASE("Params size = 2") {
    SUBCASE("Small numbers") {
      const std::vector<uintmax_t> params{1024, 5677};
      REQUIRE_EQ(params.size(), 2);

      const auto binary   = Problem_1_3::BinaryLCM(params);
      const auto standard = Problem_1_3::StandardLCM(params);

      CAPTURE(binary);
      CAPTURE(standard);

      REQUIRE_EQ(binary, standard);
      REQUIRE_EQ(binary, 5'813'248);
      REQUIRE_EQ(standard, 5'813'248);
    }

    SUBCASE("Big numbers") {
      const std::vector<uintmax_t> params{10242, 56778};
      REQUIRE_EQ(params.size(), 2);

      const auto binary   = Problem_1_3::BinaryLCM(params);
      const auto standard = Problem_1_3::StandardLCM(params);

      CAPTURE(binary);
      CAPTURE(standard);

      REQUIRE_EQ(binary, standard);
      REQUIRE_EQ(binary, 96'920'046);
      REQUIRE_EQ(standard, 96'920'046);
    }
  }

  TEST_CASE("Params size > 2") {
    SUBCASE("Small numbers") {
      const std::vector<uintmax_t> params{12, 22, 33, 37, 41, 45, 54, 84};
      REQUIRE_EQ(params.size(), 8);

      const auto binary   = Problem_1_3::BinaryLCM(params);
      const auto standard = Problem_1_3::StandardLCM(params);

      CAPTURE(binary);
      CAPTURE(standard);

      REQUIRE_EQ(binary, standard);
      REQUIRE_EQ(binary, 63'076'860);
      REQUIRE_EQ(standard, 63'076'860);
    }

    SUBCASE("Big numbers") {
      const std::vector<uintmax_t> params{2742, 1106, 2424};
      REQUIRE_EQ(params.size(), 3);

      const auto binary   = Problem_1_3::BinaryLCM(params);
      const auto standard = Problem_1_3::StandardLCM(params);

      CAPTURE(binary);
      CAPTURE(standard);

      REQUIRE_EQ(binary, standard);
      REQUIRE_EQ(binary, 612'595'704);
      REQUIRE_EQ(standard, 612'595'704);
    }
  }
}
