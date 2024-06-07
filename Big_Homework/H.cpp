#include <iostream>
#include <vector>
#include <queue>
#include <cstdint>

using std::cin, std::cout;

int main() {
  int n = 0;
  cin >> n;

  std::priority_queue<int64_t, std::vector<int64_t>, std::greater<>> provinces;
  for (int i = 0; i < n; ++i) {
    int64_t residents = 0;
    cin >> residents;
    provinces.push(residents);
  }

  int64_t answer = 0;
  while (provinces.size() > 1) {
    int64_t province1 = provinces.top();
    provinces.pop();
    int64_t province2 = provinces.top();
    provinces.pop();
    provinces.push(province1 + province2);

    answer += province1 + province2;
  }

  cout << answer;

  return 0;
}