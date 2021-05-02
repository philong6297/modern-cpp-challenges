// Copyright 2021 Long Le Phi. All rights reserved.
// Use of this source code is governed by a MIT license that can be
// found in the LICENSE file.

#include <stdint.h>
#include <cstdint>
#include <limits>
#include <numeric>
#include "benchmark/benchmark.h"

static void BM_Iteration_Branch(benchmark::State& state) {
  for ([[maybe_unused]] auto _ : state) {
    uintmax_t sum    = 0;
    const auto range = static_cast<uintmax_t>(state.range());
    for (uintmax_t i = 3; i < range; ++i) {
      if (i % 3 == 0 || i % 5 == 0) {
        sum += i;
      }
    }
    benchmark::DoNotOptimize(sum);
  }
}

static void BM_Iteration_Branch_No_Branch(benchmark::State& state) {
  for ([[maybe_unused]] auto _ : state) {
    uintmax_t sum    = 0;
    const auto range = static_cast<uintmax_t>(state.range());
    for (uintmax_t i = 3; i < range; i += 3) {
      sum += i;
    }
    for (uintmax_t i = 5; i < range; i += 5) {
      sum += i;
    }
    for (uintmax_t i = 15; i < range; i += 15) {
      sum -= i;
    }
    benchmark::DoNotOptimize(sum);
  }
}

static void BM_No_Iteration(benchmark::State& state) {
  for ([[maybe_unused]] auto _ : state) {
    uintmax_t sum    = 0;
    const auto range = static_cast<uintmax_t>(state.range());
    sum += 3 * (range / 3) * (range / 3 + 1) / 2;
    sum += 5 * (range / 5) * (range / 5 + 1) / 2;
    sum -= 15 * (range / 15) * (range / 15 + 1) / 2;
    benchmark::DoNotOptimize(sum);
  }
}

BENCHMARK(BM_Iteration_Branch)
  ->RangeMultiplier(1000)
  ->Range(100, std::numeric_limits<int64_t>::max())
  ->DisplayAggregatesOnly(true);
BENCHMARK(BM_Iteration_Branch_No_Branch)
  ->RangeMultiplier(1000)
  ->Range(100, std::numeric_limits<int64_t>::max())
  ->DisplayAggregatesOnly(true);
BENCHMARK(BM_No_Iteration)
  ->RangeMultiplier(1000)
  ->Range(100, std::numeric_limits<int64_t>::max())
  ->DisplayAggregatesOnly(true);

BENCHMARK_MAIN();
