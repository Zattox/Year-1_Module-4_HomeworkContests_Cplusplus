#include <iostream>

using std::cin, std::cout;

int main() {
  int n, m, k;
  cin >> n >> m >> k;

  if (k % m == 0 && k / m < n) {
    cout << "YES";
  } else if (k % n == 0 && k / n < m) {
    cout << "YES";
  } else {
    cout << "NO";
  }

  return 0;
}
