#ifndef CIRCLE_H
#define CIRCLE_H

#include "IShape.h"
#include "point.h"
#include "line.h"
#include "vector.h"

namespace geometry {

class Circle : public IShape {
 public:
  Circle();
  Circle(const Point &centre, const int64_t &radius);
  Circle(const Circle &circle);

  void SetCentre(const Point &point);
  void SetRadius(const int64_t &radius);
  [[nodiscard]] Point GetCentre() const;
  [[nodiscard]] int64_t GetRadius() const;

  [[nodiscard]] IShape &Move(const Vector &vector) override;
  [[nodiscard]] bool ContainsPoint(const Point &point) const override;
  [[nodiscard]] bool CrossesSegment(const Segment &segment) const override;
  [[nodiscard]] IShape *Clone() const override;
  [[nodiscard]] std::string ToString() const override;

  friend std::ostream &operator<<(std::ostream &out, const Circle &value);

 private:
  Point centre_;
  int64_t radius_;
};

}  // namespace geometry

#endif  // CIRCLE_H