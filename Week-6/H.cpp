#include <iostream>
#include <map>
#include <cstdint>

using std::cin, std::cout;
using std::string, std::map;

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  map<string, map<string, int64_t>> mp;
  string name, product;
  int64_t cnt;
  while (cin >> name >> product >> cnt) {
    mp[name][product] += cnt;
  }

  for (auto &man : mp) {
    cout << man.first << ":\n";
    for (auto &el : man.second) {
      cout << el.first << ' ' << el.second << '\n';
    }
  }

  return 0;
}
