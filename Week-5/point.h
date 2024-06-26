#ifndef POINT_H
#define POINT_H

#include "IShape.h"
#include "vector.h"

namespace geometry {

class Point : public IShape {
 public:
  Point();
  Point(int64_t x, int64_t y);
  Point(const Point &point);
  explicit Point(const Vector &vector);

  bool operator==(const Point &vector) const;
  bool operator!=(const Point &vector) const;
  Vector operator-(const Point &point) const;

  void SetX(const int64_t &value);
  void SetY(const int64_t &value);
  [[nodiscard]] int64_t GetX() const;
  [[nodiscard]] int64_t GetY() const;

  [[nodiscard]] IShape &Move(const Vector &vector) override;
  [[nodiscard]] bool ContainsPoint(const Point &point) const override;
  [[nodiscard]] bool CrossesSegment(const Segment &segment) const override;
  [[nodiscard]] IShape *Clone() const override;
  [[nodiscard]] std::string ToString() const override;

  friend std::ostream &operator<<(std::ostream &out, const Point &value);
  friend std::istream &operator>>(std::istream &in, Point &value);

 private:
  int64_t x_;
  int64_t y_;
};

}  // namespace geometry

#endif  // POINT_H