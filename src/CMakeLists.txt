set(CMAKE_CXX_FLAGS_LIST
        -std=c++11
        -Wall
        -Wextra
        -pedantic
        -g
   )

string(REPLACE ";" " "
       CMAKE_CXX_FLAGS
       "${CMAKE_CXX_FLAGS_LIST}")

add_library(syn-noise
        noise.cc
        )

add_library(syn-sine
        sine.cc
        )

add_executable(syn
        syn.cc
        )

target_link_libraries(syn
        syn-noise
        syn-sine
        )
