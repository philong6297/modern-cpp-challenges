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
  for (uintmax_t i = 3; i < upper_limit; ++i) {
    if (i % 3 == 0 || i % 5 == 0) {
      sum += i;
    }
  }
  return sum;
}

// static
auto Problem_1_1::IterationWithNoBranches(const uintmax_t upper_limit)
  -> uintmax_t {
  uintmax_t sum{};
  for (uintmax_t i = 15; i < upper_limit; i += 15) {
    // sum += i;
    // sum += i - 5;
    // sum += i - 10;
    // sum += i - 3;
    // sum += i - 6;
    // sum += i - 12;
    // sum += i - 9;
    sum += i * 7 - 45;
  }
  return sum;
}

// static
auto Problem_1_1::UseFormula(const uintmax_t upper_limit) -> uintmax_t {
  const auto n = upper_limit / 15;
  return 15 * (7 * n * (n + 1) / 2 - 3 * n);
}
