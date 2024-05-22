#include "../segment.h"

using namespace Geometry;

Segment::Segment() : start_(Point()), end_(Point()) {}

Segment::Segment(const Point& start, const Point& end) : start_(start), end_(end) {}

Segment::Segment(const Segment &segment) : start_(segment.GetStart()), end_(segment.end_) {}

bool Segment::operator==(const Segment &segment) const {
  bool flag1 = (start_ == segment.GetStart()) && (end_ == segment.GetEnd());
  bool flag2 = (start_ == segment.GetEnd()) && (end_ == segment.GetStart());
  return (flag1 || flag2);
}

bool Segment::operator!=(const Segment &segment) const {
  return !(*this == segment);
}

void Segment::SetStart(const Point &point) {
  start_ = point;
}

void Segment::SetEnd(const Point &point) {
  end_ = point;
}

Point Segment::GetStart() const {
  return start_;
}

Point Segment::GetEnd() const {
  return end_;
}

IShape &Segment::Move(const Vector &vector) {
  start_.SetX(start_.GetX() + vector.GetX());
  start_.SetY(start_.GetY() + vector.GetY());
  end_.SetX(end_.GetX() + vector.GetX());
  end_.SetY(end_.GetY() + vector.GetY());
  return *this;
}

bool Segment::ContainsPoint(const Point &point) const {
  return false;
}

bool Segment::CrossesSegment(const Segment &segment) const {
  return false;
}

IShape *Segment::Clone() const {
  IShape *it = new Segment(*this);
  return it;
}

std::string Segment::ToString() const {
  std::string text = "Segment(";
  text += start_.ToString();
  text += ',';
  text += end_.ToString();
  text += ')';
  return text;
}

std::ostream &operator<<(std::ostream &out, const Segment &value) {
  out << value.ToString();
  return out;
}