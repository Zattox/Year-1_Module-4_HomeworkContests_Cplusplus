#include <iostream>

using std::cin, std::cout;

const int kMaxN = 50;

int main() {
  int n;
  int arr[kMaxN][kMaxN];

  cin >> n;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      arr[i][j] = 0;
    }
  }
  for (int i = 0; i < n; ++i) {
    arr[0][i] = 1;
    arr[i][n - 1] = 1;
    arr[n - 1][i] = 1;
  }

  int cur_cnt = n - 2, ch = 2;
  int cur_x = 0, cur_y = n - 1;
  int dx = 0, dy = -1;
  while (cur_cnt > 0) {
    for (int i = 0; i < cur_cnt; ++i) {
      arr[cur_y][cur_x] = 1;
      cur_x += dx;
      cur_y += dy;
    }
    cur_x -= dx, cur_y -= dy;

    if (dx == 1 && dy == 0) {
      dx = 0, dy = 1;
    } else if (dx == 0 && dy == 1) {
      dx = -1, dy = 0;
    } else if (dx == -1 && dy == 0) {
      dx = 0, dy = -1;
    } else if (dx == 0 && dy == -1) {
      dx = 1, dy = 0;
    }

    ++ch;
    if (ch % 2 == 0) {
      cur_cnt -= 2;
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cout << arr[i][j];
    }
    cout << '\n';
  }

  return 0;
}
