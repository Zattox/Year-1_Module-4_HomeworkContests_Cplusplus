#include <iostream>
#include <unordered_map>
#include <queue>
#include <vector>

using std::cin, std::cout;

struct Request {
  int user_id;
  int time;
};

bool operator>(const Request &r1, const Request &r2) {
  if (r1.time == r2.time) {
    return r1.user_id > r2.user_id;
  }
  return r1.time > r2.time;
}

void Solve() {
  size_t m = 0;
  cin >> m;

  int user_id = 0;
  int cur_time = 0;
  std::unordered_map<int, int> cache;
  std::priority_queue<Request, std::vector<Request>, std::greater<>> queue;
  while (cin >> user_id) {
    if (cache.find(user_id) == cache.end()) {
      cout << "1 ";
    } else {
      cout << "0 ";
    }
    queue.push({user_id, cur_time});
    cache[user_id] = cur_time;
    if (cache.size() > m) {
      Request oldest = queue.top();
      while (cache[oldest.user_id] != oldest.time) {
        queue.pop();
        oldest = queue.top();
      }
      queue.pop();
      cache.erase(oldest.user_id);
    }
    ++cur_time;
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  cin.tie(nullptr);
  cout.tie(nullptr);

  Solve();

  return 0;
}
