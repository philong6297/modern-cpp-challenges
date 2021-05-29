// Copyright 2021 Long Le Phi. All rights reserved.
// Use of this source code is governed by a MIT license that can be
// found in the LICENSE file.

#include <cassert>
#include <cstdint>
#include <limits>
#include <numeric>
#include "benchmark/benchmark.h"
#include "problems/1_1/solution.hpp"

namespace {
  using longlp::solution::Problem_1_1;
}   // namespace

auto main(int32_t argc, char** argv) -> int32_t {
  benchmark::RegisterBenchmark(
    "BM_Iteration_Branch",
    [](benchmark::State& state) {
      for ([[maybe_unused]] auto _ : state) {
        benchmark::DoNotOptimize(Problem_1_1::IterationWithBranches(
          static_cast<uintmax_t>(state.range())));
      }
    })
    ->RangeMultiplier(10)
    ->Range(100, 1'000'000)
    ->DisplayAggregatesOnly(true);

  benchmark::RegisterBenchmark(
    "BM_Iteration_Brach_no_branch",
    [](benchmark::State& state) {
      for ([[maybe_unused]] auto _ : state) {
        benchmark::DoNotOptimize(Problem_1_1::IterationWithNoBranches(
          static_cast<uintmax_t>(state.range())));
      }
    })
    ->RangeMultiplier(10)
    ->Range(100, 1'000'000)
    ->DisplayAggregatesOnly(true);

  benchmark::RegisterBenchmark(
    "BM_No_Iteration",
    [](benchmark::State& state) {
      for ([[maybe_unused]] auto _ : state) {
        benchmark::DoNotOptimize(
          Problem_1_1::UseFormula(static_cast<uintmax_t>(state.range())));
      }
    })
    ->RangeMultiplier(10)
    ->Range(100, 1'000'000)
    ->DisplayAggregatesOnly(true);

  benchmark::Initialize(&argc, argv);
  if (benchmark::ReportUnrecognizedArguments(argc, argv)) {
    return 1;
  }

  benchmark::RunSpecifiedBenchmarks();
}
