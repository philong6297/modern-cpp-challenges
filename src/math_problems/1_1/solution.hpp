// Copyright 2022 Long Le Phi. All rights reserved.
// Use of this source code is governed by a MIT license that can be
// found in the LICENSE file.

#ifndef MATH_PROBLEMS_1_1_SOLUTION_HPP_
#define MATH_PROBLEMS_1_1_SOLUTION_HPP_

// Sum of naturals divisible by 3 and 5
//
// Write a program that calculates and prints the sum of all the natural numbers
// divisible by either 3 or 5, up to a given limit entered by the user.

#include <cstdint>

namespace longlp {
  inline constexpr auto Solve_1_1(uintmax_t upper_limit) -> uintmax_t {
    const auto n15 = upper_limit / 15;
    const auto n3  = upper_limit / 3;
    const auto n5  = upper_limit / 5;

    return (3 * n3 * (n3 + 1) + 5 * n5 * (n5 + 1) - 15 * n15 * (n15 + 1)) / 2;
  }
}   // namespace longlp

#endif   // MATH_PROBLEMS_1_1_SOLUTION_HPP_
