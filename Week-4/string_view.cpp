#include "string_view.h"

StringView::StringView() {
  string_ = nullptr;
  size_ = 0;
}

StringView::StringView(const char *sequence) {
  string_ = sequence;
  size_ = strlen(sequence);
}

StringView::StringView(const char *sequence, const size_t len) {
  string_ = sequence;
  size_ = len;
}

const char &StringView::operator[](size_t index) const {
  return *(string_ + index);
}

const char &StringView::At(size_t index) const {
  if (index >= size_) {
    throw StringViewOutOfRange{};
  }
  return *(string_ + index);
}

const char &StringView::Front() const {
  return *string_;
}

const char &StringView::Back() const {
  return *(string_ + size_ - 1);
}

size_t StringView::Size() const {
  return size_;
}

size_t StringView::Length() const {
  return size_;
}

bool StringView::Empty() const {
  return (size_ == 0);
}

const char *StringView::Data() const {
  return string_;
}

void StringView::Swap(StringView &other) {
  StringView tmp = other;
  other.string_ = string_;
  other.size_ = size_;
  string_ = tmp.string_;
  size_ = tmp.size_;
}

void StringView::RemovePrefix(size_t prefix_size) {
  string_ += prefix_size;
  size_ -= prefix_size;
}

void StringView::RemoveSuffix(size_t suffix_size) {
  size_ -= suffix_size;
}

StringView StringView::Substr(size_t pos, size_t count = -1) {
  if (Size() - pos < 0) {
    throw StringViewOutOfRange{};
  }
  size_t len = std::min(count, Size() - pos);
  auto substr = string_ + pos;
  return StringView{substr, len};
}