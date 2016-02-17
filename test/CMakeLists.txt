set(GTEST_DIR ${CMAKE_SOURCE_DIR}/libs/googletest/googletest)

include_directories(SYSTEM ${GTEST_DIR}/include)
include_directories(${GTEST_DIR})

add_library(googletest ${GTEST_DIR}/src/gtest-all.cc)
add_library(googletest_main ${GTEST_DIR}/src/gtest_main.cc)

add_executable(unit_track unit_track.cc)
target_link_libraries(unit_track
    googletest
    googletest_main
    pthread
    syn-track)
add_test(unit_track unit_track)

add_executable(integration_track integration_track.cc)
target_link_libraries(integration_track
    googletest
    googletest_main
    pthread
    syn-track)
add_test(integration_track integration_track)

add_executable(unit_generator unit_generator.cc)
target_link_libraries(unit_generator
    googletest
    googletest_main
    pthread
    syn-generator
    syn-generator-sine)
add_test(unit_generator unit_generator)

add_executable(unit_generator_sine unit_generator_sine.cc)
target_link_libraries(unit_generator_sine
    googletest
    googletest_main
    pthread
    syn-generator
    syn-generator-sine)
add_test(unit_generator_sine unit_generator_sine)

add_executable(integration_generator_factory integration_generator_factory.cc)
target_link_libraries(integration_generator_factory
    googletest
    googletest_main
    pthread
    syn-generator
    syn-generator-factory
    syn-generator-sine)
add_test(integration_generator_factory integration_generator_factory)
