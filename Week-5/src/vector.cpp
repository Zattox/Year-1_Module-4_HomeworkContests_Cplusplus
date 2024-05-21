#include "../vector.h"

Vector::Vector() : orientation_(0, 0) {}

Vector::Vector(int x, int y) : orientation_(x, y) {}

Point Vector::GetOrientation() const {
  return orientation_;
}

void Vector::SetOrientation(const Point &value) {
  orientation_ = value;
}

std::ostream &operator<<(std::ostream &out, const Vector &value) {
  out << "Vector(" << value.GetOrientation().GetX() << ',' << value.GetOrientation().GetY() << ')';
  return out;
}

std::istream &operator>>(std::istream &in, Vector &value) {
  int x, y;
  in >> x >> y;
  if (in) {
    value.SetOrientation({x, y});
  }
  return in;
}

Vector operator+(const Vector &vector) {
  return vector;
}

Vector operator-(const Vector &vector) {
  Vector result = {-vector.GetOrientation().GetX(), -vector.GetOrientation().GetY()};
  return result;
}

Vector operator+(const Vector &vector1, const Vector &vector2) {
  Point p1 = vector1.GetOrientation();
  Point p2 = vector2.GetOrientation();
  Vector result = {p1.GetX() + p2.GetX(), p1.GetY() + p2.GetY()};
  return result;
}

Vector operator-(const Vector &vector1, const Vector &vector2) {
  Vector result = vector1 + (-vector2);
  return result;
}

Vector operator*(const Vector &vector, const int &alpha) {
  Vector result = {vector.GetOrientation().GetX() * alpha, vector.GetOrientation().GetY() * alpha};
  return result;
}
Vector operator/(const Vector &vector, const int &alpha) {
  if (alpha == 0) {
    throw RationalDivisionByZero();
  }
  Vector result = {vector.GetOrientation().GetX() / alpha, vector.GetOrientation().GetY() / alpha};
  return result;
}

Vector &operator+=(Vector &vector1, Vector &vector2) {
  Vector &result = vector1;
  result = result + vector2;
  return result;
}

Vector &operator-=(Vector &vector1, Vector &vector2) {
  Vector &result = vector1;
  result = result - vector2;
  return result;
}

Vector &operator*=(Vector &vector, int &alpha) {
  Vector &result = vector;
  result = result * alpha;
  return result;
}

Vector &operator/=(Vector &vector, int &alpha) {
  Vector &result = vector;
  result = result / alpha;
  return result;
}

bool operator==(const Vector &vector1, const Vector &vector2) {
  return vector1.GetOrientation() == vector2.GetOrientation();
}

bool operator!=(const Vector &vector1, const Vector &vector2) {
  return !(vector1 == vector2);
}