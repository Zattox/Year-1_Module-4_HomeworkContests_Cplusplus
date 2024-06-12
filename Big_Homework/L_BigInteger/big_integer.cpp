#include "big_integer.h"
#define BIG_INTEGER_DIVISION_IMPLEMENTED

BigInteger::BigInteger() {
  negative_ = false;
  digits_.emplace_back(0);
}

BigInteger::BigInteger(int &&value) {
  negative_ = (value < 0);
  int64_t tmp = std::abs(value);
  do {
    digits_.push_back(tmp % kBase);
    tmp /= kBase;
  } while (tmp != 0);
}

BigInteger::BigInteger(const int64_t &value) {
  negative_ = (value < 0);
  int64_t tmp = std::abs(value);
  do {
    digits_.push_back(tmp % kBase);
    tmp /= kBase;
  } while (tmp != 0);
}

void BigInteger::RemoveLeadingZeros() {
  while (digits_.size() > 1 && digits_.back() == 0) {
    digits_.pop_back();
  }
  if (digits_.size() == 1 && digits_[0] == 0) {
    negative_ = false;
  }
}

BigInteger::BigInteger(const char *value_c) {
  string value(value_c);
  if (value.empty()) {
    digits_.emplace_back(0);
    negative_ = false;
  } else {
    negative_ = false;
    string abs_value = value;
    if (value[0] == '-') {
      abs_value = abs_value.substr(1);
      negative_ = true;
    }
    for (auto i = static_cast<int64_t>(abs_value.size()); i > 0; i -= 9) {
      if (i < 9) {
        digits_.emplace_back(std::atoll(abs_value.substr(0, i).c_str()));
      } else {
        digits_.emplace_back(std::atoll(abs_value.substr(i - 9, 9).c_str()));
      }
    }
    RemoveLeadingZeros();
  }
}

BigInteger::BigInteger(const BigInteger &other) {
  digits_ = other.digits_;
  negative_ = other.negative_;
}

BigInteger &BigInteger::operator=(const BigInteger &other) {
  if (this != &other) {
    digits_ = other.digits_;
    negative_ = other.negative_;
  }
  return *this;
}

BigInteger &BigInteger::operator=(const int64_t &other) {
  digits_.clear();
  negative_ = (other < 0);
  int64_t tmp = std::abs(other);
  do {
    digits_.push_back(tmp % kBase);
    tmp /= kBase;
  } while (tmp != 0);

  return *this;
}

void BigInteger::SetNegative(bool sign) {
  negative_ = sign;
}

bool BigInteger::IsNegative() const {
  return negative_;
}

const BigInteger BigInteger::operator-() const {
  BigInteger result(*this);
  result.SetNegative(!(IsNegative()));
  return result;
}

const BigInteger BigInteger::operator+() const {
  return BigInteger(*this);
}

const BigInteger operator+(BigInteger left, const BigInteger &right) {
  if (left.negative_ && right.negative_) {
    return -((-left) + (-right));
  }
  if (left.negative_) {
    return right - (-left);
  }
  if (right.negative_) {
    return left - (-right);
  }

  int64_t delta = 0;
  size_t len = std::max(left.digits_.size(), right.digits_.size());
  for (size_t i = 0; i < len || delta != 0; ++i) {
    if (i == left.digits_.size()) {
      left.digits_.emplace_back(0);
    }
    int64_t cur_digit = left.digits_[i];
    if (i < right.digits_.size()) {
      cur_digit += right.digits_[i];
    }
    cur_digit += delta;
    delta = 0;
    if (cur_digit >= BigInteger::kBase) {
      delta = 1;
      cur_digit -= BigInteger::kBase;
    }
    left.digits_[i] = cur_digit;
  }
  left.RemoveLeadingZeros();
  return left;
}

