#include <iostream>
#include <cmath>

using std::cin, std::cout;

int main() {
  int x;
  cin >> x;

  for (int i = 2; i <= sqrt(x) + 1; ++i) {
    if (x % i == 0) {
      cout << i;
      return 0;
    }
  }

  cout << x;
  return 0;
}
