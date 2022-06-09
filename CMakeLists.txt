cmake_minimum_required(VERSION 3.21)
project(FlashProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXE_LINKER_FLAGS "-static")

file(GLOB_RECURSE SOURCES RELATIVE ${CMAKE_SOURCE_DIR} "src/*.cpp")

include_directories(
        lib/gtest/googletest/include
        src
        include)
add_executable(FlashProject ${SOURCES}
        tests/tests.cpp
        src/generate_sequence.cpp
        )
add_subdirectory(lib/gtest)

target_link_libraries(FlashProject gtest gtest_main)

#add_subdirectory(lib/gtest)
#include_directories(lib/gtest/googletest/include src)
#target_link_libraries(FlashProject gtest gtest_main)