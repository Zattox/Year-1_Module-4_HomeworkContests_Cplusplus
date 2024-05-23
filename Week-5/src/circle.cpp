#include "../circle.h"

namespace geometry {

Circle::Circle() : centre_(Point()), radius_(0) {
}

Circle::Circle(const Point &centre, const int64_t &radius) : centre_(centre), radius_(radius) {
}

Circle::Circle(const Circle &circle) : centre_(circle.GetCentre()), radius_(circle.GetRadius()) {
}

void Circle::SetCentre(const Point &point) {
  centre_ = point;
}

void Circle::SetRadius(const int64_t &radius) {
  radius_ = radius;
}

Point Circle::GetCentre() const {
  return centre_;
}

int64_t Circle::GetRadius() const {
  return radius_;
}

IShape &Circle::Move(const Vector &vector) {
  centre_.SetX(centre_.GetX() + vector.GetX());
  centre_.SetY(centre_.GetY() + vector.GetY());
  return *this;
}

bool Circle::ContainsPoint(const Point &point) const {
  Vector vector = point - centre_;
  return vector.Length() <= radius_;
}

bool Circle::CrossesSegment(const Segment &segment) const {
  Vector vector_start = segment.GetStart() - centre_;
  Vector vector_end = segment.GetEnd() - centre_;
  bool flag1 = ((vector_start.Length() <= radius_) && (vector_end.Length() >= radius_));
  bool flag2 = ((vector_start.Length() >= radius_) && (vector_end.Length() <= radius_));

  return flag1 || flag2;
}

IShape *Circle::Clone() const {
  IShape *it = new Circle(*this);
  return it;
}

std::string Circle::ToString() const {
  std::string text = "Circle(";
  text += centre_.ToString();
  text += ", ";
  text += std::to_string(radius_);
  text += ')';
  return text;
}

std::ostream &operator<<(std::ostream &out, const Circle &value) {
  out << value.ToString();
  return out;
}

}  // namespace geometry