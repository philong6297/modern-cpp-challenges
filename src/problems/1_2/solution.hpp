// Copyright 2021 Long Le Phi. All rights reserved.
// Use of this source code is governed by a MIT license that can be
// found in the LICENSE file.

#ifndef PROBLEMS_1_2_SOLUTION_HPP_
#define PROBLEMS_1_2_SOLUTION_HPP_

#include <cstdint>

namespace longlp::solution {
  struct Problem_1_2 {
    static auto StandardGCD(uintmax_t u, uintmax_t v) -> uintmax_t;

    static auto BinaryGCD(uintmax_t u, uintmax_t v) -> uintmax_t;
  };

}   // namespace longlp::solution

#endif   // PROBLEMS_1_2_SOLUTION_HPP_
