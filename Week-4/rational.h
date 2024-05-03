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

  friend std::ostream &operator<<(std::ostream &out, const Rational &value);
  friend std::istream &operator>>(std::istream &in, Rational &value);

  void Reduction();

 private:
  int numerator_;
  int denominator_;
};

Rational operator+(const Rational &fraction1, const Rational &fraction2);
Rational operator-(const Rational &fraction1, const Rational &fraction2);
Rational operator*(const Rational &fraction1, const Rational &fraction2);
Rational operator/(const Rational &fraction1, const Rational &fraction2);

Rational &operator+=(Rational &fraction1, const Rational &fraction2);
Rational &operator-=(Rational &fraction1, const Rational &fraction2);
Rational &operator*=(Rational &fraction1, const Rational &fraction2);
Rational &operator/=(Rational &fraction1, const Rational &fraction2);

Rational operator+(const Rational &fraction);
Rational operator-(const Rational &fraction);

Rational &operator++(Rational &fraction);
Rational &operator--(Rational &fraction);
const Rational operator++(Rational &fraction, int);
const Rational operator--(Rational &fraction, int);

bool operator==(const Rational &fraction1, const Rational &fraction2);
bool operator!=(const Rational &fraction1, const Rational &fraction2);
bool operator<(const Rational &fraction1, const Rational &fraction2);
bool operator>(const Rational &fraction1, const Rational &fraction2);
bool operator<=(const Rational &fraction1, const Rational &fraction2);
bool operator>=(const Rational &fraction1, const Rational &fraction2);

#endif //RATIONAL_H
