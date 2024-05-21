#ifndef VECTOR_H
#define VECTOR_H

#include "point.h"

class RationalDivisionByZero : public std::runtime_error {
 public:
  RationalDivisionByZero() : std::runtime_error("RationalDivisionByZero") {
  }
};

class Vector {
 private:
  Point orientation_;
 public:
  Vector();
  Vector(int x, int y);
  [[nodiscard]] Point GetOrientation() const;
  void SetOrientation(const Point &value);

  friend std::ostream &operator<<(std::ostream &out, const Vector &value);
  friend std::istream &operator>>(std::istream &in, Vector &value);
};

Vector operator+(const Vector &vector);
Vector operator-(const Vector &vector);

Vector operator+(const Vector &vector1, const Vector &vector2);
Vector operator-(const Vector &vector1, const Vector &vector2);
Vector operator*(const Vector &vector, const int &alpha);
Vector operator/(const Vector &vector, const int &alpha);

Vector &operator+=(Vector &vector1, Vector &vector2);
Vector &operator-=(Vector &vector1, Vector &vector2);
Vector &operator*=(Vector &vector, int &alpha);
Vector &operator/=(Vector &vector, int &alpha);

bool operator==(const Vector &vector1, const Vector &vector2);
bool operator!=(const Vector &vector1, const Vector &vector2);

#endif // VECTOR_H
