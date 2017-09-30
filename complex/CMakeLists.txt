cmake_minimum_required(VERSION 3.0)
project(complex)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES complex.cpp complex_test.cpp complex.h)
add_executable(complex ${SOURCE_FILES})
