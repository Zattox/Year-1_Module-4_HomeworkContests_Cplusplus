#ifndef MY_CONST_ITERATOR
#define MY_CONST_ITERATOR

#include <iostream>
#include <iterator>
#include <cstddef>
#include <cstdint>

template<typename T>
class MyConstIterator {
 public:
  using iterator_category = std::random_access_iterator_tag; // NOLINT
  using difference_type = std::ptrdiff_t; // NOLINT
  using value_type = T; // NOLINT
  using pointer = const T *; // NOLINT
  using reference = const T &; // NOLINT

  MyConstIterator() : ptr_(nullptr) {
  }

  explicit MyConstIterator(pointer ptr) : ptr_(ptr) {
  }

  const T &operator*() const {
    return *ptr_;
  }

  const T *operator->() {
    return ptr_;
  }

  MyConstIterator &operator++() {
    ++ptr_;
    return *this;
  }

  const MyConstIterator operator++(int) {
    const MyConstIterator tmp = *this;
    ++(*this);
    return tmp;
  }

  MyConstIterator &operator--() {
    --ptr_;
    return *this;
  }

  const MyConstIterator operator--(int) {
    const MyConstIterator tmp = *this;
    --(*this);
    return tmp;
  }

  friend bool operator==(const MyConstIterator &it1, const MyConstIterator &it2) {
    return it1.ptr_ == it2.ptr_;
  }

  friend bool operator!=(const MyConstIterator &it1, const MyConstIterator &it2) {
    return it1.ptr_ != it2.ptr_;
  }

  friend bool operator>(const MyConstIterator &it1, const MyConstIterator &it2) {
    return it1.ptr_ > it2.ptr_;
  }

  friend bool operator<(const MyConstIterator &it1, const MyConstIterator &it2) {
    return it1.ptr_ < it2.ptr_;
  }

  friend bool operator>=(const MyConstIterator &it1, const MyConstIterator &it2) {
    return it1.ptr_ >= it2.ptr_;
  }

  friend bool operator<=(const MyConstIterator &it1, const MyConstIterator &it2) {
    return it1.ptr_ <= it2.ptr_;
  }

  friend MyConstIterator operator+(const MyConstIterator &it, const int64_t &alpha) {
    MyIterator result = it;
    result.ptr_ += alpha;
    return result;
  }

  friend difference_type operator-(const MyConstIterator &it1, const MyConstIterator &it2) {
    return (it1.ptr_ - it2.ptr_);
  }

  friend MyConstIterator operator-(const MyConstIterator &it, const int64_t &alpha) {
    MyIterator result = it;
    result.ptr_ -= alpha;
    return result;
  }

  MyConstIterator &operator+=(const int64_t &alpha) {
    ptr_ += alpha;
    return *this;
  }

  MyConstIterator &operator-=(const int64_t &alpha) {
    ptr_ -= alpha;
    return *this;
  }

 private:
  pointer ptr_;
};

#endif
