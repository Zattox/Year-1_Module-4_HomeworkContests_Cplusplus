#ifndef SHARED_PTR
#define SHARED_PTR

#include <future>

template<typename T>
class SharedPtr {
 private:
  T *ptr_ = nullptr;
  size_t *counter_ = nullptr;
 public:
  SharedPtr() : ptr_(nullptr) {
  }

  explicit SharedPtr(T *ptr) : ptr_(ptr) {
    if (ptr_) {
      counter_ = new size_t(1);
    }
  }

  SharedPtr(const SharedPtr &other) : ptr_(other.ptr_), counter_(other.counter_) {
    if (counter_) {
      ++(*counter_);
    }
  }

  SharedPtr(SharedPtr &&other) noexcept: ptr_(other.ptr_), counter_(other.counter_) {
    other.ptr_ = nullptr;
    other.counter_ = nullptr;
  }

  ~SharedPtr() {
    if (!counter_) {
      return;
    }
    if (*counter_ > 1) {
      --(*counter_);
      return;
    }
    delete ptr_;
    delete counter_;
  }

  SharedPtr &operator=(const SharedPtr &other) {
    if (this != &other) {
      this->~SharedPtr();
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
      this->~SharedPtr();
      ptr_ = other.ptr_;
      counter_ = other.counter_;
      other.ptr_ = nullptr;
      other.counter_ = nullptr;
    }
    return *this;
  }

  void Reset(T *ptr = nullptr) {
    this->~SharedPtr();
    if (ptr) {
      counter_ = new size_t(1);
    } else {
      counter_ = nullptr;
    }
    ptr_ = ptr;
  }

  void Swap(SharedPtr &other_ptr) {
    std::swap(ptr_, other_ptr.ptr_);
    std::swap(counter_, other_ptr.counter_);
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
