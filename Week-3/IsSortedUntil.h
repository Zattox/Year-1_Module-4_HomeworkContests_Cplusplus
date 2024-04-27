#ifndef IsSortedUntil_H
#define IsSortedUntil_H

template<typename T>
T IsSortedUntil(T begin, T end) {
  if (begin == end) {
    return end;
  }
  else {
    auto cur = begin + 1;
    while (cur < end && !(*cur < *(cur - 1))) {
      ++cur;
    }

    return cur;
  }
}

#endif
