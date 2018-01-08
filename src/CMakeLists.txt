project(automata)

set(HEADER_FILES
        test.h
        Automaton.h
        )

set(SOURCE_FILES
        test.cpp
        Automaton.cpp)

add_library(automata STATIC ${SOURCE_FILES} ${HEADER_FILES})