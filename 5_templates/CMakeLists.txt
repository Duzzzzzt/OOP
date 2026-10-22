cmake_minimum_required(VERSION 3.14 FATAL_ERROR)

project(lab5_proj VERSION 0.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(my_lib)

option(BUILD_TESTS "Build unit tests" ON)

if(BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
else()
    message(STATUS "building without tests")
endif()

add_executable(exec_trg main.cpp)

target_link_libraries(exec_trg PUBLIC mylib)

