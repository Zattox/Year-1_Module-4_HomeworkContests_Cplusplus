#ifndef SEGMENT_H
#define SEGMENT_H

#include "IShape.h"
#include "point.h"
#include "vector.h"

using namespace Geometry;

class Geometry::Segment : public Geometry::IShape {
 public:
  Segment();
  Segment(const Point &start, const Point &end);
  Segment(const Segment &segment);

  bool operator==(const Segment &segment) const;
  bool operator!=(const Segment &segment) const;

  void SetStart(const Point &point);
  void SetEnd(const Point &point);
  [[nodiscard]] Point GetStart() const;
  [[nodiscard]] Point GetEnd() const;

  [[nodiscard]] IShape &Move(const Vector &vector) override;
  [[nodiscard]] bool ContainsPoint(const Geometry::Point &point) const override;
  [[nodiscard]] bool CrossesSegment(const Geometry::Segment &segment) const override;
  [[nodiscard]] IShape *Clone() const override;
  [[nodiscard]] std::string ToString() const override;

  friend std::ostream &operator<<(std::ostream &out, const Segment &value);

 private:
  Point start_;
  Point end_;
};

#endif // SEGMENT_H
