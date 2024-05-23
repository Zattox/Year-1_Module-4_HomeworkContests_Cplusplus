#include "../segment.h"
#include "../vector.h"

namespace geometry {

Segment::Segment() : start_(Point()), end_(Point()) {}

Segment::Segment(const Point &start, const Point &end) : start_(start), end_(end) {}

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
  Vector start(start_.GetX(), start_.GetY());
  Vector end(end_.GetX(), end_.GetY());
  Vector pt(point.GetX(), point.GetY());
  return CrossProduct(start - pt, end - pt) == 0
      && DotProduct(start - pt, end - pt) <= 0;
}

bool Segment::CrossesSegment(const Segment &segment) const {
  Vector start1(start_.GetX(), start_.GetY());
  Vector end1(end_.GetX(), end_.GetY());
  Vector start2(segment.GetStart().GetX(), segment.GetStart().GetY());
  Vector end2(segment.GetEnd().GetX(), segment.GetEnd().GetY());
  bool flag1 = CheckParallelism(start1.GetX(), end1.GetX(), start2.GetX(), end2.GetX());
  bool flag2 = CheckParallelism(start1.GetY(), end1.GetY(), start2.GetY(), end2.GetY());
  bool flag3 = (CrossProduct(start1 - end1, start1 - start2)
      * CrossProduct(start1 - end1, start1 - end2) <= 0);
  bool flag4 = (CrossProduct(start2 - end2, start2 - start1)
      * CrossProduct(start2 - end2, start2 - end1) <= 0);
  return flag1 && flag2 && flag3 && flag4;
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

bool CheckParallelism(int64_t a, int64_t b, int64_t c, int64_t d) {
  if (a > b)
    std::swap(a, b);
  if (c > d)
    std::swap(c, d);
  return std::max(a, c) <= std::min(b, d);
}

}