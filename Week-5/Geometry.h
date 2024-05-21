#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <cmath>
#include <cstdint>
#include <iostream>

class RationalDivisionByZero : public std::runtime_error {
 public:
  RationalDivisionByZero() : std::runtime_error("RationalDivisionByZero") {
  }
};

namespace Geometry {
class Vector;
class IShape;
class Point;
class Segment;
class Ray;
class Line;
class Circle;
class Polygon;
}

#endif // GEOMETRY_H
