#ifndef MY_ITERATOR
#define MY_ITERATOR

#include <iostream>
#include <iterator>
#include <cstddef>

template<typename T>
class MyIterator {
 public:
  using iterator_category = std::random_access_iterator_tag;
  using difference_type = std::ptrdiff_t;
  using value_type = T;
  using pointer = T *;
  using reference = T &;

  MyIterator();
  MyIterator(pointer ptr);

  T &operator[](size_t index);
  const T &operator[](size_t index) const;

  reference operator*() const;
  pointer operator->();

  MyIterator& operator++();
  MyIterator operator++(int);
  MyIterator& operator--();
  MyIterator operator--(int);

  friend bool operator==(const MyIterator &it1, const MyIterator &it2);
  friend bool operator!=(const MyIterator &it1, const MyIterator &it2);
  friend bool operator>(const MyIterator &it1, const MyIterator &it2);
  friend bool operator<(const MyIterator &it1, const MyIterator &it2);
  friend bool operator>=(const MyIterator &it1, const MyIterator &it2);
  friend bool operator<=(const MyIterator &it1, const MyIterator &it2);

  MyIterator operator+(const MyIterator &other_it) const;
  MyIterator operator-(const MyIterator &other_it) const;
  MyIterator &operator+=(const MyIterator &other_it);
  MyIterator &operator-=(const MyIterator &other_it);

  friend MyIterator operator+(const MyIterator &it, const int64_t &alpha);
  friend MyIterator operator-(const MyIterator &it, const int64_t &alpha);
  MyIterator &operator+=(const int64_t &alpha);
  MyIterator &operator-=(const int64_t &alpha);

 private:
  pointer ptr_;
};

#endif
