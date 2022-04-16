cmake_minimum_required(VERSION 3.21)
project(MersenneTwisterClass)

set(CMAKE_CXX_STANDARD 20)

add_executable(MersenneTwisterClass main.cpp MersenneTwisterImplementation.cpp MersenneTwisterImplementation.h)