const BigInteger operator-(BigInteger left, const BigInteger &right) {
  if (left.negative_ && right.negative_) {
    return (-right) - (-left);
  }
  if (left.negative_) {
    return -((-left) + right);
  }
  if (right.negative_) {
    return left + (-right);
  }
  if (left < right) {
    return -(right - left);
  }

  int64_t delta = 0;
  for (size_t i = 0; i < right.digits_.size() || delta != 0; ++i) {
    int64_t cur_digit = left.digits_[i];
    if (i < right.digits_.size()) {
      cur_digit -= right.digits_[i];
    }
    cur_digit -= delta;
    delta = 0;
    if (cur_digit < 0) {
      delta = 1;
      cur_digit += BigInteger::kBase;
    }
    left.digits_[i] = cur_digit;
  }
  left.RemoveLeadingZeros();
  return left;
}

const BigInteger operator*(BigInteger left, const BigInteger &right) {
  if (left.digits_.size() * right.digits_.size() * 81 > 1100000) {
    throw BigIntegerOverflow{};
  }

  BigInteger result;
  result.digits_.resize(left.digits_.size() + right.digits_.size());
  for (size_t i = 0; i < left.digits_.size(); ++i) {
    int64_t delta = 0;
    for (size_t j = 0; j < right.digits_.size() || delta != 0; ++j) {
      int64_t cur_digit = delta + result.digits_[i + j];
      if (j < right.digits_.size()) {
        cur_digit += 1LL * left.digits_[i] * right.digits_[j];
      }
      delta = cur_digit / BigInteger::kBase;
      result.digits_[i + j] = cur_digit % BigInteger::kBase;
    }
  }
  result.negative_ = (left.negative_ != right.negative_);
  result.RemoveLeadingZeros();
  return result;
}

void BigInteger::ShiftRight() {
  if (digits_.empty()) {
    digits_.emplace_back(0);
    return;
  }
  digits_.push_back(digits_[digits_.size() - 1]);
  for (size_t i = digits_.size() - 2; i > 0; --i) {
    digits_[i] = digits_[i - 1];
  }
  digits_[0] = 0;
}

int64_t BigInteger::FindMaxCount(const BigInteger &number) const {
  int64_t l = 0;
  int64_t r = BigInteger::kBase;
  while (l + 1 < r) {
    int64_t m = (l + r) / 2;
    if (number * m <= *this) {
      l = m;
    } else {
      r = m;
    }
  }
  return l;
}

const BigInteger operator/(BigInteger left, const BigInteger &right) {
  if (right == BigInteger(0)) {
    throw BigIntegerDivisionByZero();
  }

  BigInteger tmp = right;
  tmp.negative_ = false;
  BigInteger result;
  BigInteger current;
  result.digits_.resize(left.digits_.size());
  for (int64_t i = static_cast<int64_t>(left.digits_.size()) - 1; i >= 0; --i) {
    current.ShiftRight();
    current.digits_[0] = left.digits_[i];
    current.RemoveLeadingZeros();
    int64_t max_count = current.FindMaxCount(tmp);
    result.digits_[i] = max_count;
    current = current - tmp * max_count;
  }

  result.negative_ = (left.negative_ != right.negative_);
  result.RemoveLeadingZeros();
  return result;
}

const BigInteger operator%(BigInteger left, const BigInteger &right) {
  BigInteger result = left - (left / right) * right;
  return result;
}

BigInteger &BigInteger::operator+=(const BigInteger &other) {
  (*this) = (*this) + other;
  return *this;
}

BigInteger &BigInteger::operator-=(const BigInteger &other) {
  (*this) = (*this) - other;
  return *this;
}

BigInteger &BigInteger::operator*=(const BigInteger &other) {
  (*this) = (*this) * other;
  return *this;
}

BigInteger &BigInteger::operator/=(const BigInteger &other) {
  (*this) = (*this) / other;
  return *this;
}

BigInteger &BigInteger::operator%=(const BigInteger &other) {
  (*this) = (*this) % other;
  return *this;
}

BigInteger &BigInteger::operator+=(const int64_t &alpha) {
  (*this) = (*this) + alpha;
  return *this;
}

BigInteger &BigInteger::operator-=(const int64_t &alpha) {
  (*this) = (*this) - alpha;
  return *this;
}

BigInteger &BigInteger::operator*=(const int64_t &alpha) {
  (*this) = (*this) * alpha;
  return *this;
}

