#ifndef VECTOR_H
#define VECTOR_H

#include "Geometry.h"

class Geometry::Vector {
 public:
  Vector();
  Vector(int64_t x, int64_t y);
  Vector(const Vector &vec);

  Vector& operator=(const Vector& vec);
  bool operator==(const Vector &vector) const;
  bool operator!=(const Vector &vector) const;

  void SetX(int64_t &value);
  void SetY(int64_t &value);
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
  friend Vector operator/(const int64_t &alpha, const Vector &vector);

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

#endif // VECTOR_H
