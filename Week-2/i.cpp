#include <iostream>
#include <cmath>

using std::cin, std::cout;

bool IsPrime(int x) {
  for (int i = 2; i <= sqrt(x); ++i) {
    if (x % i == 0) {
      return false;
    }
  }
  return true;
}

int main() {
  int x;
  cin >> x;

  if (IsPrime(x)) {
    cout << "prime";
  } else {
    cout << "composite";
  }

  return 0;
}
