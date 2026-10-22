cmake_minimum_required(VERSION 3.14 FATAL_ERROR)
project(mylib_proj VERSION 0.0.1 LANGUAGES CXX)

add_library(mylib INTERFACE)
target_include_directories(mylib INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})