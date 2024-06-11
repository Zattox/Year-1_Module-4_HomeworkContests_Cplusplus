#ifndef WHOSHUU_Range_H
#define WHOSHUU_Range_H

#include <iterator>
#include <stdexcept>
#include "RangeIterator.h"
#define REVERSE_RANGE_IMPLEMENTED

template<typename T>
class RangeClass {
 public:
  RangeClass(const T &start, const T &stop, const T &step) : start_{start}, stop_{stop}, step_{step} {
  }

  RangeIterator<T> begin() const {
    return RangeIterator<T>(start_, step_, start_);
  }

  RangeIterator<T> end() const {
    return RangeIterator<T>(stop_, step_, start_);
  }

 private:
  const T start_;
  const T stop_;
  const T step_;
};

template<typename T>
RangeClass<T> Range(const T &stop) {
  return RangeClass<T>(T{0}, stop, T{1});
}

template<typename T>
RangeClass<T> Range(const T &start, const T &stop) {
  return RangeClass<T>(start, stop, T{1});
}

template<typename T>
RangeClass<T> Range(const T &start, const T &stop, const T &step) {
  if (step == 0) {
    return RangeClass<T>(T{0}, T{0}, T{0});
  }
  return RangeClass<T>(start, stop, step);
}

#endif /* WHOSHUU_Range_H */