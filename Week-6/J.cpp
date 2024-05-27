#include <iostream>
#include <set>
#include <queue>

using std::cin, std::cout;
using std::pair, std::vector;

struct MyCompare {
  bool operator()(std::pair<int, int> left, std::pair<int, int> right) {
    return left.first > right.first;
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  size_t m = 0;
  cin >> m;
  int number = 0;
  int counter_cache = 0;
  std::set<int> cur_users;
  std::priority_queue<std::pair<int, int>, vector<pair<int, int>>, MyCompare> cache;
  while (cin >> number) {
    if (cur_users.count(number) > 0) {
      cache.emplace(counter_cache, number);
      ++counter_cache;
      cur_users.insert(number);
      cout << "0 ";
    } else {
      while (cache.size() >= m) {
        auto top_elem = cache.top();
        cache.pop();
        cur_users.erase(cur_users.find(top_elem.second));
      }
      cur_users.insert(number);
      cache.emplace(counter_cache, number);
      ++counter_cache;
      cout << "1 ";
    }
  }

  return 0;
}
