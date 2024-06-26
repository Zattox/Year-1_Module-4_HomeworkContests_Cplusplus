#ifndef RANGE_ITERATOR
#define RANGE_ITERATOR

#include <iostream>
#include <cstddef>
#include <cstdint>

template<typename T>
class RangeIterator {
 public:
  using iterator_category = std::forward_iterator_tag; //NOLINT
  using value_type = T; //NOLINT
  using reference = T &; //NOLINT
  using pointer = T *; //NOLINT

  RangeIterator(T value, T step, T end) : cur_value_{value}, step_{step}, end_value_{end}, reverse_{step > 0} {
  }

  RangeIterator operator++() {
    cur_value_ += step_;
    return *this;
  }

  reference operator*() {
    return cur_value_;
  }

  const pointer operator->() {
    return &cur_value_;
  }

  bool operator==(const RangeIterator &rhs) {
    if (reverse_) {
      return (cur_value_ >= rhs.cur_value_ && cur_value_ > end_value_);
    }
    return (cur_value_ <= rhs.cur_value_ && cur_value_ < end_value_);
  }

  bool operator!=(const RangeIterator &rhs) {
    if (reverse_) {
      return (cur_value_ < rhs.cur_value_ && cur_value_ >= end_value_);
    }
    return (cur_value_ > rhs.cur_value_ && cur_value_ <= end_value_);
  }

 private:
  T cur_value_;
  const T step_;
  const T end_value_;
  const bool reverse_;
};

#endif
