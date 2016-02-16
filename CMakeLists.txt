cmake_minimum_required(VERSION 2.6)

project(synthesizer)

enable_testing()

add_compile_options(
    -std=c++14
    -Wall
    -Wextra
    -pedantic
    -g
)

include_directories(inc)
include_directories(libs)
add_subdirectory(src)
add_subdirectory(test)
