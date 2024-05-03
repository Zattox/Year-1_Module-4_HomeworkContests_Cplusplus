#include "rational.h"

Rational::Rational() {
  numerator_ = 0;
  denominator_ = 1;
}

Rational::Rational(const int &number) {
  numerator_ = number;
  denominator_ = 1;
}

Rational::Rational(const int &numerator, const int &denominator) {
  numerator_ = numerator;
  denominator_ = denominator;
  Reduction();
}

int Rational::GetNumerator() const {
  return numerator_;
}

int Rational::GetDenominator() const {
  return denominator_;
}

void Rational::SetNumerator(const int &number) {
  numerator_ = number;
  Reduction();
}

void Rational::SetDenominator(const int &number) {
  denominator_ = number;
  Reduction();
}

std::ostream &operator<<(std::ostream &out, const Rational &value) {
  if (value.GetDenominator() != 1) {
    out << value.GetNumerator() << '/' << value.GetDenominator();
  } else {
    out << value.GetNumerator();
  }
  return out;
}

std::istream &operator>>(std::istream &in, Rational &value) {
  std::string data;
  in >> data;

  if (in) {
    std::string string_numerator;
    size_t ind = 0;
    while (ind < data.size() && data[ind] != '/') {
      string_numerator.push_back(data[ind]);
      ++ind;
    }
    ++ind;

    std::string string_denominator;
    while (ind < data.size()) {
      string_denominator.push_back(data[ind]);
      ++ind;
    }

    if (string_denominator.empty()) {
      string_denominator = "1";
    }

    if (!string_numerator.empty() && !string_denominator.empty()) {
      int num = atoi(string_numerator.c_str());
      int den = atoi(string_denominator.c_str());
      Rational fraction(num, den);
      fraction.Reduction();

      value = fraction;
    }
  }
  return in;
}

void Rational::Reduction() {
  if (denominator_ == 0) {
    throw RationalDivisionByZero();
  }
  if (denominator_ < 0) {
    numerator_ = -numerator_;
    denominator_ = -denominator_;
  }

  int gcd = std::gcd(numerator_, denominator_);
  numerator_ /= gcd;
  denominator_ /= gcd;
}

Rational operator+(const Rational &fraction1, const Rational &fraction2) {
  int res_numerator =
      fraction1.GetNumerator() * fraction2.GetDenominator() + fraction2.GetNumerator() * fraction1.GetDenominator();
  int res_denominator = fraction1.GetDenominator() * fraction2.GetDenominator();
  Rational result = {res_numerator, res_denominator};
  result.Reduction();
  return result;
}

Rational operator-(const Rational &fraction1, const Rational &fraction2) {
  int res_numerator =
      fraction1.GetNumerator() * fraction2.GetDenominator() - fraction2.GetNumerator() * fraction1.GetDenominator();
  int res_denominator = fraction1.GetDenominator() * fraction2.GetDenominator();
  Rational result = {res_numerator, res_denominator};
  result.Reduction();
  return result;
}

Rational operator*(const Rational &fraction1, const Rational &fraction2) {
  int res_numerator = fraction1.GetNumerator() * fraction2.GetNumerator();
  int res_denominator = fraction1.GetDenominator() * fraction2.GetDenominator();
  Rational result = {res_numerator, res_denominator};
  result.Reduction();
  return result;
}

Rational operator/(const Rational &fraction1, const Rational &fraction2) {
  int res_numerator = fraction1.GetNumerator() * fraction2.GetDenominator();
  int res_denominator = fraction1.GetDenominator() * fraction2.GetNumerator();
  Rational result = {res_numerator, res_denominator};
  result.Reduction();
  return result;
}

Rational &operator+=(Rational &fraction1, const Rational &fraction2) {
  Rational &result = fraction1;
  result = result + fraction2;
  return result;
}

Rational &operator-=(Rational &fraction1, const Rational &fraction2) {
  Rational &result = fraction1;
  result = result - fraction2;
  return result;
}

Rational &operator*=(Rational &fraction1, const Rational &fraction2) {
  Rational &result = fraction1;
  result = result * fraction2;
  return result;
}

Rational &operator/=(Rational &fraction1, const Rational &fraction2) {
  Rational &result = fraction1;
  result = result / fraction2;
  return result;
}

Rational operator+(const Rational &fraction) {
  Rational result = {fraction.GetNumerator(), fraction.GetDenominator()};
  return result;
}

Rational operator-(const Rational &fraction) {
  Rational result = {-fraction.GetNumerator(), fraction.GetDenominator()};
  return result;
}

Rational &operator++(Rational &fraction) {
  int numerator = fraction.GetNumerator();
  int denominator = fraction.GetDenominator();
  fraction.SetNumerator(numerator + denominator);
  return fraction;
}

Rational &operator--(Rational &fraction) {
  int numerator = fraction.GetNumerator();
  int denominator = fraction.GetDenominator();
  fraction.SetNumerator(numerator - denominator);
  return fraction;
}

const Rational operator++(Rational &fraction, int) {
  const Rational tmp = fraction;
  fraction.SetNumerator(tmp.GetNumerator() + tmp.GetDenominator());
  return tmp;
}

const Rational operator--(Rational &fraction, int) {
  const Rational tmp = fraction;
  fraction.SetNumerator(tmp.GetNumerator() - tmp.GetDenominator());
  return tmp;
}

bool operator==(const Rational &fraction1, const Rational &fraction2) {
  return (fraction1.GetNumerator() == fraction2.GetNumerator())
      && (fraction1.GetDenominator() == fraction2.GetDenominator());
}

bool operator!=(const Rational &fraction1, const Rational &fraction2) {
  return (fraction1.GetNumerator() != fraction2.GetNumerator())
      || (fraction1.GetDenominator() != fraction2.GetDenominator());
}

bool operator<(const Rational &fraction1, const Rational &fraction2) {
  return (fraction1.GetNumerator() * fraction2.GetDenominator())
      < (fraction2.GetNumerator() * fraction1.GetDenominator());
}

bool operator>(const Rational &fraction1, const Rational &fraction2) {
  return (fraction1.GetNumerator() * fraction2.GetDenominator())
      > (fraction2.GetNumerator() * fraction1.GetDenominator());
}

bool operator<=(const Rational &fraction1, const Rational &fraction2) {
  return !(fraction1 > fraction2);
}

bool operator>=(const Rational &fraction1, const Rational &fraction2) {
  return !(fraction1 < fraction2);
}
