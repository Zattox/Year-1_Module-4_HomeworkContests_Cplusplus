#include <iostream>

using std::cin, std::cout;

const int kMaxN = 100;

int main() {
  int n, m;
  int arr[kMaxN][kMaxN];
  cin >> n >> m;

  int cur_num = 0, x = 0, y = 0, ch = 0;
  while (x != n - 1 || y != m - 1) {
    while (y >= 0 && x <= n - 1) {
      arr[x][y] = cur_num++;
      ++x;
      --y;
    }

    ++ch;
    if (ch < m) {
      x = 0;
      y = ch;
    } else {
      x = ch - m + 1;
      y = m - 1;
    }
  }
  arr[x][y] = cur_num;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cout << arr[i][j] << ' ';
    }
    cout << '\n';
  }

  return 0;
}
