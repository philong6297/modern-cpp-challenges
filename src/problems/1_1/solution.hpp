

#ifndef PROBLEMS_1_1_SOLUTION_HPP_
#define PROBLEMS_1_1_SOLUTION_HPP_

#include <cstdint>

namespace longlp::solution {
  struct Problem_1_1 {
    static auto IterationWithBranches(uintmax_t upper_limit) -> uintmax_t;

    static auto IterationWithNoBranches(uintmax_t upper_limit) -> uintmax_t;

    static auto UseFormula(uintmax_t upper_limit) -> uintmax_t;
  };
}   // namespace longlp::solution

#endif   // PROBLEMS_1_1_SOLUTION_HPP_
