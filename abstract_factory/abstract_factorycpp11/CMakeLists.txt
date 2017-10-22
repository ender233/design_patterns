cmake_minimum_required(VERSION 3.8)
project(abstract_factorycpp11)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp shape.hpp shapeFactory.hpp)
add_executable(abstract_factorycpp11 ${SOURCE_FILES})