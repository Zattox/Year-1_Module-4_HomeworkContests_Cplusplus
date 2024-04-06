#include <iostream>

using std::cin, std::cout;

int main() {
  int n, ans = 0;
  cin >> n;

  if (n == 1) {
    ans = 1;
  } else if (n > 1) {
    int x = 0, y = 1;

    for (int i = 2; i <= n; ++i) {
      int tmp = x + y;
      x = y;
      y = tmp;
    }

    ans = y;
  }

  cout << ans;
  return 0;
}
