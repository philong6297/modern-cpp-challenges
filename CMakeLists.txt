cmake_minimum_required(VERSION 3.14 FATAL_ERROR)

# ---- Project ----
project(
  modern-cpp-challenges
  VERSION 1.0
  LANGUAGES CXX
)

# ---- Main Project check ----
# determine if this project is built as a subproject (using add_subdirectory) or
# if it is the main project
set(MAIN_PROJECT OFF)
if(CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR)
  set(MAIN_PROJECT ON)
endif()

set(LONGLP_PROJECT_DIR "${PROJECT_SOURCE_DIR}")
set(LONGLP_PROJECT_SRC_DIR "${LONGLP_PROJECT_DIR}/src")
set(LONGLP_PROJECT_BENCHMARK_DIR "${LONGLP_PROJECT_DIR}/benchmark")
set(LONGLP_PROJECT_OUTPUT_DIR "${PROJECT_BINARY_DIR}")
set(LONGLP_PROJECT_TEST_DIR "${LONGLP_PROJECT_DIR}/test")

# ---- Related tools ----
add_subdirectory(cmake)
longlp_desired_compile_features(LONGLP_DESIRED_COMPILE_FEATURES)
longlp_desired_compile_options(LONGLP_DESIRED_COMPILE_OPTIONS)

# ---- Options ----
option(ENABLE_TESTING "Build tests" ${MAIN_PROJECT})
option(ENABLE_BENCHMARK "Build benchmarks" ${MAIN_PROJECT})

# ---- Third parties ----
find_package(fmt REQUIRED)
if(ENABLE_BENCHMARK)
  find_package(benchmark REQUIRED)
endif()
if(ENABLE_TESTING)
  find_package(doctest REQUIRED)
endif()

add_subdirectory(${LONGLP_PROJECT_SRC_DIR})

# ---- Test ----
message("ENABLE_TESTING is ${ENABLE_TESTING}")
if(ENABLE_TESTING)
  include(CTest)
  enable_testing()
  add_subdirectory(${LONGLP_PROJECT_TEST_DIR})
endif()

# ---- Benchmark ----
message("ENABLE_BENCHMARK is ${ENABLE_BENCHMARK}")
if(ENABLE_BENCHMARK)
  add_subdirectory(${LONGLP_PROJECT_BENCHMARK_DIR})
endif()
