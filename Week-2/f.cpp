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
  int n, ans;
  cin >> n >> ans;

  for (int i = 1; i < n; ++i) {
    int x;
    cin >> x;
    ans = GCD(x, ans);
  }

  cout << ans;

  return 0;
}
