project(project_test)

add_executable(project_test)
target_compile_options(project_test PRIVATE ${LONGLP_DESIRED_COMPILE_OPTIONS})
target_compile_features(project_test PRIVATE ${LONGLP_DESIRED_COMPILE_FEATURES})
target_include_directories(project_test PRIVATE ${LONGLP_PROJECT_SRC_DIR})
target_link_libraries(
  project_test PRIVATE GTest::gtest nlohmann_json::nlohmann_json fmt::fmt
                       # target for each solution
)
target_sources(
  project_test PRIVATE main.cpp
                       # unittest for each solution
)

# ---- Discover tests ----
include(GoogleTest)
gtest_discover_tests(project_test)
