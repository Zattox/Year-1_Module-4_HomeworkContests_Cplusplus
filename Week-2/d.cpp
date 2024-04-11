#include <iostream>

using std::cin, std::cout;

const int kMaxN = 100;

int main() {
  int n;
  int arr[kMaxN][kMaxN];
  cin >> n;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i + j < n - 1) {
        arr[i][j] = 0;
      } else if (i + j == n - 1) {
        arr[i][j] = 1;
      } else {
        arr[i][j] = 2;
      }
      cout << arr[i][j] << " ";
    }
    cout << '\n';
  }

  return 0;
}
