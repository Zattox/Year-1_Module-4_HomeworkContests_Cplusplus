#include <iostream>

using std::cin, std::cout;

void HanoiTowers(int n, int x, int y) {
  if (n == 1) {
    cout << 1 << ' ' << x << ' ' << y << '\n';
  } else {
    HanoiTowers(n - 1, x, 6 - x - y);
    cout << n << ' ' << x << ' ' << y << '\n';
    HanoiTowers(n - 1, 6 - x - y, y);
  }
}

int main() {
  int n;
  cin >> n;
  HanoiTowers(n, 1, 3);

  return 0;
}
