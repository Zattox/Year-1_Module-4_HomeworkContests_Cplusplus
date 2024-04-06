#include <iostream>
#include <cmath>

using std::cin, std::cout;

int main() {
  int a, b;
  cin >> a >> b;

  double ans = sqrt(a * a + b * b);
  cout.precision(10);
  cout << ans;

  return 0;
}
