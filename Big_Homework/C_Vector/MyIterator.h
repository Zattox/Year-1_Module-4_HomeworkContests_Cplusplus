#ifndef MY_ITERATOR
#define MY_ITERATOR

#include <iostream>
#include <iterator>
#include <cstddef>
#include <cstdint>

template<typename T>
class MyIterator {
 public:
  using iterator_category = std::random_access_iterator_tag;
  using difference_type = std::ptrdiff_t;
  using value_type = T;
  using pointer = T *;
  using reference = T &;

  MyIterator() : ptr_(nullptr) {
  }

  explicit MyIterator(pointer ptr) : ptr_(ptr) {
  }

  reference operator*() const {
    return *ptr_;
  }

  pointer operator->() {
    return ptr_;
  }

  MyIterator &operator++() {
    ++ptr_;
    return *this;
  }

  const MyIterator operator++(int) {
    const MyIterator tmp = *this;
    ++(*this);
    return tmp;
  }

  MyIterator &operator--() {
    --ptr_;
    return *this;
  }

  const MyIterator operator--(int) {
    const MyIterator tmp = *this;
    --(*this);
    return tmp;
  }

  friend bool operator==(const MyIterator &it1, const MyIterator &it2) {
    return it1.ptr_ == it2.ptr_;
  }

  friend bool operator!=(const MyIterator &it1, const MyIterator &it2) {
    return it1.ptr_ != it2.ptr_;
  }

  friend bool operator>(const MyIterator &it1, const MyIterator &it2) {
    return it1.ptr_ > it2.ptr_;
  }

  friend bool operator<(const MyIterator &it1, const MyIterator &it2) {
    return it1.ptr_ < it2.ptr_;
  }

  friend bool operator>=(const MyIterator &it1, const MyIterator &it2) {
    return it1.ptr_ >= it2.ptr_;
  }

  friend bool operator<=(const MyIterator &it1, const MyIterator &it2) {
    return it1.ptr_ <= it2.ptr_;
  }

  friend difference_type operator-(const MyIterator &it1, const MyIterator &it2) {
    return (it1.ptr_ - it2.ptr_);
  }

  friend MyIterator operator+(const MyIterator &it, const int64_t &alpha) {
    MyIterator result = it;
    result.ptr_ += alpha;
    return result;
  }

  friend MyIterator operator-(const MyIterator &it, const int64_t &alpha) {
    MyIterator result = it;
    result.ptr_ -= alpha;
    return result;
  }

  MyIterator &operator+=(const int64_t alpha) {
    ptr_ += alpha;
    return *this;
  }

  MyIterator &operator-=(const int64_t alpha) {
    ptr_ -= alpha;
    return *this;
  }

 private:
  pointer ptr_;
};

#endif
