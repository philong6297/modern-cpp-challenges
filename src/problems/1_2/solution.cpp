// Copyright 2021 Long Le Phi. All rights reserved.
// Use of this source code is governed by a MIT license that can be
// found in the LICENSE file.

#include "problems/1_2/solution.hpp"
#include <numeric>

#if defined(_MSC_VER)
#  include <intrin.h>
#endif

namespace {
  using longlp::solution::Problem_1_2;

  inline auto CountTrailingZeros(const uintmax_t u) -> uintmax_t {
#if defined(_MSC_VER)
    unsigned long trailing_zero = 0;

    if (_BitScanForward64(&trailing_zero, u) != 0U) {
      return trailing_zero;
    }

    // This is undefined, I better choose 64 than 0
    return 64;

#elif defined(__clang__) || defined(__GNUC__) || defined(__GNUG__)
    return __builtin_ctzll(u);
#endif
  }
}   // namespace

// static
auto Problem_1_2::StandardGCD(const uintmax_t u, const uintmax_t v)
  -> uintmax_t {
  return std::gcd(u, v);
}

// https://lemire.me/blog/2013/12/26/fastest-way-to-compute-the-greatest-common-divisor/
// static
auto Problem_1_2::BinaryGCD(uintmax_t u, uintmax_t v) -> uintmax_t {
  // Base cases: gcd(n, 0) = gcd(0, n) = n
  if (u == 0) {
    return v;
  }
  if (v == 0) {
    return u;
  }

  // Using identity 2: gcd(2u, 2v) = 2*gcd(u, v)
  // Using identity 3: gcd(2u, v) = gcd(u, v), if v is odd (2 is not a common
  // divisor). Similarly, gcd(u, 2v) = gcd(u, v) if u is odd.
  // gcd(u * 2^i, v * 2^j) = gcd(u, v) * 2^k with u, v odd and k = min(i, j).
  // 2^k is the greatest power of two that divides both u and v
  // The number of trailing 0-bits in x, starting at the least significant bit
  // position, represent for k.
  uintmax_t k = CountTrailingZeros(u | v);

  // Identity 3: gcd(u, v * 2^j) = gcd(u, v) (u is known to be odd)
  u >>= CountTrailingZeros(u);

  do {
    // Identity 3: gcd(u, v * 2^j) = gcd(u, v) (u is known to be odd)
    v >>= CountTrailingZeros(v);

    // swap to make sure u <= v
    if (u > v) {
      std::swap(u, v);
    }

    // Using identity 4 (gcd(u, v) = gcd(|v-u|, min(u, v))
    v = v - u;
  } while (v != 0);

  // Identity 1: gcd(u, 0) = u
  // The shift by k is necessary to add back the 2^k factor that was removed b
  // fore the loop
  return u << k;
}
