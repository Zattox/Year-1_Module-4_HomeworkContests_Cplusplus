#include <iostream>

using std::cin, std::cout;

int main() {
  int64_t a, b, ans = 0;
  cin >> a >> b;

  while (a * b > 0) {
    if (a > b) {
      ans += a / b;
      a -= (a / b) * b;
    } else if (b > a) {
      ans += b / a;
      b -= (b / a) * a;
    } else if (a == b) {
      a = 0;
      b = 0;
      ++ans;
    }
  }

  cout << ans;
  return 0;
}
