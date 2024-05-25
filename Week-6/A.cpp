#include <iostream>
#include <vector>

using std::cin, std::cout;
using std::vector;

int main() {
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;

  vector<vector<int>> arr(n + 1);
  for (int i = 0; i < k; ++i) {
    int command;
    cin >> command;
    if (command == 1) {
      int u, v;
      cin >> u >> v;
      arr[v - 1].push_back(u - 1);
      arr[u - 1].push_back(v - 1);
    } else if (command == 2) {
      int v;
      cin >> v;
      for (auto &el : arr[v - 1]) {
        cout << el + 1 << ' ';
      }
      cout << "\n";
    }
  }

  return 0;
}
