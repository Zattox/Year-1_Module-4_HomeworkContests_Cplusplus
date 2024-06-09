#ifndef VECTOR
#define VECTOR

#include "MyIterator.h"
#include "MyConstIterator.h"

template<typename T>
class Vector {
 public:
  using ValueType = T;
  using Pointer = T *;
  using ConstPointer = const T *;
  using Reference = T &;
  using ConstReference = const T &;
  using SizeType = size_t;
  using Iterator = MyIterator<T>;
  using ConstIterator = MyConstIterator<T>;
  using ReverseIterator = MyIterator<T>;
  using ConstReverseIterator = MyConstIterator<T>;

  Vector();
  Vector(SizeType size);
  Vector(SizeType size, ValueType value);
  template<class TemplateIterator, class = std::enable_if_t<std::is_base_of_v<std::forward_iterator_tag,
                                                                      typename std::iterator_traits<TemplateIterator>::iterator_category>>>
  Vector(TemplateIterator first, TemplateIterator last);
  Vector(std::initializer_list<ValueType> list);

  ~Vector();
  Vector(const Vector &other_vec);
  Vector &operator=(const Vector &other_vec);
  Vector(Vector &&other_vec);
  Vector &operator=(Vector &&other_vec);

  [[nodiscard]] size_t Size() const;
  [[nodiscard]] size_t Capacity() const;
  [[nodiscard]] bool Empty() const;

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
  void Swap(Vector<T> &other);

  void Resize(size_t new_size);
  void Resize(size_t new_size, T value);
  void Reserve(size_t new_capacity);
  void ShrinkToFit();
  void Clear();

  void PushBack(const T &value);
  void PushBack(T &&value);
  void PopBack();

  friend bool operator==(const Vector<T> &vector1, const Vector<T> &vector2);
  friend bool operator!=(const Vector<T> &vector1, const Vector<T> &vector2);
  friend bool operator<(const Vector<T> &vector1, const Vector<T> &vector2);
  friend bool operator>(const Vector<T> &vector1, const Vector<T> &vector2);
  friend bool operator<=(const Vector<T> &vector1, const Vector<T> &vector2);
  friend bool operator>=(const Vector<T> &vector1, const Vector<T> &vector2);

  Iterator begin(); //NOLINT
  Iterator end(); //NOLINT
  Iterator begin() const; //NOLINT
  Iterator end() const; //NOLINT

  ConstIterator cbegin() const; //NOLINT
  ConstIterator cend() const; //NOLINT

  ReverseIterator rbegin(); //NOLINT
  ReverseIterator rend(); //NOLINT
  ReverseIterator rbegin() const; //NOLINT
  ReverseIterator rend() const; //NOLINT

  ConstReverseIterator crbegin() const; //NOLINT
  ConstReverseIterator crend() const; //NOLINT

 private:
  T *arr_;
  size_t size_;
  size_t capacity_;
};



#endif
