#ifndef UNORDERED_SET
#define UNORDERED_SET

#include <list>
#include <vector>
#include <functional>

template <typename KeyT>
class UnorderedSet {
 public:
  UnorderedSet();
  explicit UnorderedSet(size_t count);
  template <typename IteratorType,
            typename = std::enable_if_t<std::is_base_of_v<
                std::forward_iterator_tag, typename std::iterator_traits<IteratorType>::iterator_category>>>
  UnorderedSet(IteratorType first, IteratorType last);
  UnorderedSet(const UnorderedSet &other);
  UnorderedSet(UnorderedSet &&other) noexcept;
  ~UnorderedSet() = default;
  UnorderedSet &operator=(const UnorderedSet &other);
  UnorderedSet &operator=(UnorderedSet &&other) noexcept;
  [[nodiscard]] size_t Size() const;
  [[nodiscard]] bool Empty() const;
  void Clear();
  void Insert(const KeyT &key);
  void Insert(KeyT &&key);
  void Erase(const KeyT &key);
  bool Find(const KeyT &key) const;
  void Rehash(size_t new_bucket_count);
  void Reserve(size_t new_bucket_count);
  [[nodiscard]] size_t BucketCount() const;
  [[nodiscard]] size_t BucketSize(size_t id) const;
  size_t Bucket(const KeyT &key) const;
  [[nodiscard]] double LoadFactor() const;

 private:
  size_t size_;
  size_t bucket_count_;
  std::vector<std::list<KeyT>> data_;
};

template <typename KeyT>
UnorderedSet<KeyT>::UnorderedSet() : size_(0), bucket_count_(0) {
}

template <typename KeyT>
UnorderedSet<KeyT>::UnorderedSet(size_t count) : size_(0), bucket_count_(count) {
  data_.clear();
  data_.resize(bucket_count_);
}

template <typename KeyT>
template <typename IteratorType, typename>
UnorderedSet<KeyT>::UnorderedSet(IteratorType first, IteratorType last) {
  auto tmp_first = first;
  size_t elem_count = 0;
  while (tmp_first != last) {
    ++tmp_first;
    ++elem_count;
  }
  size_ = elem_count;
  bucket_count_ = elem_count;
  data_.clear();
  data_.resize(bucket_count_);
  for (auto it = first; it != last; ++it) {
    size_t i_hash = std::hash<KeyT>{}(*it) % bucket_count_;
    data_[i_hash].emplace_back(*it);
  }
}

template <typename KeyT>
UnorderedSet<KeyT>::UnorderedSet(const UnorderedSet &other) {
  size_ = other.size_;
  bucket_count_ = other.bucket_count_;
  data_ = other.data_;
}

template <typename KeyT>
UnorderedSet<KeyT>::UnorderedSet(UnorderedSet &&other) noexcept {
  size_ = other.size_;
  bucket_count_ = other.bucket_count_;
  data_ = other.data_;
  other.size_ = 0;
  other.bucket_count_ = 0;
  other.data_.clear();
}

template <typename KeyT>
UnorderedSet<KeyT> &UnorderedSet<KeyT>::operator=(const UnorderedSet &other) {
  if (this != &other) {
    size_ = other.size_;
    bucket_count_ = other.bucket_count_;
    data_ = other.data_;
  }
  return *this;
}

template <typename KeyT>
UnorderedSet<KeyT> &UnorderedSet<KeyT>::operator=(UnorderedSet &&other) noexcept {
  if (this != &other) {
    size_ = other.size_;
    bucket_count_ = other.bucket_count_;
    data_ = other.data_;
    other.size_ = 0;
    other.bucket_count_ = 0;
    other.data_.clear();
  }
  return *this;
}

template <typename KeyT>
size_t UnorderedSet<KeyT>::Size() const {
  return size_;
}

template <typename KeyT>
bool UnorderedSet<KeyT>::Empty() const {
  return (size_ == 0);
}

template <typename KeyT>
void UnorderedSet<KeyT>::Clear() {
  size_ = 0;
  bucket_count_ = 0;
  data_.clear();
}

template <typename KeyT>
void UnorderedSet<KeyT>::Insert(const KeyT &key) {
  if (bucket_count_ == 0 || LoadFactor() >= 1.0) {
    Rehash(bucket_count_ == 0 ? 1 : bucket_count_ * 2);
  }
  size_t i_hash = std::hash<KeyT>{}(key) % bucket_count_;
  data_[i_hash].emplace_back(key);
  size_ += 1;
}

template <typename KeyT>
void UnorderedSet<KeyT>::Insert(KeyT &&key) {
  if (bucket_count_ == 0 || LoadFactor() >= 1.0) {
    Rehash(bucket_count_ == 0 ? 1 : bucket_count_ * 2);
  }
  size_t i_hash = std::hash<KeyT>{}(key) % bucket_count_;
  data_[i_hash].emplace_back(key);
  size_ += 1;
}

template <typename KeyT>
void UnorderedSet<KeyT>::Erase(const KeyT &key) {
  size_t i_hash = std::hash<KeyT>{}(key) % bucket_count_;
  for (auto it = data_[i_hash].begin(); it != data_[i_hash].end(); ++it) {
    if (*it == key) {
      data_[i_hash].erase(it);
      --size_;
      break;
    }
  }
}

template <typename KeyT>
bool UnorderedSet<KeyT>::Find(const KeyT &key) const {
  if (bucket_count_ == 0) {
    return false;
  }
  size_t i_hash = std::hash<KeyT>{}(key) % bucket_count_;
  for (auto el : data_[i_hash]) {
    if (el == key) {
      return true;
    }
  }
  return false;
}

template <typename KeyT>
void UnorderedSet<KeyT>::Rehash(size_t new_bucket_count) {
  double new_load_factor = size_ / static_cast<double>(new_bucket_count);
  if (new_bucket_count == bucket_count_ || new_load_factor > 1.0) {
    return;
  }
  std::vector<std::list<KeyT>> new_data(new_bucket_count);
  for (auto old_list : data_) {
    for (auto el : old_list) {
      size_t i_hash = std::hash<KeyT>{}(el) % new_bucket_count;
      new_data[i_hash].emplace_back(el);
    }
  }
  data_ = new_data;
  bucket_count_ = new_bucket_count;
}

template <typename KeyT>
void UnorderedSet<KeyT>::Reserve(size_t new_bucket_count) {
  double new_load_factor = size_ / static_cast<double>(new_bucket_count);
  if (new_bucket_count <= bucket_count_ || new_load_factor > 1.0) {
    return;
  }
  std::vector<std::list<KeyT>> new_data(new_bucket_count);
  for (auto old_list : data_) {
    for (auto el : old_list) {
      size_t i_hash = std::hash<KeyT>{}(el) % new_bucket_count;
      new_data[i_hash].emplace_back(el);
    }
  }
  data_ = new_data;
  bucket_count_ = new_bucket_count;
}

template <typename KeyT>
size_t UnorderedSet<KeyT>::BucketCount() const {
  return bucket_count_;
}

template <typename KeyT>
size_t UnorderedSet<KeyT>::BucketSize(size_t id) const {
  if (id >= data_.size()) {
    return 0;
  }
  return data_[id].size();
}

template <typename KeyT>
size_t UnorderedSet<KeyT>::Bucket(const KeyT &key) const {
  size_t i_hash = std::hash<KeyT>{}(key) % bucket_count_;
  return i_hash;
}

template <typename KeyT>
double UnorderedSet<KeyT>::LoadFactor() const {
  if (bucket_count_ == 0) {
    return 0.0;
  }
  return 1.0 * size_ / bucket_count_;
}

#endif
