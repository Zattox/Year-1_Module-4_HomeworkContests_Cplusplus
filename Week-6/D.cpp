#include <iostream>
#include <vector>
#include <unordered_map>

using std::cin, std::cout;
using std::unordered_map, std::vector;

int main() {
  int n = 0;
  cin >> n;

  int counter = 0;
  vector<int> count(n + 1);
  unordered_map<int, int> cur(n);
  for (int i = 0; i < n; ++i) {
    int x = 0;
    cin >> x;
    if (cur.find(x) == cur.end()) {
      cur[x] = counter;
      ++counter;
    }
    ++count[cur[x]];
  }

  int m = 0;
  cin >> m;
  for (int i = 0; i < m; ++i) {
    int number = 0;
    cin >> number;
    if (cur.find(number) == cur.end()) {
      cout << 0 << '\n';
    } else {
      cout << count[cur[number]] << '\n';
    }
  }

  return 0;
}
