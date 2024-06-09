#ifndef VECTOR
#define VECTOR

#include "MyIterator.h"
#include "MyConstIterator.h"
#include <algorithm>
#include <initializer_list>

template<typename T>
class Vector {
 private:
  T *arr_;
  size_t size_;
  size_t capacity_;
 public:
  using ValueType = T;
  using Pointer = T *;
  using ConstPointer = const T *;
  using Reference = T &;
  using ConstReference = const T &;
  using SizeType = size_t;
  using Iterator = MyIterator<T>;
  using ConstIterator = MyConstIterator<T>;
  using ReverseIterator = std::reverse_iterator<Iterator>;
  using ConstReverseIterator = std::reverse_iterator<ConstIterator>;

  Vector() {
    size_ = 0;
    capacity_ = 0;
    arr_ = new T[0];
  }

  explicit Vector(SizeType size) : size_(size), capacity_(size) {
    arr_ = new T[capacity_];
  }

  Vector(SizeType size, ValueType value) : size_(size), capacity_(size) {
    arr_ = new T[capacity_];
    std::fill(begin(), end(), value);
  }

  template<class TemplateIterator, class = std::enable_if_t<std::is_base_of_v<std::forward_iterator_tag,
                                                                              typename std::iterator_traits<
                                                                                  TemplateIterator>::iterator_category>>>
  Vector(TemplateIterator first, TemplateIterator last) : size_(last - first),
                                                          capacity_(last - first) {
    arr_ = new T[capacity_];
    std::copy(first, last, begin());
  }

  Vector(std::initializer_list<ValueType> list) {
    size_ = list.size();
    capacity_ = list.size();
    arr_ = new T[capacity_];
    size_t index = 0;
    for (auto el : list) {
      arr_[index] = std::move(el);
      ++index;
    }
  }

  Vector(const Vector &other) : arr_(new T[other.capacity_]), size_(other.size_), capacity_(other.capacity_) {
    for (size_t i = 0; i < size_; ++i) {
      arr_[i] = other.arr_[i];
    }
  }

  Vector(Vector &&other) noexcept: arr_(other.arr_), size_(other.size_), capacity_(other.capacity_) {
    other.arr_ = nullptr;
    other.capacity_ = 0;
    other.size_ = 0;
  }

  ~Vector() = default;

  Vector &operator=(const Vector &other) {
    if (this != &other) {
      delete[] arr_;
      size_ = other.size_;
      capacity_ = other.capacity_;
      arr_ = new T[capacity_];
      std::copy(other.begin(), other.end(), begin());
    }
    return *this;
  }

  Vector &operator=(Vector &&other) noexcept {
    if (this != &other) {
      delete[] arr_;
      arr_ = other.arr_;
      size_ = other.size_;
      capacity_ = other.capacity_;
      other.arr_ = nullptr;
      other.size_ = 0;
      other.capacity_ = 0;
    }
    return *this;
  }

  [[nodiscard]] SizeType Size() const {
    return size_;
  }

  [[nodiscard]] SizeType Capacity() const {
    return capacity_;
  }

  [[nodiscard]] bool Empty() const {
    return (size_ == 0);
  }

  T &operator[](size_t index) {
    return *(arr_ + index);
  }

  const T &operator[](size_t index) const {
    return *(arr_ + index);
  }

  T &At(size_t index) {
    if (index < size_) {
      return *(arr_ + index);
    }
    throw std::out_of_range("Vector out of range");
  }

  const T &At(size_t index) const {
    if (index < size_) {
      return *(arr_ + index);
    }
    throw std::out_of_range("Vector out of range");
  }

  T &Front() {
    return *arr_;
  }

  const T &Front() const {
    return *arr_;
  }

  T &Back() {
    return *(arr_ + size_ - 1);
  }

  const T &Back() const {
    return *(arr_ + size_ - 1);
  }

  T *Data() {
    if (size_ == 0 && capacity_ == 0) {
      return nullptr;
    }
    return arr_;
  }

  const T *Data() const {
    if (size_ == 0 && capacity_ == 0) {
      return nullptr;
    }
    return arr_;
  }

  void Swap(Vector<T> &other) {
    std::swap(*this, other);
  }

  void Resize(size_t new_size) {
    if (new_size < capacity_) {
      size_ = new_size;
    } else if (new_size > capacity_) {
      T *new_arr = new T[new_size];
      std::move(begin(), end(), new_arr);

      delete[] arr_;
      arr_ = std::move(new_arr);
      capacity_ = new_size;
      size_ = new_size;
    }
  }

  void Resize(size_t new_size, T value) {
    if (new_size < capacity_) {
      if (new_size > size_) {
        std::fill(begin() + size_, begin() + new_size, value);
      }
      size_ = new_size;
    } else if (new_size > capacity_) {
      T *new_arr = new T[new_size];
      std::move(begin(), end(), new_arr);
      std::fill(new_arr + capacity_, new_arr + new_size, value);

      delete[] arr_;
      arr_ = std::move(new_arr);
      capacity_ = new_size;
      size_ = new_size;
    }
  }

