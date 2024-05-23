#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <cstdint>
#include <cmath>
#include <algorithm>

namespace geometry {

class Vector {
 public:
  Vector();
  Vector(int64_t x, int64_t y);
  Vector(const Vector &vec);

  bool operator==(const Vector &vector) const;
  bool operator!=(const Vector &vector) const;

  void SetX(const int64_t &value);
  void SetY(const int64_t &value);
  [[nodiscard]] int64_t GetX() const;
  [[nodiscard]] int64_t GetY() const;
  [[nodiscard]] long double Length() const;
  [[nodiscard]] std::string ToString() const;

  Vector operator+() const;
  Vector operator-() const;
  Vector operator+(const Vector &vector) const;
  Vector operator-(const Vector &vector) const;

  friend Vector operator*(const Vector &vector, const int64_t &alpha);
  friend Vector operator*(const int64_t &alpha, const Vector &vector);
  friend Vector operator/(const Vector &vector, const int64_t &alpha);

  Vector &operator+=(const Vector &vector);
  Vector &operator-=(const Vector &vector);
  Vector &operator*=(const int &alpha);
  Vector &operator/=(const int &alpha);

  friend std::ostream &operator<<(std::ostream &out, const Vector &value);
  friend std::istream &operator>>(std::istream &in, Vector &value);

 private:
  int64_t x_;
  int64_t y_;
};

int64_t DotProduct(const Vector &v1, const Vector &v2);
int64_t CrossProduct(const Vector &v1, const Vector &v2);

}  // namespace geometry

#endif  // VECTOR_H
