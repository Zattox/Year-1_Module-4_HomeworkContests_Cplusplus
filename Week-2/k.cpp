#include <iostream>

using std::cin, std::cout;

void Func(int n) {
  if (n < 1) {
    return;
  }

  int x;
  cin >> x;
  Func(n - 1);
  cout << x << " ";
}

int main() {
  int n;
  cin >> n;

  Func(n);

  return 0;
}
