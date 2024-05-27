#include <iostream>
#include <set>
#include <queue>

using namespace std;

long long getrand() {
  return (rand() * 32768) + rand();
}

vector<int> wa_solve(size_t m, vector<int> &question) {
  int counter_cache = 0;
  vector<int> answer;
  std::multiset<int> cur_users;
  std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> cache;
  for (auto number : question) {
    if (cur_users.count(number) > 0) {
      cache.emplace(counter_cache, number);
      ++counter_cache;
      cur_users.insert(number);
      answer.push_back(0);
    } else {
      while (cache.size() >= m) {
        auto top_elem = cache.top();
        cache.pop();
        cur_users.erase(cur_users.find(top_elem.second));
      }
      cur_users.insert(number);
      cache.emplace(counter_cache, number);
      ++counter_cache;
      answer.push_back(1);
    }
  }
  return answer;
}

vector<int> tl_solve(size_t m, vector<int> &question) {
  int counter_cache = 0;
  std::set<int> cur_users;
  vector<int> answer;
  std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> cache;
  for (auto number : question){
    if (cur_users.count(number) > 0) {
      std::vector<std::pair<int, int>> elems;
      while (cache.top().second != number) {
        elems.push_back(cache.top());
        cache.pop();
      }
      cache.pop();
      for (auto &el : elems) {
        cache.push(el);
      }
      cache.emplace(counter_cache, number);
      ++counter_cache;
      answer.push_back(0);
    } else {
      if (cache.size() == m) {
        auto top_elem = cache.top();
        cache.pop();
        cur_users.erase(top_elem.second);
      }
      cur_users.insert(number);
      cache.emplace(counter_cache, number);
      ++counter_cache;
      answer.push_back(1);
    }
  }
  return answer;
}

int main() {
  freopen("tests.txt", "w", stdout);

  int xxx = 0;
  while (xxx < 10) {
    int size_cache = getrand() % 5 + 1;
    int size_ques = getrand() % 20 + 1;
    vector<int> arr (size_ques, 0);
    for (auto &el : arr) {
      el = getrand() % 30;
    }
    auto wa_ans = wa_solve(size_cache, arr);
    auto tl_ans = tl_solve(size_cache, arr);
    if (wa_ans != tl_ans) {
      cout << size_cache << '\n';
      for (auto el : arr) {
        cout << el << ' ';
      }
      cout << "\nwa_ans:\n";
      for (auto el : wa_ans) {
        cout << el << ' ';
      }
      cout << "\ntl_ans:\n";
      for (auto el : tl_ans) {
        cout << el << ' ';
      }
      ++xxx;
      cout << "\n=============\n";
    }
  }

  return 0;
}
