cmake_minimum_required(VERSION 3.21)
project(FlashProject)

set(CMAKE_CXX_STANDARD 17)

add_executable(
        FlashProject main.cpp
        src/space_parting.cpp
        src/create_directories.cpp
        src/generate_uuid.cpp
        tests/tests.cpp
)

add_subdirectory(lib/gtest)

include_directories(lib/gtest/googletest/include src)
target_link_libraries(FlashProject gtest gtest_main)
