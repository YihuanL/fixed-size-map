cmake_minimum_required(VERSION 2.8)

project(fixed_size_map_test LANGUAGES CXX)

include_directories(./src/)
include_directories(./test)
add_executable(fixed_size_map_test  test/test_fixed.cpp)