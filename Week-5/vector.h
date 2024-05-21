#ifndef VECTOR_H
#define VECTOR_H

#include <cmath>

class RationalDivisionByZero : public std::runtime_error {
 public:
  RationalDivisionByZero() : std::runtime_error("RationalDivisionByZero") {
  }
};

class Vector {
 public:
  Vector();
  Vector(int64_t coor_x, int64_t coor_y);
  Vector(const Vector& vec);

  [[nodiscard]] int64_t GetX() const;
  [[nodiscard]] int64_t GetY() const;
  void SetX(int64_t &value);
  void SetY(int64_t &value);
  [[nodiscard]] long double Length() const;

 private:
  int64_t x_;
  int64_t y_;
};

Vector operator+(const Vector &vector);
Vector operator-(const Vector &vector);
Vector operator+(const Vector &vector1, const Vector &vector2);
Vector operator-(const Vector &vector1, const Vector &vector2);

Vector operator*(const Vector &vector, const int64_t &alpha);
Vector operator*(const int64_t &alpha, const Vector &vector);
Vector operator/(const Vector &vector, const int64_t &alpha);
Vector operator/(const int64_t &alpha, const Vector &vector);

Vector &operator+=(Vector &vector1, Vector &vector2);
Vector &operator-=(Vector &vector1, Vector &vector2);
Vector &operator*=(Vector &vector, int &alpha);
Vector &operator/=(Vector &vector, int &alpha);

bool operator==(const Vector &vector1, const Vector &vector2);
bool operator!=(const Vector &vector1, const Vector &vector2);

#endif // VECTOR_H
