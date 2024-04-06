#include <iostream>

using std::cin, std::cout;

int main() {
  int a, b;
  cin >> a >> b;

  for (int i = a; i <= b; ++i) {
    if (i % 2 == 0) {
      cout << i << ' ';
    }
  }

  return 0;
}
