#include <iostream>
#include <vector>

int main() {
  std::ios_base::sync_with_stdio(false);
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n, k;
  std::cin >> n >> k;

  std::vector<std::vector<int>> arr(n + 1);
  for (int i = 0; i < k; ++i) {
    int command;
    std::cin >> command;
    if (command == 1) {
      int u, v;
      std::cin >> u >> v;
      arr[v - 1].push_back(u - 1);
      arr[u - 1].push_back(v - 1);
    } else if (command == 2) {
      int v;
      std::cin >> v;
      for (auto &el : arr[v - 1]) {
        std::cout << el + 1 << ' ';
      }
      std::cout << "\n";
    }
  }

  return 0;
}
