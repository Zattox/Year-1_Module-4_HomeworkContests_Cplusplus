#ifndef MY_CONST_ITERATOR
#define MY_CONST_ITERATOR

#include <iostream>
#include <iterator>
#include <cstddef>

template<typename T>
class MyConstIterator {
 public:
  using iterator_category = std::random_access_iterator_tag;
  using difference_type = std::ptrdiff_t;
  using value_type = T;
  using pointer = T *;
  using reference = T &;

  MyConstIterator();
  MyConstIterator(pointer ptr);

  T &operator[](size_t index);
  const T &operator[](size_t index) const;

  const reference operator*() const;
  const pointer operator->();

  MyConstIterator& operator++();
  MyConstIterator operator++(int);
  MyConstIterator& operator--();
  MyConstIterator operator--(int);

  friend bool operator==(const MyConstIterator &it1, const MyConstIterator &it2);
  friend bool operator!=(const MyConstIterator &it1, const MyConstIterator &it2);
  friend bool operator>(const MyConstIterator &it1, const MyConstIterator &it2);
  friend bool operator<(const MyConstIterator &it1, const MyConstIterator &it2);
  friend bool operator>=(const MyConstIterator &it1, const MyConstIterator &it2);
  friend bool operator<=(const MyConstIterator &it1, const MyConstIterator &it2);

  MyConstIterator operator+(const MyConstIterator &other_it) const;
  MyConstIterator operator-(const MyConstIterator &other_it) const;
  MyConstIterator &operator+=(const MyConstIterator &other_it);
  MyConstIterator &operator-=(const MyConstIterator &other_it);

  friend MyConstIterator operator+(const MyConstIterator &it, const int64_t &alpha);
  friend MyConstIterator operator-(const MyConstIterator &it, const int64_t &alpha);
  MyConstIterator &operator+=(const int64_t &alpha);
  MyConstIterator &operator-=(const int64_t &alpha);

 private:
  pointer ptr_;
};

#endif
