project(automata)

set(HEADER_FILES
        test.h
        Automaton.h
        DFAAutomaton.h
        util.h)

set(SOURCE_FILES
        test.cpp
        Automaton.cpp
        DFAAutomaton.cpp
        util.cpp)

#add_library(automata STATIC ${SOURCE_FILES} ${HEADER_FILES})

add_library(automata ${SOURCE_FILES} ${HEADER_FILES})

target_include_directories(Automata PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})