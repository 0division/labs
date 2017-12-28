cmake_minimum_required(VERSION 3.0) 
project(priorityqueuel) 
 
set(CMAKE_CXX_STANDARD 11) 
 
set(SOURCE_FILES priorityqueuel.h priorityqueuel.cpp priorityqueuel-test.cpp)
add_executable(priorityqueuel ${SOURCE_FILES}) 
