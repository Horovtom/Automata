include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(TEST_SOURCES
        dfa_definitions_test.cpp)

set(TEST_ASSETS
        interactive_DFA_string.txt
        interactive_DFA_int.txt)

add_executable(run_dfa_tests ${TEST_SOURCES})

foreach (asset ${TEST_ASSETS})
    set(CURR
            "${CMAKE_CURRENT_SOURCE_DIR}/${asset}")
    set(TAR
            "${CMAKE_CURRENT_BINARY_DIR}/${asset}")

    add_custom_command(
            TARGET run_dfa_tests
            COMMAND ${CMAKE_COMMAND}
            -E copy ${CURR}
            ${TAR}
            DEPENDS ${CURR}
    )
endforeach ()

##interactive_DFA_string.txt
#add_custom_command(
#        TARGET run_dfa_tests
#        COMMAND ${CMAKE_COMMAND}
#        -E copy ${CMAKE_CURRENT_SOURCE_DIR}/interactive_DFA_string.txt
#        ${CMAKE_CURRENT_BINARY_DIR}/interactive_DFA_string.txt
#        DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/interactive_DFA_string.txt
#)
##interactive_DFA_int.txt
#add_custom_command(
#        TARGET run_dfa_tests
#        COMMAND ${CMAKE_COMMAND}
#        -E copy ${CMAKE_CURRENT_SOURCE_DIR}/interactive_DFA_int.txt
#        ${CMAKE_CURRENT_BINARY_DIR}/interactive_DFA_int.txt
#        DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/interactive_DFA_int.txt
#)

target_link_libraries(run_dfa_tests gtest gtest_main)
target_link_libraries(run_dfa_tests automata)
