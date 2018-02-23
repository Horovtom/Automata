cmake_minimum_required(VERSION 3.8)
project(Automata)

set(CMAKE_CXX_STANDARD 11)

add_executable(Automata main.cpp)

include_directories(src)

add_subdirectory(src)
add_subdirectory(test)

target_link_libraries(Automata automata)