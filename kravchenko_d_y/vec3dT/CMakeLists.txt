cmake_minimum_required(VERSION 3.0) 
project(vec3dT) 
 
set(CMAKE_CXX_STANDARD 11) 
 
set(SOURCE_FILES vec3dT.h vec3dT_test.cpp) 
add_executable(vec3dT ${SOURCE_FILES}) 