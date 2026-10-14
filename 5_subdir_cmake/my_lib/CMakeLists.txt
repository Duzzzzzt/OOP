cmake_minimum_required(VERSION 3.14 FATAL_ERROR)

project(mylib_proj VERSION 0.0.1 LANGUAGES CXX)

add_library(mylib STATIC add.h add.cpp)