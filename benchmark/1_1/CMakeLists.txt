add_executable(1_1_benchmark)
target_sources(1_1_benchmark PRIVATE main.cpp)
target_compile_options(1_1_benchmark PRIVATE ${LONGLP_DESIRED_COMPILE_OPTIONS})
target_compile_features(
  1_1_benchmark PRIVATE ${LONGLP_DESIRED_COMPILE_FEATURES}
)
target_include_directories(1_1_benchmark PRIVATE ${LONGLP_PROJECT_SRC_DIR})
target_link_libraries(
  1_1_benchmark PRIVATE benchmark::benchmark fmt::fmt 1_1_solution
)
