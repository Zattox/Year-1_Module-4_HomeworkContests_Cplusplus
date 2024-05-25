#include <iostream>
#include <map>

using std::cin, std::cout;

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  std::map<std::string, int> mp;
  std::string word;
  int maxi = -1;
  while (cin >> word) {
    mp[word]++;
    maxi = std::max(maxi, mp[word]);
  }

  for (auto &el : mp) {
    if (el.second == maxi) {
      cout << el.first;
      break;
    }
  }
  return 0;
}
