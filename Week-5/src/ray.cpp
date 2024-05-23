#include "../ray.h"
#include "../segment.h"

#include <vector>

namespace geometry {

Ray::Ray() : start_(Point()), end_(Point()), direction_(Vector()) {}

Ray::Ray(const Point &start, const Vector &direction) : start_(start), direction_(direction) {
  end_.SetX(start_.GetX() + direction_.GetX());
  end_.SetY(start_.GetY() + direction_.GetY());
}

Ray::Ray(const Point &start, const Point &end) : start_(start), end_(end), direction_(end - start) {}

Ray::Ray(const Ray &ray) : start_(ray.GetStart()), end_(ray.GetEnd()), direction_(ray.GetDirection()) {}

void Ray::SetStart(const Point &point) {
  start_ = point;
  end_.SetX(start_.GetX() + direction_.GetX());
  end_.SetY(start_.GetY() + direction_.GetY());
}

void Ray::SetEnd(const Point &point) {
  end_ = point;
  direction_ = end_ - start_;
}

void Ray::SetDirection(const Vector &vector) {
  direction_ = vector;
  end_.SetX(start_.GetX() + direction_.GetX());
  end_.SetY(start_.GetY() + direction_.GetY());
}

Point Ray::GetStart() const {
  return start_;
}

Point Ray::GetEnd() const {
  return end_;
}

Vector Ray::GetDirection() const {
  return direction_;
}

IShape &Ray::Move(const Vector &vector) {
  start_.SetX(start_.GetX() + vector.GetX());
  start_.SetY(start_.GetY() + vector.GetY());
  end_.SetX(end_.GetX() + vector.GetX());
  end_.SetY(end_.GetY() + vector.GetY());
  return *this;
}

bool Ray::ContainsPoint(const Point &point) const {
  Vector start(start_.GetX(), start_.GetY());
  Vector end(end_.GetX(), end_.GetY());
  Vector pt(point.GetX(), point.GetY());
  return CrossProduct(end - start, start - pt) == 0
      && DotProduct(end - start, start - pt) <= 0;
}

// Не уверен что работает
bool Ray::CrossesSegment(const Segment &segment) const {
  std::vector<int64_t> delta(4);
  delta[0] = (start_.GetX() - segment.GetStart().GetX()) / direction_.GetX() + 1;
  delta[1] = (start_.GetX() - segment.GetEnd().GetX()) / direction_.GetX() + 1;
  delta[2] = (start_.GetY() - segment.GetStart().GetY()) / direction_.GetY() + 1;
  delta[3] = (start_.GetY() - segment.GetEnd().GetY()) / direction_.GetY() + 1;

  int64_t maxi_plus = _abs64(*std::max_element(delta.begin(), delta.end()));
  int64_t maxi_minus = _abs64(*std::min_element(delta.begin(), delta.end()));

  Vector start(start_.GetX(), start_.GetY());
  Vector end(end_.GetX(), end_.GetY());
  Segment lineSegment = {Point(start + maxi_plus * direction_), Point(end + maxi_minus * direction_)};

  return segment.CrossesSegment(lineSegment);
}

IShape *Ray::Clone() const {
  IShape *it = new Ray(*this);
  return it;
}

std::string Ray::ToString() const {
  std::string text = "Ray(";
  text += start_.ToString();
  text += ", ";
  text += direction_.ToString();
  text += ')';
  return text;
}

std::ostream &operator<<(std::ostream &out, const Ray &value) {
  out << value.ToString();
  return out;
}

}