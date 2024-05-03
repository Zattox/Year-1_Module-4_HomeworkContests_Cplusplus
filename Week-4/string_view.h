#ifndef STRING_VIEW_H
#define STRING_VIEW_H

#include <iostream>
#include <cstring>
#include <stdexcept>

class StringViewOutOfRange : public std::out_of_range {
 public:
  StringViewOutOfRange() : std::out_of_range("StringViewOutOfRange") {
  }
};

class StringView {
 public :
  StringView();
  StringView(const char *sequence);  // NOLINT
  StringView(const char *sequence, size_t len);

  const char &operator[](size_t index) const;
  const char &At(size_t index) const;

  const char &Front() const;
  const char &Back() const;
  size_t Size() const;
  size_t Length() const;
  bool Empty() const;
  const char *Data() const;

  void Swap(StringView &other);
  void RemovePrefix(size_t prefix_size);
  void RemoveSuffix(size_t suffix_size);
  StringView Substr(size_t pos, size_t count);

 private:
  const char *string_;
  size_t size_;
};

#endif // STRING_VIEW_H
