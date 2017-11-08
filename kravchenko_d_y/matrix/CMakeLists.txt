cmake_minimum_required(VERSION 3.0) 
project(matrix) 
 
set(CMAKE_CXX_STANDARD 11) 
 
set(SOURCE_FILES matrix.h matrix.cpp matrix_test.cpp) 
add_executable(matrix ${SOURCE_FILES}) 
