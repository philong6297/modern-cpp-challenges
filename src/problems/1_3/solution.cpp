// Copyright 2021 Long Le Phi. All rights reserved.
// Use of this source code is governed by a MIT license that can be
// found in the LICENSE file.

#include "problems/1_3/solution.hpp"

#include <algorithm>
#include <numeric>

#include "problems/1_2/solution.hpp"

namespace {
  using longlp::solution::Problem_1_2;
  using longlp::solution::Problem_1_3;

}   // namespace

// static
auto Problem_1_3::StandardLCM(const std::vector<uintmax_t>& params)
  -> uintmax_t {
  switch (params.size()) {
    case 0:
      return 0;
    case 1:
      return params.front();
    default:
      return std::accumulate(params.cbegin(),
                             params.cend(),
                             1U,
                             std::lcm<uintmax_t, uintmax_t>);
  }
}

// static
auto Problem_1_3::BinaryLCM(const std::vector<uintmax_t>& params) -> uintmax_t {
  switch (params.size()) {
    case 0:
      return 0;
    case 1:
      return params.front();
    default:
      return std::accumulate(params.cbegin(),
                             params.cend(),
                             1U,
                             [](const uintmax_t u, const uintmax_t v) {
                               return u * v / Problem_1_2::BinaryGCD(u, v);
                             });
  }
}
