cmake_minimum_required(VERSION 3.0)
project(stackl)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES stackl.h stackl.cpp stack_test.cpp)
add_executable(stackl ${SOURCE_FILES})
