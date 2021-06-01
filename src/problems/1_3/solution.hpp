// Copyright 2021 Long Le Phi. All rights reserved.
// Use of this source code is governed by a MIT license that can be
// found in the LICENSE file.

#ifndef PROBLEMS_1_3_SOLUTION_HPP_
#define PROBLEMS_1_3_SOLUTION_HPP_

#include <cstdint>
#include <vector>

namespace longlp::solution {
  struct Problem_1_3 {
    static auto BinaryLCM(const std::vector<uintmax_t>& params) -> uintmax_t;

    static auto StandardLCM(const std::vector<uintmax_t>& params) -> uintmax_t;
  };

}   // namespace longlp::solution

#endif   // PROBLEMS_1_3_SOLUTION_HPP_
