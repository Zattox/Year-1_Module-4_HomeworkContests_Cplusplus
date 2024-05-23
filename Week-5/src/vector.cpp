#include "../vector.h"

namespace geometry {

Vector::Vector() : x_(0), y_(0) {}

Vector::Vector(int64_t x, int64_t y) : x_(x), y_(y) {}

Vector::Vector(const Vector &vec) : x_(vec.GetX()), y_(vec.GetY()) {}

bool Vector::operator==(const Vector &vector) const {
  return (x_ == vector.GetX()) && (y_ == vector.GetY());
}

bool Vector::operator!=(const Vector &vector) const {
  return !(*this == vector);
}

int64_t Vector::GetX() const {
  return x_;
}

int64_t Vector::GetY() const {
  return y_;
}

void Vector::SetX(const int64_t &value) {
  x_ = value;
}

void Vector::SetY(const int64_t &value) {
  y_ = value;
}

long double Vector::Length() const {
  long double res = std::hypot(x_, y_);
  return res;
}

std::string Vector::ToString() const {
  std::string text = "Vector(";
  text += std::to_string(x_);
  text += ',';
  text += std::to_string(y_);
  text += ')';
  return text;
}

Vector Vector::operator+() const {
  return *this;
}

Vector Vector::operator-() const {
  Vector result = {-x_, -y_};
  return result;
}

Vector Vector::operator+(const Vector &vector) const {
  Vector result = {x_ + vector.GetX(), y_ + vector.GetY()};
  return result;
}

Vector Vector::operator-(const Vector &vector) const {
  Vector result = {x_ - vector.GetX(), y_ - vector.GetY()};
  return result;
}

Vector operator*(const Vector &vector, const int64_t &alpha) {
  Vector result = {vector.GetX() * alpha, vector.GetY() * alpha};
  return result;
}

Vector operator*(const int64_t &alpha, const Vector &vector) {
  Vector result = {vector.GetX() * alpha, vector.GetY() * alpha};
  return result;
}

Vector operator/(const Vector &vector, const int64_t &alpha) {
  if (alpha == 0) {
    throw std::runtime_error("RationalDivisionByZero");
  }
  Vector result = {vector.GetX() / alpha, vector.GetY() / alpha};
  return result;
}

Vector &Vector::operator+=(const Vector &vector) {
  x_ += vector.GetX();
  y_ += vector.GetY();
  return *this;
}

Vector &Vector::operator-=(const Vector &vector) {
  x_ -= vector.GetX();
  y_ -= vector.GetY();
  return *this;
}

Vector &Vector::operator*=(const int &alpha) {
  x_ *= alpha;
  y_ *= alpha;
  return *this;
}

Vector &Vector::operator/=(const int &alpha) {
  if (alpha == 0) {
    throw std::runtime_error("RationalDivisionByZero");
  }
  x_ /= alpha;
  y_ /= alpha;
  return *this;
}

std::ostream &operator<<(std::ostream &out, const Vector &value) {
  out << value.ToString();
  return out;
}

std::istream &operator>>(std::istream &in, Vector &value) {
  int64_t first_num, second_num;
  in >> first_num >> second_num;
  if (in) {
    value.SetX(first_num);
    value.SetY(second_num);
  }
  return in;
}

int64_t DotProduct(const Vector &v1, const Vector &v2) {
  return v1.GetX() * v2.GetX() + v1.GetY() * v2.GetY();
}

int64_t CrossProduct(const Vector &v1, const Vector &v2) {
  return v1.GetX() * v2.GetY() - v1.GetY() * v2.GetX();
}

}