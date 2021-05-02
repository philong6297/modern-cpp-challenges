cmake_minimum_required(VERSION 3.14 FATAL_ERROR)

# ---- Project ----
project(
  modern-cpp-challenges
  VERSION 1.0
  LANGUAGES CXX
)

set(LONGLP_PROJECT_DIR "${PROJECT_SOURCE_DIR}")
set(LONGLP_PROJECT_SRC_DIR "${LONGLP_PROJECT_DIR}/src")
set(LONGLP_PROJECT_EXTERNAL_DIR "${LONGLP_PROJECT_DIR}/external")
set(LONGLP_PROJECT_OUTPUT_DIR "${PROJECT_BINARY_DIR}")

# ---- Related tools ----
add_subdirectory(cmake)
longlp_desired_compile_features(LONGLP_DESIRED_COMPILE_FEATURES)
longlp_desired_compile_options(LONGLP_DESIRED_COMPILE_OPTIONS)

# ---- Third parties ----
find_package(fmt REQUIRED)
find_package(benchmark REQUIRED)

add_subdirectory(${LONGLP_PROJECT_SRC_DIR})
