include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(TEST_SOURCES
        manual_DFA.cpp)

add_executable(run_definitions_tests ${TEST_SOURCES})

target_link_libraries(run_definitions_tests gtest gtest_main)
target_link_libraries(run_definitions_tests automata)