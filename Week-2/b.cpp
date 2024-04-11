#include <iostream>

using std::cin, std::cout;

const int kMaxN = 100;

int main() {
  int n, m;
  int arr[kMaxN][kMaxN];
  cin >> n >> m;

  for (int i = 0; i < n; ++i) {
    arr[i][0] = 1;
  }
  for (int j = 0; j < m; ++j) {
    arr[0][j] = 1;
  }
  for (int i = 1; i < n; ++i) {
    for (int j = 1; j < m; ++j) {
      arr[i][j] = arr[i - 1][j] + arr[i][j - 1];
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cout << arr[i][j] << ' ';
    }
    cout << '\n';
  }

  return 0;
}