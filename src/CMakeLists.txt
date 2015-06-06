set(CMAKE_CXX_FLAGS_LIST
        -std=c++14
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

add_library(syn-sequencer
        sequencer.cc
        )

target_link_libraries(syn-sequencer
        syn-noise
        syn-sine
        )

target_link_libraries(syn
        syn-sequencer
        )