BigInteger &BigInteger::operator/=(const int64_t &alpha) {
  if (alpha == 0) {
    throw BigIntegerDivisionByZero();
  }
  (*this) = (*this) / alpha;
  return *this;
}

BigInteger &BigInteger::operator%=(const int64_t &alpha) {
  if (alpha == 0) {
    throw BigIntegerDivisionByZero();
  }
  (*this) = (*this) % alpha;
  return *this;
}

BigInteger operator+(const BigInteger &number, const int64_t &alpha) {
  BigInteger result = number + BigInteger(alpha);
  return result;
}

BigInteger operator+(const int64_t &alpha, const BigInteger &number) {
  BigInteger result = number + BigInteger(alpha);
  return result;
}

BigInteger operator-(const BigInteger &number, const int64_t &alpha) {
  BigInteger result = number - BigInteger(alpha);
  return result;
}

BigInteger operator-(const int64_t &alpha, const BigInteger &number) {
  BigInteger result = number - BigInteger(alpha);
  return result;
}

BigInteger operator*(const BigInteger &number, const int64_t &alpha) {
  BigInteger result = number * BigInteger(alpha);
  return result;
}

BigInteger operator*(const int64_t &alpha, const BigInteger &number) {
  BigInteger result = number * BigInteger(alpha);
  return result;
}

BigInteger operator/(const BigInteger &number, const int64_t &alpha) {
  BigInteger result = number / BigInteger(alpha);
  return result;
}

BigInteger operator%(const BigInteger &number, const int64_t &alpha) {
  BigInteger result = number % BigInteger(alpha);
  return result;
}

BigInteger &BigInteger::operator--() {
  (*this) -= 1;
  return *this;
}

const BigInteger BigInteger::operator--(int) {
  const BigInteger tmp = *this;
  (*this) -= 1;
  return tmp;
}

BigInteger &BigInteger::operator++() {
  (*this) += 1;
  return *this;
}

const BigInteger BigInteger::operator++(int) {
  const BigInteger tmp = *this;
  (*this) += 1;
  return tmp;
}

bool operator==(const BigInteger &left, const BigInteger &right) {
  if (left.negative_ != right.negative_) {
    return false;
  }
  if (left.digits_.size() != right.digits_.size()) {
    return false;
  }
  for (size_t i = 0; i < left.digits_.size(); ++i) {
    if (left.digits_[i] != right.digits_[i]) {
      return false;
    }
  }
  return true;
}

bool operator!=(const BigInteger &left, const BigInteger &right) {
  return !(left == right);
}

bool operator<(const BigInteger &left, const BigInteger &right) {
  if (left == right) {
    return false;
  }
  if (left.negative_) {
    if (right.negative_) {
      return (-(left) < (-right));
    }
    return true;
  }
  if (right.negative_) {
    return false;
  }
  if (left.digits_.size() != right.digits_.size()) {
    return left.digits_.size() < right.digits_.size();
  }
  size_t i = left.digits_.size() - 1;
  while (i > 0 && left.digits_[i] == right.digits_[i]) {
    --i;
  }
  return left.digits_[i] < right.digits_[i];
}

bool operator<=(const BigInteger &left, const BigInteger &right) {
  return (left < right || left == right);
}

bool operator>(const BigInteger &left, const BigInteger &right) {
  return !(left <= right);
}

bool operator>=(const BigInteger &left, const BigInteger &right) {
  return !(left < right);
}

std::ostream &operator<<(std::ostream &out, const BigInteger &value) {
  if (value.digits_.empty()) {
    out << 0;
  } else {
    if (value.negative_) {
      out << '-';
    }
    out << value.digits_.back();
    auto old_fill = out.fill('0');
    for (auto i = static_cast<int64_t>(value.digits_.size()) - 2; i >= 0; --i) {
      out << std::setw(9) << value.digits_[i];
    }
    out.fill(old_fill);
  }
  return out;
}

std::istream &operator>>(std::istream &in, BigInteger &value) {
  string number;
  in >> number;
  value = BigInteger(number.c_str());
  return in;
}
