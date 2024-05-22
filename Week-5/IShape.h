#ifndef ISHAPE_H
#define ISHAPE_H

#include "Geometry.h"
#include <memory>

class Geometry::IShape {
 public:
  [[nodiscard]] virtual IShape &Move(const Geometry::Vector &vector) = 0;
  [[nodiscard]] virtual bool ContainsPoint(const Geometry::Point &point) const = 0;
  //[[nodiscard]] virtual bool CrossesSegment(const Geometry::Segment &segment) const = 0;
  [[nodiscard]] virtual IShape *Clone() const = 0;
  [[nodiscard]] virtual std::string ToString() const = 0;
  virtual ~IShape() = default;
};

#endif // ISHAPE_H
