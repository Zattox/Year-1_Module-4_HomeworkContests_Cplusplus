#include <iostream>
#include <vector>
#include <cassert>
#include "IsSortedUntil.h"

using std::cin, std::cout;

struct NonCopyableInt {
  int x = 0;

  NonCopyableInt(int x) : x(x) {  // NOLINT (explicit)
  }

  NonCopyableInt(const NonCopyableInt&) = delete;
  NonCopyableInt(NonCopyableInt&&) = default;

  NonCopyableInt& operator=(const NonCopyableInt&) = delete;
  NonCopyableInt& operator=(NonCopyableInt&&) = default;

  [[nodiscard]] bool operator<(const NonCopyableInt& other) const noexcept {
    return x < other.x;
  }
};


int main() {
  std::vector<int> data{{1, 1, 2, 2, 3, 3, 3, 2, 4, 5, 6}};  // NOLINT
  std::vector<NonCopyableInt> a;
  for (auto element : data) {
    a.emplace_back(element);
  }

  cout << (IsSortedUntil(a.begin(), a.begin()) == a.begin()) << "\n";
  cout << (IsSortedUntil(a.begin(), a.begin() + 10) == a.begin() + 7) << "\n";
  cout << (IsSortedUntil(a.begin(), a.begin() + 5) == a.begin() + 5) << "\n";
  cout << (IsSortedUntil(a.begin(), a.begin() + 8) == a.begin() + 7) << "\n";
  cout << (IsSortedUntil(a.begin() + 8, a.begin() + 10) == a.begin() + 10) << "\n";
  cout << (IsSortedUntil(a.begin() + 6, a.begin() + 8) == a.begin() + 7) << "\n";



  return 0;
}