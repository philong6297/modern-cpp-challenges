add_library(1_2_solution OBJECT solution.hpp solution.cpp)
target_compile_options(1_2_solution PRIVATE ${LONGLP_DESIRED_COMPILE_OPTIONS})
target_compile_features(1_2_solution PRIVATE ${LONGLP_DESIRED_COMPILE_FEATURES})
target_include_directories(1_2_solution PRIVATE ${LONGLP_PROJECT_SRC_DIR})
