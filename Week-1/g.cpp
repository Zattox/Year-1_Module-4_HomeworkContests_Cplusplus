#include <iostream>

using std::cin, std::cout;

int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;

  if (a == 0 && b == 0) {
    cout << "INF";
  } else if (a == 0 || (b * c) == (a * d)) {
    cout << "NO";
  } else if (b % a == 0) {
    cout << -b / a;
  } else {
    cout << "NO";
  }

  return 0;
}
