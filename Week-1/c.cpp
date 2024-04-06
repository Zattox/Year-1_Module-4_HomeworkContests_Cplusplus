#include <iostream>

using std::cin, std::cout;

int main() {
  int n;
  cin >> n;

  int ans = n + 2 - n % 2;
  cout << ans;

  return 0;
}
