cmake_minimum_required(VERSION 3.0) 
project(rational) 
 
set(CMAKE_CXX_STANDARD 11) 
 
set(SOURCE_FILES rational.cpp rational_test.cpp rational.h) 
add_executable(rational ${SOURCE_FILES}) 
