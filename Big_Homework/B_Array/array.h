#ifndef ARRAY
#define ARRAY

#define ARRAY_TRAITS_IMPLEMENTED
#include <iostream>
#include <stdexcept>

class ArrayOutOfRange : public std::out_of_range {
 public:
  ArrayOutOfRange() : std::out_of_range("ArrayOutOfRange") {
  }
};

template<class T, size_t N>
class Array {
 public:
  T arr[N];

  T &operator[](size_t index);
  const T &operator[](size_t index) const;
  T &At(size_t index);
  const T &At(size_t index) const;

  T &Front();
  const T &Front() const;
  T &Back();
  const T &Back() const;
  T *Data();
  const T *Data() const;

  [[nodiscard]] size_t Size() const;
  [[nodiscard]] bool Empty() const;
  void Fill(const T &value);

  void Swap(Array<T, N> &other);
};

template<class T, size_t N>
T &Array<T, N>::operator[](size_t index) {
  return *(arr + index);
}

template<class T, size_t N>
const T &Array<T, N>::operator[](size_t index) const {
  return *(arr + index);
}

template<class T, size_t N>
T &Array<T, N>::At(size_t index) {
  if (index < N) {
    return *(arr + index);
  }
  throw ArrayOutOfRange();
}

template<class T, size_t N>
const T &Array<T, N>::At(size_t index) const {
  if (index < N) {
    return *(arr + index);
  }
  throw ArrayOutOfRange();
}

template<class T, size_t N>
T &Array<T, N>::Front() {
  return *arr;
}

template<class T, size_t N>
const T &Array<T, N>::Front() const {
  return *arr;
}

template<class T, size_t N>
T &Array<T, N>::Back() {
  return *(arr + N - 1);
}

template<class T, size_t N>
const T &Array<T, N>::Back() const {
  return *(arr + N - 1);
}

template<class T, size_t N>
T *Array<T, N>::Data() {
  return arr;
}

template<class T, size_t N>
const T *Array<T, N>::Data() const {
  return arr;
}

template<class T, size_t N>
size_t Array<T, N>::Size() const {
  return N;
}

template<class T, size_t N>
bool Array<T, N>::Empty() const {
  return (Size() == 0);
}

template<class T, size_t N>
void Array<T, N>::Fill(const T &value) {
  for (size_t i = 0; i < N; ++i) {
    *(arr + i) = value;
  }
}

template<class T, size_t N>
void Array<T, N>::Swap(Array<T, N> &other) {
  for (size_t i = 0; i < N; ++i) {
    T temp = *(arr + i);
    *(arr + i) = other[i];
    other[i] = temp;
  }
}

template<typename T>
size_t GetSize(const T &) {
  return 0;
}

template<typename T, size_t N>
size_t GetSize(T (&)[N]) {
  return N;
}

template<typename T>
size_t GetRank(const T &) {
  return 0;
}

template<typename T, size_t N>
size_t GetRank(T (&arr)[N]) {
  size_t ans = 1 + GetRank(arr[0]);
  return ans;
}

template<typename T>
size_t GetNumElements(const T &) {
  return 1;
}

template<typename T, size_t N>
size_t GetNumElements(T (&arr)[N]) {
  size_t ans = GetSize(arr) * GetNumElements(arr[0]);
  return ans;
}

#endif