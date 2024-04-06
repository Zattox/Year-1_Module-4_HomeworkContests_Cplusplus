#include <iostream>

using std::cin, std::cout;

int main() {
  int n;
  cin >> n;

  std::string ans = n % 2 == 0 ? "YES" : "NO";
  cout << ans;

  return 0;
}
