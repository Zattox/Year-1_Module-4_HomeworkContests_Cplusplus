#include "../polygon.h"
#include "../segment.h"

namespace geometry {

Polygon::Polygon() : points_(std::vector<Point>(0)), size_(0) {}

Polygon::Polygon(const std::vector<Point> &arr) : points_(arr), size_(arr.size()){}

Polygon::Polygon(const Polygon &polygon) : points_(polygon.GetPoints()), size_(polygon.GetSize()){}

void Polygon::SetPoints(const std::vector<Point> &arr) {
  points_ = arr;
  size_ = arr.size();
}

size_t Polygon::GetSize() const {
  return size_;
}

std::vector<Point> Polygon::GetPoints() const {
  return points_;
}

IShape &Polygon::Move(const Vector &vector) {
  for (auto &point : points_) {
    point.SetX(point.GetX() + vector.GetX());
    point.SetY(point.GetY() + vector.GetY());
  }
  return *this;
}

bool Polygon::ContainsPoint(const Point &point) const {
  for (int i = 0; i < size_; ++i) {
    Segment segment = {points_[i], points_[(i + 1) % size_]};
    if (segment.ContainsPoint(point)) {
      return true;
    }
  }

  long double sum = 0;
  for (int i = 0; i < size_; ++i) {
    sum += Angle(points_[i] - point, points_[(i + 1) % size_] - point);
  }

  long double eps = 1e-6;
  if (fabsl(sum) < eps) {
    return false;
  }
  return true;
}

bool Polygon::CrossesSegment(const Segment &segment) const {
  for (int i = 0; i < size_; ++i) {
    Segment edge = {points_[i], points_[(i + 1) % size_]};
    if (segment.CrossesSegment(edge)) {
      return true;
    }
  }
  return false;
}

IShape *Polygon::Clone() const {
  IShape *it = new Polygon(*this);
  return it;
}

std::string Polygon::ToString() const {
  std::string text = "Polygon(";
  for (auto &el : points_) {
    text += el.ToString();
    text += ", ";
  }
  text.pop_back();
  text.pop_back();
  text += ')';
  return text;
}

std::ostream &operator<<(std::ostream &out, const Polygon &value) {
  out << value.ToString();
  return out;
}

long double Angle(const Vector& point1, const Vector& point2) {
  return atan2l(CrossProduct(point1, point2), DotProduct(point1, point2));
}

}