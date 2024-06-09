cmake_minimum_required(VERSION 3.27)
project(C_Vector)

set(CMAKE_CXX_STANDARD 20)

add_executable(C_Vector vector_public_test.cpp)
add_executable(xz my_tests.cpp)
add_executable(xz2 xz2.cpp)