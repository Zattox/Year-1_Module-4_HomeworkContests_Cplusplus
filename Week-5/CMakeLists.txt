cmake_minimum_required(VERSION 3.27)
project(Week_5)

set(CMAKE_CXX_STANDARD 17)

add_executable(Geometry_main Geometry_main.cpp src/vector.cpp
               src/point.cpp src/segment.cpp src/line.cpp
               src/ray.cpp src/polygon.cpp src/circle.cpp)