#ifndef SHARED_PTR
#define SHARED_PTR

#include <iostream>

template<typename T>
class SharedPtr {
 private:
  T *ptr_;
  size_t *counter_;
 public:
  SharedPtr() {
    ptr_ = nullptr;
    counter_ = nullptr;
  }

  explicit SharedPtr(std::nullptr_t) {
    ptr_ = nullptr;
    counter_ = nullptr;
  }

  explicit SharedPtr(T *ptr) {
    ptr_ = ptr;
    counter_ = new size_t(1);
  }

  SharedPtr(const SharedPtr &other) {
    ptr_ = other.ptr_;
    counter_ = other.counter_;
    if (counter_ != nullptr) {
      ++(*counter_);
    }
  }

  SharedPtr(SharedPtr &&other) noexcept {
    ptr_ = other.ptr_;
    counter_ = other.counter_;
    other.ptr_ = nullptr;
    other.counter_ = nullptr;
  }

  ~SharedPtr() {
    if (counter_ == nullptr || *counter_ <= 1) {
      delete ptr_;
      delete counter_;
    } else {
      --(*counter_);
    }
  }

  SharedPtr &operator=(const SharedPtr &other) {
    if (this != &other) {
      ptr_ = other.ptr_;
      counter_ = other.counter_;
      if (counter_ != nullptr) {
        ++(*counter_);
      }
    }
    return *this;
  }

  SharedPtr &operator=(SharedPtr &&other) noexcept {
    if (this != &other) {
      if (counter_ != nullptr) {
        --(*counter_);
      }
      ptr_ = other.ptr_;
      counter_ = other.counter_;
      other.ptr_ = nullptr;
      other.counter_ = nullptr;
    }
    return *this;
  }

  void Reset(T *ptr = nullptr) {
    if (counter_ != nullptr) {
      --(*counter_);
    }
    ptr_ = ptr;
    if (ptr_ == nullptr) {
      counter_ = nullptr;
    } else {
      counter_ = new size_t(1);
    }
  }

  void Swap(SharedPtr &other_ptr) {
    std::swap(*this, other_ptr);
  }

  T *Get() const {
    return ptr_;
  }

  [[nodiscard]] size_t UseCount() const {
    if (counter_ != nullptr) {
      return *counter_;
    }
    return 0;
  }

  T &operator*() const {
    if (!ptr_) {
      throw "Dereference nullptr";
    }
    return *ptr_;
  }

  T *operator->() const {
    return Get();
  }

  explicit operator bool() const {
    return Get() != nullptr;
  }

};

#endif
