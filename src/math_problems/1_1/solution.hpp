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
  auto Solve(uint64_t limit) -> uint64_t;
}   // namespace longlp

#endif   // MATH_PROBLEMS_1_1_SOLUTION_HPP_
