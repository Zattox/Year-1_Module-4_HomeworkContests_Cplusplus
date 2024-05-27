#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using std::cin, std::cout;
using std::vector, std::string, std::pair;
using std::unordered_map;

bool cmp(const pair<string, int> &p1, const pair<string, int> &p2) {
  if (p1.second == p2.second) {
    return p1.first < p2.first;
  }
  return p1.second > p2.second;
}

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  unordered_map<string, int> dict_cnt;
  string word;
  while (cin >> word) {
    ++dict_cnt[word];
  }

  vector<pair<string, int>> dict_ans;
  dict_ans.reserve(dict_cnt.size());
  for (auto &el : dict_cnt) {
    dict_ans.emplace_back(el);
  }

  std::sort(dict_ans.begin(), dict_ans.end(), cmp);
  for (auto &el : dict_ans) {
    cout << el.first << "\n";
  }

  return 0;
}
