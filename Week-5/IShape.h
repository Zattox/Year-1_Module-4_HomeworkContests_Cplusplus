#ifndef ISHAPE_H
#define ISHAPE_H

#include <iostream>
#include <cstdint>
#include <cmath>
#include <algorithm>

namespace geometry {
class Segment;
class Vector;
class Point;

class IShape {
 public:
  [[nodiscard]] virtual IShape &Move(const Vector &vector) = 0;
  [[nodiscard]] virtual bool ContainsPoint(const Point &point) const = 0;
  [[nodiscard]] virtual bool CrossesSegment(const Segment &segment) const = 0;
  [[nodiscard]] virtual IShape *Clone() const = 0;
  [[nodiscard]] virtual std::string ToString() const = 0;
  virtual ~IShape() = default;
};

}  // namespace geometry

#endif  // ISHAPE_H
