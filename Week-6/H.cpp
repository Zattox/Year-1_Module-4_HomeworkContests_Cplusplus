#include <iostream>
#include <map>
#include <cstdint>

using std::cin, std::cout;
using std::string, std::map;

int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  string name;
  string product;
  map<string, map<string, int64_t>> people;

  int64_t cnt = 0;
  while (cin >> name >> product >> cnt) {
    people[name][product] += cnt;
  }

  for (const auto &man : people) {
    cout << man.first << ":\n";
    for (const auto &el : man.second) {
      cout << el.first << ' ' << el.second << '\n';
    }
  }

  return 0;
}