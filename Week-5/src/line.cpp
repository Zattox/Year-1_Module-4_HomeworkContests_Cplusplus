#include "../line.h"
#include <vector>

namespace geometry {

Line::Line() : start_(Point()), end_(Point()) {
}

Line::Line(const Point &start, const Point &end) : start_(start), end_(end) {
}

Line::Line(const Line &line) : start_(line.GetStart()), end_(line.GetEnd()) {
}

void Line::SetStart(const Point &point) {
  start_ = point;
}

void Line::SetEnd(const Point &point) {
  end_ = point;
}

Point Line::GetStart() const {
  return start_;
}

Point Line::GetEnd() const {
  return end_;
}

int64_t Line::GetA() const {
  Vector start(start_.GetX(), start_.GetY());
  Vector end(end_.GetX(), end_.GetY());
  Vector result = end - start;
  return result.GetY();
}

int64_t Line::GetB() const {
  Vector start(start_.GetX(), start_.GetY());
  Vector end(end_.GetX(), end_.GetY());
  Vector result = start - end;
  return result.GetX();
}

int64_t Line::GetC() const {
  int64_t result = start_.GetY() * end_.GetX() - start_.GetX() * end_.GetY();
  return result;
}

IShape &Line::Move(const Vector &vector) {
  start_.SetX(start_.GetX() + vector.GetX());
  start_.SetY(start_.GetY() + vector.GetY());
  end_.SetX(end_.GetX() + vector.GetX());
  end_.SetY(end_.GetY() + vector.GetY());
  return *this;
}

bool Line::ContainsPoint(const Point &point) const {
  Vector start(start_.GetX(), start_.GetY());
  Vector end(end_.GetX(), end_.GetY());
  Vector pt(point.GetX(), point.GetY());
  return CrossProduct(start - pt, end - pt) == 0;
}

bool Line::CrossesSegment(const Segment &segment) const {
  Vector direction = end_ - start_;

  std::vector<int64_t> delta(8, 0);

  if (direction.GetX() != 0) {
    delta[0] = (start_.GetX() - segment.GetStart().GetX()) / direction.GetX();
    delta[1] = (start_.GetX() - segment.GetEnd().GetX()) / direction.GetX();
    delta[4] = (end_.GetX() - segment.GetStart().GetX()) / direction.GetX();
    delta[5] = (end_.GetX() - segment.GetEnd().GetX()) / direction.GetX();
  }
  if (direction.GetY() != 0) {
    delta[2] = (start_.GetY() - segment.GetStart().GetY()) / direction.GetY();
    delta[3] = (start_.GetY() - segment.GetEnd().GetY()) / direction.GetY();
    delta[6] = (end_.GetY() - segment.GetStart().GetY()) / direction.GetY();
    delta[7] = (end_.GetY() - segment.GetEnd().GetY()) / direction.GetY();
  }

  int64_t maxi_plus = llabs(*std::max_element(delta.begin(), delta.end())) + 1;
  int64_t maxi_minus = llabs(*std::min_element(delta.begin(), delta.end())) - 1;

  Vector start(start_.GetX(), start_.GetY());
  Vector end(end_.GetX(), end_.GetY());
  Segment lineSegment1 = {Point(start - maxi_minus * direction), Point(end + maxi_plus * direction)};
  Segment lineSegment2 = {Point(start + maxi_plus * direction), Point(end - maxi_minus * direction)};

  return segment.CrossesSegment(lineSegment1) || segment.CrossesSegment(lineSegment2);
}

IShape *Line::Clone() const {
  IShape *it = new Line(*this);
  return it;
}

std::string Line::ToString() const {
  std::string text = "Line(";
  text += std::to_string(GetA());
  text += ", ";
  text += std::to_string(GetB());
  text += ", ";
  text += std::to_string(GetC());
  text += ')';
  return text;
}

std::ostream &operator<<(std::ostream &out, const Line &value) {
  out << value.ToString();
  return out;
}

}  // namespace geometry