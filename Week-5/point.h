#ifndef POINT_H
#define POINT_H

#include "IShape.h"

class Geometry::Point : public Geometry::IShape {
 public:
  Point();
  Point(int64_t x, int64_t y);
  Point(const Geometry::Point &point);
  explicit Point(const Geometry::Vector& vector);

  Point& operator=(const Point& point);
  bool operator==(const Point &vector) const;
  bool operator!=(const Point &vector) const;

  [[nodiscard]] Vector GetVec() const;
  [[nodiscard]] IShape &Move(const Geometry::Vector &vector) override {
    point_ += vector;
    return *this;
  }
  [[nodiscard]] bool ContainsPoint(const Geometry::Point &point) const override;
  [[nodiscard]] bool CrossesSegment(const Geometry::Segment &segment) const override;
  [[nodiscard]] IShape *Clone() const override {
    IShape* it = new Point(*this);
    return it;
  }
  [[nodiscard]] std::string ToString() const override;

  friend std::ostream &operator<<(std::ostream &out, const Point &value);
  friend std::istream &operator>>(std::istream &in, Point &value);

 private:
  Vector point_;
};

#endif // POINT_H