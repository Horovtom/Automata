cmake_minimum_required(VERSION 3.8)
project(Automata)

set(CMAKE_CXX_STANDARD 11)

add_executable(Automata_driver main.cpp)

include_directories(src)
#include_directories(lib)

add_subdirectory(src)
add_subdirectory(test)

target_link_libraries(Automata_driver automata)