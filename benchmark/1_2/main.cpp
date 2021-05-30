// Copyright 2021 Long Le Phi. All rights reserved.
// Use of this source code is governed by a MIT license that can be
// found in the LICENSE file.

#include <cassert>
#include <cstdint>
#include <vector>
#include "benchmark/benchmark.h"
#include "problems/1_2/solution.hpp"
namespace {
  using longlp::solution::Problem_1_2;

  void CustomArguments(benchmark::internal::Benchmark* b) {
    // 100 unique numbers in [100,1000000] range
    std::vector<int64_t> args = {
      33265,  52240,  70226,  72655,  75056,  76592,  76990,  101631, 103946,
      111541, 116091, 121432, 127485, 128538, 131970, 143497, 143711, 146871,
      147444, 151721, 158244, 168089, 200456, 201968, 214702, 237702, 267224,
      274432, 274596, 276108, 288273, 307144, 310873, 312869, 325934, 349126,
      360765, 390742, 407899, 409900, 412281, 424231, 425123, 431974, 440659,
      459001, 465881, 484181, 496895, 500871, 501524, 512303, 512589, 521984,
      564632, 574813, 576067, 584891, 596110, 614651, 626787, 635533, 651651,
      653177, 657113, 663085, 663957, 697213, 711466, 718613, 739409, 749205,
      765166, 786364, 800969, 804677, 811668, 816401, 820501, 824884, 829585,
      845396, 858908, 892657, 895270, 914305, 922148, 930288, 935247, 940446,
      940655, 943932, 944170, 944796, 945002, 950400, 966563, 970709, 978004,
      990574};
    for (size_t i = 0; i < args.size(); i += 2) {
      b->Args({args[i], args[i + 1]});
    }
  }
}   // namespace

auto main(int32_t argc, char** argv) -> int32_t {
  benchmark::RegisterBenchmark(
    "BM_StandardGCD",
    [](benchmark::State& state) {
      for ([[maybe_unused]] auto _ : state) {
        benchmark::DoNotOptimize(
          Problem_1_2::StandardGCD(static_cast<uintmax_t>(state.range(0)),
                                   static_cast<uintmax_t>(state.range(1))));
      }
    })
    ->Apply(CustomArguments)
    ->DisplayAggregatesOnly(true);

  benchmark::RegisterBenchmark(
    "BM_BinaryGCD",
    [](benchmark::State& state) {
      for ([[maybe_unused]] auto _ : state) {
        benchmark::DoNotOptimize(
          Problem_1_2::BinaryGCD(static_cast<uintmax_t>(state.range(0)),
                                 static_cast<uintmax_t>(state.range(1))));
      }
    })
    ->Apply(CustomArguments)
    ->DisplayAggregatesOnly(true);

  benchmark::Initialize(&argc, argv);
  if (benchmark::ReportUnrecognizedArguments(argc, argv)) {
    return 1;
  }

  benchmark::RunSpecifiedBenchmarks();
}
