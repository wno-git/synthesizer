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

add_library(syn-generator
        generator.cc
        )
target_link_libraries(syn-generator
        syn-generator-sine
        )

add_library(syn-generator-sine
        generator_sine.cc
        )
target_link_libraries(syn-generator-sine
        syn-generator
        )

add_library(syn-generator-factory
        generator_factory.cc
        )
target_link_libraries(syn-generator-factory
        syn-generator
        syn-generator-sine
        )

add_library(syn-track
        track.cc
        )

target_link_libraries(syn-track
        syn-generator-factory
        )

target_link_libraries(syn-sequencer
        syn-noise
        syn-sine
        syn-track
        )

target_link_libraries(syn
        syn-track
        )
