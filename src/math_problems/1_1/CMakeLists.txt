add_library(1_1_solution OBJECT solution.hpp solution.cpp)
target_compile_options(1_1_solution PRIVATE ${LONGLP_DESIRED_COMPILE_OPTIONS})
target_compile_features(1_1_solution PRIVATE ${LONGLP_DESIRED_COMPILE_FEATURES})
target_include_directories(1_1_solution PRIVATE ${LONGLP_PROJECT_SRC_DIR})

add_executable(1_1)
target_compile_options(1_1 PRIVATE ${LONGLP_DESIRED_COMPILE_OPTIONS})
target_compile_features(1_1 PRIVATE ${LONGLP_DESIRED_COMPILE_FEATURES})
target_include_directories(1_1 PRIVATE ${LONGLP_PROJECT_SRC_DIR})
target_link_libraries(1_1 PRIVATE 1_1_solution)
target_sources(1_1 PRIVATE main.cpp)
