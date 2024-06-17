cmake_minimum_required(VERSION 3.27)
project(G_UnorderedSet)

set(CMAKE_CXX_STANDARD 20)

add_executable(G_UnorderedSet unordered_set_public_test.cpp)
add_executable(xz xz.cpp)