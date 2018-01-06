cmake_minimum_required(VERSION 3.2)
project(traffic_sign_marker)
set(CMAKE_CXX_STANDARD 11) 
set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set (CMAKE_PREFIX_PATH "/home/user/Qt5.5.1/5.5/gcc_64") #enter path to your Qt install directory here
find_package(Qt5Widgets REQUIRED)

add_executable(traffic_sign_marker main.cpp userinterface.cpp userinterface.h figureitem.h figureitem.cpp userinterface.ui ui_userinterface.h)
qt5_use_modules(traffic_sign_marker Core Gui Widgets)
