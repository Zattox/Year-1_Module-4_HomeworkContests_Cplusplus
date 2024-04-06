#include <iostream>

using std::cin, std::cout;

int main() {
  int n;
  cin >> n;

  int64_t sum = 0;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    sum += x;
  }

  cout << sum;
  return 0;
}
