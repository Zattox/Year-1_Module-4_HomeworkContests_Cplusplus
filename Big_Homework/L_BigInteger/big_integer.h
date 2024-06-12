#ifndef BIG_INTEGER
#define BIG_INTEGER

#include <cstdint>
#include <cmath>
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <iomanip>

using std::vector, std::string;

class BigIntegerOverflow : public std::runtime_error {
 public:
  BigIntegerOverflow() : std::runtime_error("BigIntegerOverflow") {
  }
};

class BigIntegerDivisionByZero : public std::runtime_error {
 public:
  BigIntegerDivisionByZero() : std::runtime_error("BigIntegerDivisionByZero") {
  }
};

class BigInteger {
 private:
  vector<int64_t> digits_;
  bool negative_;

  void RemoveLeadingZeros();
  void ShiftRight();
  [[nodiscard]] int64_t FindMaxCount(const BigInteger &number) const;
 public:
  static const int64_t kBase = 1000000000;

  BigInteger();
  BigInteger(int &&value);  // NOLINT
  BigInteger(const int64_t &value);  // NOLINT
  explicit BigInteger(const char *value);
  BigInteger(const BigInteger &other);

  BigInteger &operator=(BigInteger &&other) = default;
  BigInteger &operator=(const BigInteger &other);
  BigInteger &operator=(const int64_t &other);

  void SetNegative(bool sign);
  [[nodiscard]] bool IsNegative() const;

  friend const BigInteger operator+(BigInteger left, const BigInteger &right);
  friend const BigInteger operator-(BigInteger left, const BigInteger &right);
  friend const BigInteger operator*(BigInteger left, const BigInteger &right);
  friend const BigInteger operator/(BigInteger left, const BigInteger &right);
  friend const BigInteger operator%(BigInteger left, const BigInteger &right);

  BigInteger &operator+=(const BigInteger &other);
  BigInteger &operator-=(const BigInteger &other);
  BigInteger &operator*=(const BigInteger &other);
  BigInteger &operator/=(const BigInteger &other);
  BigInteger &operator%=(const BigInteger &other);

  friend BigInteger operator+(const BigInteger &number, const int64_t &alpha);
  friend BigInteger operator+(const int64_t &alpha, const BigInteger &number);
  friend BigInteger operator-(const BigInteger &number, const int64_t &alpha);
  friend BigInteger operator-(const int64_t &alpha, const BigInteger &number);
  friend BigInteger operator*(const BigInteger &number, const int64_t &alpha);
  friend BigInteger operator*(const int64_t &alpha, const BigInteger &number);
  friend BigInteger operator/(const BigInteger &number, const int64_t &alpha);
  friend BigInteger operator%(const BigInteger &number, const int64_t &alpha);

  BigInteger &operator+=(const int64_t &alpha);
  BigInteger &operator-=(const int64_t &alpha);
  BigInteger &operator*=(const int64_t &alpha);
  BigInteger &operator/=(const int64_t &alpha);
  BigInteger &operator%=(const int64_t &alpha);

  const BigInteger operator-() const;
  BigInteger &operator--();
  const BigInteger operator--(int);

  const BigInteger operator+() const;
  BigInteger &operator++();
  const BigInteger operator++(int);

  friend bool operator==(const BigInteger &, const BigInteger &);
  friend bool operator!=(const BigInteger &left, const BigInteger &right);
  friend bool operator<(const BigInteger &left, const BigInteger &right);
  friend bool operator>(const BigInteger &left, const BigInteger &right);
  friend bool operator<=(const BigInteger &left, const BigInteger &right);
  friend bool operator>=(const BigInteger &left, const BigInteger &right);

  friend std::ostream &operator<<(std::ostream &out, const BigInteger &value);
  friend std::istream &operator>>(std::istream &in, BigInteger &value);

};

#endif