// Copyright 2021 Long Le Phi. All rights reserved.
// Use of this source code is governed by a MIT license that can be
// found in the LICENSE file.

#include <cstdint>

#include <gtest/gtest.h>

auto main(int32_t argc, char** argv) -> int32_t {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
