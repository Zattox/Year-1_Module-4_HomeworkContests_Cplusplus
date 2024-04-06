#include <iostream>

using std::cin, std::cout;

int GCD(int a, int b) {
  while (b > 0) {
    int t = a % b;
    a = b;
    b = t;
  }
  return a;
}

int main() {
  int a, b;
  cin >> a >> b;

  int g = GCD(abs(a), abs(b));
  cout << a / g << ' ' << b / g;

  return 0;
}
