cmake_minimum_required(VERSION 3.21)
project(FlashProject)

set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE SOURCES RELATIVE ${CMAKE_SOURCE_DIR} "src/*.cpp")

include_directories(include)
add_executable(FlashProject ${SOURCES})

#add_subdirectory(lib/gtest)
#include_directories(lib/gtest/googletest/include src)
#target_link_libraries(FlashProject gtest gtest_main)