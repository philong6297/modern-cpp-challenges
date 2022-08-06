project(project_test)

add_executable(project_test)
target_compile_options(
  project_test PRIVATE ${LONGLP_DESIRED_COMPILE_OPTIONS}
                       -Wno-global-constructors
)
target_compile_features(project_test PRIVATE ${LONGLP_DESIRED_COMPILE_FEATURES})
target_include_directories(project_test PRIVATE ${LONGLP_PROJECT_SRC_DIR})
target_link_libraries(
  project_test
  PRIVATE Catch2::Catch2WithMain nlohmann_json::nlohmann_json fmt::fmt
          # target for each solution
          1_1_solution
)
target_sources(
  project_test PRIVATE # unittest for each solution
                       math_problems/1_1/solution_unittest.cpp
)
target_compile_definitions(project_test PUBLIC CATCH_CONFIG_FAST_COMPILE)

# ---- Discover tests ----
include(Catch)
include(CTest)
enable_testing()
catch_discover_tests(project_test)
