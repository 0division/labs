cmake_minimum_required(VERSION 3.0) 
project(kvaternion) 
 
set(CMAKE_CXX_STANDARD 11) 
 
set(SOURCE_FILES kvaternion.cpp kvaternion_test.cpp kvaternion.h) 
add_executable(kvaternion ${SOURCE_FILES}) 