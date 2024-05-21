#include "../vector.h"

using Geometry::Vector;

Geometry::Vector::Vector() {
  x_ = 0;
  y_ = 0;
}

Geometry::Vector::Vector(int64_t x, int64_t y) {
  x_ = x;
  y_ = y;
}

Geometry::Vector::Vector(const Vector &vec){
  x_ = vec.GetX();
  y_ = vec.GetY();
}

Vector& Vector::operator=(const Vector& vec) = default;

bool Geometry::Vector::operator==(const Vector &vector) const {
  return (x_ == vector.GetX()) && (y_ == vector.GetY());
}

bool Geometry::Vector::operator!=(const Vector &vector) const {
  return !(*this == vector);
}


int64_t Geometry::Vector::GetX() const {
  return x_;
}

int64_t Geometry::Vector::GetY() const {
  return y_;
}

void Geometry::Vector::SetX(int64_t &value) {
  x_ = value;
}

void Geometry::Vector::SetY(int64_t &value) {
  y_ = value;
}

long double Geometry::Vector::Length() const {
  long double res = std::hypot(x_, y_);
  return res;
}

std::string Geometry::Vector::ToString() const {
  std::string text = "Vector(";
  text += std::to_string(x_);
  text += ',';
  text += std::to_string(y_);
  text += ')';
  return text;
}

Vector Geometry::Vector::operator+() const {
  return *this;
}

Vector Geometry::Vector::operator-() const {
  Vector result = {-x_, -y_};
  return result;
}

Vector Geometry::Vector::operator+(const Vector &vector) const {
  Vector result = {x_ + vector.GetX(), y_ + vector.GetY()};
  return result;
}

Vector Geometry::Vector::operator-(const Vector &vector) const {
  Vector result = {x_ - vector.GetX(), y_ - vector.GetY()};
  return result;
}

Vector Geometry::operator*(const Vector &vector, const int64_t &alpha) {
  Vector result = {vector.GetX() * alpha, vector.GetY() * alpha};
  return result;
}

Vector Geometry::operator*(const int64_t &alpha, const Vector &vector) {
  Vector result = vector * alpha;
  return result;
}

Vector Geometry::operator/(const Vector &vector, const int64_t &alpha) {
  if (alpha == 0) {
    throw RationalDivisionByZero();
  }
  Vector result = {vector.GetX() / alpha, vector.GetY() / alpha};
  return result;
}

Vector Geometry::operator/(const int64_t &alpha, const Vector &vector) {
  Vector result = vector / alpha;
  return result;
}

Vector &Geometry::Vector::operator+=(const Vector &vector) {
  x_ += vector.GetX();
  y_ += vector.GetY();
  return *this;
}

Vector &Geometry::Vector::operator-=(const Vector &vector) {
  x_ -= vector.GetX();
  y_ -= vector.GetY();
  return *this;
}

Vector &Geometry::Vector::operator*=(const int &alpha) {
  x_ *= alpha;
  y_ *= alpha;
  return *this;
}

Vector &Geometry::Vector::operator/=(const int &alpha) {
  if (alpha == 0) {
    throw RationalDivisionByZero();
  }
  x_ /= alpha;
  y_ /= alpha;
  return *this;
}

std::ostream &Geometry::operator<<(std::ostream &out, const Vector &value) {
  out << value.ToString();
  return out;
}

std::istream &Geometry::operator>>(std::istream &in, Vector &value) {
  int64_t first_num, second_num;
  in >> first_num >> second_num;
  if (in) {
    value.SetX(first_num);
    value.SetY(second_num);
  }
  return in;
}
