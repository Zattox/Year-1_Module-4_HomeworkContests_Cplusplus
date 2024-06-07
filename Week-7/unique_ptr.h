#pragma once

#include <cstddef>
#include <utility>

template<class T>
class UniquePtr {
 public:
  UniquePtr() = default;
  explicit UniquePtr(T *ptr) : ptr_(ptr) {}

  UniquePtr(const UniquePtr &) = delete;
  UniquePtr &operator=(const UniquePtr &) = delete;

  UniquePtr(UniquePtr &&other_ptr) noexcept {
    ptr_ = other_ptr.ptr_;
    other_ptr.ptr_ = nullptr;
  }

  UniquePtr &operator=(UniquePtr &&other_ptr) noexcept {
    if (this != &other_ptr) {
      delete ptr_;
      ptr_ = other_ptr.ptr_;
      other_ptr.ptr_ = nullptr;
    }
    return *this;
  }

  ~UniquePtr() noexcept {
    delete ptr_;
  }

  T *Release() {
    return std::exchange(ptr_, nullptr);
  }

  void Reset(T *ptr = nullptr) {
    delete ptr_;
    ptr_ = ptr;
  }

  void Swap(UniquePtr &other_ptr) {
    UniquePtr temp = {std::move(other_ptr)};
    other_ptr = std::move(*this);
    *this = std::move(temp);
  }

  T *Get() const {
    return ptr_;
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

 private:
  T *ptr_ = nullptr;
};

