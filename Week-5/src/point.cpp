#include "../point.h"
#include "../vector.h"

using Geometry::Vector, Geometry::Point, Geometry::IShape;

Point::Point() : point_(0, 0) {}

Point::Point(int64_t x, int64_t y) : point_(x, y) {}

Point::Point(const Point &point) : point_(point.point_) {}

Point::Point(const Vector &vector) : point_(vector) {}

Point &Point::operator=(const Point &point) = default;

bool Point::operator==(const Point &vector) const {
  return (point_ == vector);
}

bool Point::operator!=(const Point &vector) const {
  return (point_ != vector);
}

Vector Point::GetVec() const {
  return point_;
}

bool Point::ContainsPoint(const Point &point) const {
  return point == *this;
}

bool Point::CrossesSegment(const Geometry::Segment &segment) const {
  return segment.ContainsPoint(*this);
}

std::string Point::ToString() const {
  std::string text = "Point(";
  text += std::to_string(point_.GetX());
  text += ',';
  text += std::to_string(point_.GetY());
  text += ')';
  return text;
}

std::ostream &Geometry::operator<<(std::ostream &out, const Point &value) {
  out << value.ToString();
  return out;
}

std::istream &Geometry::operator>>(std::istream &in, Point &value) {
  int64_t first_num, second_num;
  in >> first_num >> second_num;
  if (in) {
    value.point_.x_ = first_num;
    value.point_.y_ = second_num;
  }
  return in;
}

