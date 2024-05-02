#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>
#include <cstdint>
#include <string>
#include <numeric>
#include <stdexcept>

class RationalDivisionByZero : public std::runtime_error {
 public:
  RationalDivisionByZero() : std::runtime_error("RationalDivisionByZero") {
  }
};

class Rational {
 public:
  Rational();
  Rational(const int &number); // NOLINT
  Rational(const int &numerator, const int &denominator);

  [[nodiscard]] int GetNumerator() const;
  [[nodiscard]] int GetDenominator() const;
  void SetNumerator(const int &number);
  void SetDenominator(const int &number);

  Rational operator+(const Rational &value) const;
  Rational operator-(const Rational &value) const;
  Rational operator*(const Rational &value) const;
  Rational operator/(const Rational &value) const;

  Rational &operator=(Rational value);
  Rational &operator+=(const Rational &value);
  Rational &operator-=(const Rational &value);
  Rational &operator*=(const Rational &value);
  Rational &operator/=(const Rational &value);

  Rational operator+() const;
  Rational operator-() const;

  Rational &operator++();
  Rational &operator--();
  const Rational operator++(int);
  const Rational operator--(int);

  bool operator==(const Rational &value) const;
  bool operator!=(const Rational &value) const;
  bool operator>(const Rational &value) const;
  bool operator<(const Rational &value) const;
  bool operator<=(const Rational &value) const;
  bool operator>=(const Rational &value) const;

  friend std::ostream &operator<<(std::ostream &out, const Rational &value);
  friend std::istream &operator>>(std::istream &in, Rational &value);

  void Reduction();
  void Update(Rational& fraction);

 private:
  int numerator_;
  int denominator_;
};

#endif //RATIONAL_H
