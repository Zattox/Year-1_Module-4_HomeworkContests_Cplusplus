#include "../vector.h"

Vector::Vector() : x_(0), y_(0) {}

Vector::Vector(int64_t x, int64_t y) : x_(x), y_(y) {}

Vector::Vector(const Vector &vec) : x_(vec.GetX()), y_(vec.GetY()) {}

int64_t Vector::GetX() const {
  return x_;
}

int64_t Vector::GetY() const {
  return y_;
}

void Vector::SetX(int64_t &value) {
  x_ = value;
}

void Vector::SetY(int64_t &value) {
  y_ = value;
}

long double Vector::Length() const {
  long double res = std::hypot(x_, y_);
  return res;
}

std::ostream &operator<<(std::ostream &out, const Vector &value) {
  out << "Vector(" << value.GetX() << ',' << value.GetY() << ')';
  return out;
}

std::istream &operator>>(std::istream &in, Vector &value) {
  int64_t x, y;
  in >> x >> y;
  if (in) {
    value.SetX(x);
    value.SetY(y);
  }
  return in;
}

Vector operator+(const Vector &vector) {
  return vector;
}

Vector operator-(const Vector &vector) {
  Vector result = {-vector.GetX(), -vector.GetY()};
  return result;
}

Vector operator+(const Vector &vector1, const Vector &vector2) {
  Vector result = {vector1.GetX() + vector2.GetX(), vector1.GetY() + vector2.GetY()};
  return result;
}

Vector operator-(const Vector &vector1, const Vector &vector2) {
  Vector result = vector1 + (-vector2);
  return result;
}

Vector operator*(const Vector &vector, const int &alpha) {
  Vector result = {vector.GetX() * alpha, vector.GetY() * alpha};
  return result;
}

Vector operator*(const int &alpha, const Vector &vector){
  Vector result = vector * alpha;
  return result;
}

Vector operator/(const Vector &vector, const int &alpha) {
  if (alpha == 0) {
    throw RationalDivisionByZero();
  }
  Vector result = {vector.GetOrientation().GetX() / alpha, vector.GetOrientation().GetY() / alpha};
  return result;
}

Vector operator/(const int &alpha, const Vector &vector){
  Vector result = vector / alpha;
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
  return (vector1.GetX() == vector2.GetX()) && (vector1.GetY() == vector2.GetY());
}

bool operator!=(const Vector &vector1, const Vector &vector2) {
  return !(vector1 == vector2);
}