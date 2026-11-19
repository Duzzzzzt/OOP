cmake_minimum_required(VERSION 3.14 FATAL_ERROR)

project(my_tests_proj VERSION 0.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/5376968f6948923e2411081fd9372e71a59d8e77.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(mytst_exec gtest.cpp)
target_link_libraries(mytst_exec PUBLIC GTest::gtest_main)
target_link_libraries(mytst_exec PUBLIC mylib)
target_include_directories(mytst_exec PUBLIC "${CMAKE_SOURCE_DIR}/my_lib")

include(GoogleTest)
gtest_discover_tests(mytst_exec)