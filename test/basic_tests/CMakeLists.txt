include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(runBasicAutomataTests basic_check.cpp)

target_link_libraries(runBasicAutomataTests gtest gtest_main)
target_link_libraries(runBasicAutomataTests automata)