#include <iostream>

using std::cin, std::cout;

const int kMaxN = 204;

int main() {
  int n, m, w;
  char arr[kMaxN][kMaxN];

  cin >> n >> m >> w;
  for (int i = 0; i <= n + 1; ++i) {
    for (int j = 0; j <= m + 1; ++j) {
      arr[i][j] = '0';
    }
  }
  for (int i = 0; i < w; ++i) {
    int x, y;
    cin >> x >> y;
    arr[x][y] = '*';
  }

  int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
  int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (arr[i][j] != '*') {
        int cnt = 0;
        for (int k = 0; k < 8; ++k) {
          int new_x = i + dx[k];
          int new_y = j + dy[k];
          cnt += (arr[new_x][new_y] == '*');
        }
        arr[i][j] = '0' + cnt;
      }
    }
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cout << arr[i][j] << ' ';
    }
    cout << '\n';
  }

  return 0;
}
