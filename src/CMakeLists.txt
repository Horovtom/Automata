project(automata)

set(HEADER_FILES
        test.h
        )

set(SOURCE_FILES
        test.cpp
        )

add_library(automata STATIC ${SOURCE_FILES} ${HEADER_FILES})