#include "../point.h"

Point::Point() : x_(0), y_(0) {}

Point::Point(int x, int y) : x_(x), y_(y) {}

int Point::GetX() const {
  return x_;
}

int Point::GetY() const {
  return y_;
}

void Point::SetX(const int &number) {
  x_ = number;
}

void Point::SetY(const int &number) {
  y_ = number;
}

std::ostream &operator<<(std::ostream &out, const Point &value) {
  out << "Point(" << value.GetX() << ',' << value.GetY() << ')';
  return out;
}

std::istream &operator>>(std::istream &in, Point &value) {
  int first_num, second_num;
  in >> first_num >> second_num;
  if (in) {
    value.SetX(first_num);
    value.SetY(second_num);
  }
  return in;
}

bool operator==(const Point &p1, const Point &p2) {
  return (p1.GetX() == p2.GetY()) && (p1.GetY() == p2.GetY());
}

bool operator!=(const Point &p1, const Point &p2) {
  return !(p1 == p2);
}
