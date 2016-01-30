set(GTEST_DIR ${CMAKE_SOURCE_DIR}/libs/googletest/googletest)

include_directories(SYSTEM ${GTEST_DIR}/include)
include_directories(${GTEST_DIR})

add_library(googletest ${GTEST_DIR}/src/gtest-all.cc)
