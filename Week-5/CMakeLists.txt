cmake_minimum_required(VERSION 3.27)
project(Week_5)

set(CMAKE_CXX_STANDARD 17)

add_executable(Geometry_main Geometry_main.cpp)
add_executable(point src/point.cpp)
add_executable(circle src/circle.cpp)
add_executable(line src/line.cpp)
add_executable(polygon src/polygon.cpp)
add_executable(ray src/ray.cpp)
add_executable(segment src/segment.cpp)
add_executable(vector src/vector.cpp)