  void Reserve(size_t new_capacity) {
    if (new_capacity > capacity_) {
      T *new_arr = new T[new_capacity];
      std::move(begin(), end(), new_arr);

      delete[] arr_;
      arr_ = std::move(new_arr);
      capacity_ = new_capacity;
    }
  }

  void ShrinkToFit() {
    if (capacity_ > size_) {
      T *new_arr = new T[size_];
      std::move(begin(), end(), new_arr);

      delete[] arr_;
      arr_ = std::move(new_arr);
      capacity_ = size_;
    }
  }

  void Clear() {
    size_ = 0;
  }

  void PushBack(const T &value) {
    if (size_ < capacity_) {
      arr_[size_] = std::move(value);
      size_ = size_ + 1;
    } else {
      size_t new_size = capacity_ > 0 ? capacity_ * 2 : 1;
      T *new_arr = new T[new_size];
      std::move(begin(), end(), new_arr);
      new_arr[size_] = std::move(value);

      delete[] arr_;
      arr_ = std::move(new_arr);
      capacity_ = new_size;
      size_ = size_ + 1;
    }
  }

  void PushBack(T &&value) {
    if (size_ < capacity_) {
      arr_[size_] = std::move(value);
      size_ = size_ + 1;
    } else {
      size_t new_size = capacity_ > 0 ? capacity_ * 2 : 1;
      T *new_arr = new T[new_size];
      std::move(begin(), end(), new_arr);
      new_arr[size_] = std::move(value);

      delete[] arr_;
      arr_ = std::move(new_arr);
      capacity_ = new_size;
      size_ = size_ + 1;
    }
  }

  friend bool operator==(const Vector<T> &vector1, const Vector<T> &vector2) {
    if (vector1.size_ == vector2.size_) {
      for (SizeType i = 0; i < vector1.size_; ++i) {
        if (vector1[i] != vector2[i]) {
          return false;
        }
      }
      return true;
    }
    return false;
  }
  friend bool operator!=(const Vector<T> &vector1, const Vector<T> &vector2) {
    return !(vector1 == vector2);
  }
  friend bool operator<(const Vector<T> &vector1, const Vector<T> &vector2) {
    SizeType i = 0;
    SizeType len = std::min(vector1.size_, vector2.size_);
    for (; i < len; ++i) {
      if (vector1[i] != vector2[i]) {
        break;
      }
    }
    if (i < len) {
      return vector1[i] < vector2[i];
    } else {
      return vector1.size_ < vector2.size_;
    }
  }
  friend bool operator>(const Vector<T> &vector1, const Vector<T> &vector2) {
    SizeType i = 0;
    SizeType len = std::min(vector1.size_, vector2.size_);
    for (; i < len; ++i) {
      if (vector1[i] != vector2[i]) {
        break;
      }
    }
    if (i < len) {
      return vector1[i] > vector2[i];
    } else {
      return vector1.size_ > vector2.size_;
    }
  }
  friend bool operator<=(const Vector<T> &vector1, const Vector<T> &vector2) {
    return (vector1 < vector2) || (vector1 == vector2);
  }
  friend bool operator>=(const Vector<T> &vector1, const Vector<T> &vector2) {
    return (vector1 > vector2) || (vector1 == vector2);
  }

  void PopBack() {
    --size_;
  }

  Iterator begin() {  // NOLINT
    return Vector::Iterator(arr_);
  }

  Iterator end() {  // NOLINT
    return Vector::Iterator(arr_ + size_);
  }

  ConstIterator begin() const {  // NOLINT
    return Vector::ConstIterator(arr_);
  }

  ConstIterator end() const {  // NOLINT
    return Vector::ConstIterator(arr_ + size_);
  }

  ConstIterator cbegin() const {  // NOLINT
    return Vector::ConstIterator(arr_);
  }

  ConstIterator cend() const {  // NOLINT
    return Vector::ConstIterator(arr_ + size_);
  }

  ReverseIterator rbegin() {  // NOLINT
    return std::make_reverse_iterator(Iterator(arr_ + size_));
  }

  ReverseIterator rend() {  // NOLINT
    return std::make_reverse_iterator(Iterator(arr_));
  }

  ConstReverseIterator rbegin() const {  // NOLINT
    return std::make_reverse_iterator(ConstIterator(arr_ + size_));
  }

  ConstReverseIterator rend() const {  // NOLINT
    return std::make_reverse_iterator(ConstIterator(arr_));
  }

  ConstReverseIterator crbegin() const {  // NOLINT
    return std::make_reverse_iterator(ConstIterator(arr_ + size_));
  }

  ConstReverseIterator crend() const {  // NOLINT
    return std::make_reverse_iterator(ConstIterator(arr_));
  }

};

#endif
