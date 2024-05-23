#include "../point.h"
#include "../segment.h"

namespace geometry {

Point::Point() : x_(0), y_(0) {}

Point::Point(int64_t x, int64_t y) : x_(x), y_(y) {}

Point::Point(const Point &point) : x_(point.GetX()), y_(point.GetY()) {}

Point::Point(const Vector &vector) : x_(vector.GetX()), y_(vector.GetX()) {}

bool Point::operator==(const Point &point) const {
  return (x_ == point.GetX()) && (y_ == point.GetY());
}

bool Point::operator!=(const Point &vector) const {
  return !(*this == vector);
}

Vector Point::operator-(const Point &point) const {
  Vector result = {x_ - point.GetX(), y_ - point.GetY()};
  return result;
}

void Point::SetX(const int64_t &value) {
  x_ = value;
}

void Point::SetY(const int64_t &value) {
  y_ = value;
}

int64_t Point::GetX() const {
  return x_;
}

int64_t Point::GetY() const {
  return y_;
}

IShape &Point::Move(const Vector &vector) {
  x_ += vector.GetX();
  y_ += vector.GetY();
  return *this;
}

bool Point::ContainsPoint(const Point &point) const {
  return point == *this;
}

bool Point::CrossesSegment(const Segment &segment) const {
  return segment.ContainsPoint(*this);
}

IShape *Point::Clone() const {
  IShape *it = new Point(*this);
  return it;
}

std::string Point::ToString() const {
  std::string text = "Point(";
  text += std::to_string(x_);
  text += ", ";
  text += std::to_string(y_);
  text += ')';
  return text;
}

std::ostream &operator<<(std::ostream &out, const Point &value) {
  out << value.ToString();
  return out;
}

std::istream &operator>>(std::istream &in, Point &value) {
  int64_t first_num, second_num;
  in >> first_num >> second_num;
  if (in) {
    value.SetX(first_num);
    value.SetY(second_num);
  }
  return in;
}

}