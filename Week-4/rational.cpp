#include "rational.h"

Rational::Rational() : numerator_(0), denominator_(1) {

}

Rational::Rational(const int &number) : numerator_(number), denominator_(1) {

}

Rational::Rational(const int &numerator, const int &denominator) : numerator_(numerator), denominator_(denominator) {
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

Rational Rational::operator+(const Rational &value) const {
  int new_numerator = numerator_ * value.denominator_ + value.numerator_ * denominator_;
  int new_denominator = denominator_ * value.denominator_;
  Rational fraction(new_numerator, new_denominator);
  fraction.Reduction();

  return fraction;
}

Rational Rational::operator-(const Rational &value) const {
  int new_numerator = numerator_ * value.denominator_ - value.numerator_ * denominator_;
  int new_denominator = denominator_ * value.denominator_;
  Rational fraction(new_numerator, new_denominator);
  fraction.Reduction();

  return fraction;
}

Rational Rational::operator*(const Rational &value) const {
  int new_numerator = numerator_ * value.numerator_;
  int new_denominator = denominator_ * value.denominator_;
  Rational fraction(new_numerator, new_denominator);
  fraction.Reduction();

  return fraction;
}

Rational Rational::operator/(const Rational &value) const {
  int new_numerator = numerator_ * value.denominator_;
  int new_denominator = value.numerator_ * denominator_;
  Rational fraction(new_numerator, new_denominator);
  fraction.Reduction();

  return fraction;
}

Rational &Rational::operator=(Rational value) {
  value.Reduction();
  Update(value);
  return *this;
}

Rational &Rational::operator+=(const Rational &value) {
  *this = *this + value;
  return *this;
}

Rational &Rational::operator-=(const Rational &value) {
  *this = *this - value;
  return *this;
}

Rational &Rational::operator*=(const Rational &value) {
  *this = *this * value;
  return *this;
}

Rational &Rational::operator/=(const Rational &value) {
  *this = *this / value;
  return *this;
}

Rational Rational::operator+() const {
  return *this;
}

Rational Rational::operator-() const {
  int new_numerator = -numerator_;
  int new_denominator = denominator_;

  Rational fraction(new_numerator, new_denominator);
  fraction.Reduction();

  return fraction;
}

Rational &Rational::operator++() {
  numerator_ += denominator_;
  Reduction();
  return *this;
}

Rational &Rational::operator--() {
  numerator_ -= denominator_;
  Reduction();
  return *this;
}

const Rational Rational::operator++(int) {
  const Rational copy = *this;
  numerator_ += denominator_;
  return copy;
}

const Rational Rational::operator--(int) {
  const Rational copy = *this;
  numerator_ -= denominator_;
  return copy;
}

bool Rational::operator==(const Rational &value) const {
  return (numerator_ == value.numerator_)
      && (denominator_ == value.denominator_);
}

bool Rational::operator!=(const Rational &value) const {
  return !(*this == value);
}

bool Rational::operator<(const Rational &value) const {
  if (numerator_ * value.denominator_ < value.numerator_ * denominator_) {
    return true;
  }
  return false;
}

bool Rational::operator>(const Rational &value) const {
  if (numerator_ * value.denominator_ > value.numerator_ * denominator_) {
    return true;
  }
  return false;
}

bool Rational::operator<=(const Rational &value) const {
  return !(*this < value);
}

bool Rational::operator>=(const Rational &value) const {
  return !(*this > value);
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
    int ind = 0;
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

void Rational::Update(Rational &fraction) {
  std::swap(numerator_, fraction.numerator_);
  std::swap(denominator_, fraction.denominator_);
}
