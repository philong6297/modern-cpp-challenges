// Copyright 2021 Long Le Phi. All rights reserved.
// Use of this source code is governed by a MIT license that can be
// found in the LICENSE file.

#include "problems/1_1/solution.hpp"
#include <algorithm>

namespace {
  using longlp::solution::Problem_1_1;
}   // namespace

// static
auto Problem_1_1::IterationWithBranches(const uintmax_t upper_limit)
  -> uintmax_t {
  uintmax_t sum{};
  for (uintmax_t i = 3; i <= upper_limit; ++i) {
    if (i % 3 == 0 || i % 5 == 0) {
      sum += i;
    }
  }
  return sum;
}

// static
auto Problem_1_1::IterationWithNoBranches(const uintmax_t upper_limit)
  -> uintmax_t {
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

// static
auto Problem_1_1::UseFormula(const uintmax_t upper_limit) -> uintmax_t {
  const auto n15 = upper_limit / 15;
  const auto n3  = upper_limit / 3;
  const auto n5  = upper_limit / 5;
  return (3 * n3 * (n3 + 1) + 5 * n5 * (n5 + 1) - 15 * n15 * (n15 + 1)) / 2;
}
