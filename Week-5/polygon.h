#ifndef POLYGON_H
#define POLYGON_H

#include "IShape.h"
#include "point.h"
#include "vector.h"
#include <vector>

namespace geometry {

class Polygon : public IShape {
 public:
  Polygon();
  Polygon(const std::vector<Point> &arr);
  Polygon(const Polygon &polygon);

  void SetPoints(const std::vector<Point> &arr);
  [[nodiscard]] size_t GetSize() const;
  [[nodiscard]] std::vector<Point> GetPoints() const;

  [[nodiscard]] IShape &Move(const Vector &vector) override;
  [[nodiscard]] bool ContainsPoint(const Point &point) const override;
  [[nodiscard]] bool CrossesSegment(const Segment &segment) const override;
  [[nodiscard]] IShape *Clone() const override;
  [[nodiscard]] std::string ToString() const override;

  friend std::ostream &operator<<(std::ostream &out, const Polygon &value);

 private:
  std::vector<Point> points_;
  size_t size_;
};

long double Angle(const Vector& point1, const Vector& point2);

}

#endif // POLYGON_H
