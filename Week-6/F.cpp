#include <iostream>
#include <queue>

using std::cin, std::cout;

int main() {
  int n;
  cin >> n;
  std::priority_queue<int, std::vector<int>, std::greater<>> coins;

  for (int i = 0; i < n; ++i) {
    int num;
    cin >> num;
    coins.push(num);
  }

  double answer = 0;
  while (coins.size() > 1) {
    int first_num = coins.top();
    coins.pop();
    int second_num = coins.top();
    coins.pop();
    int result = first_num + second_num;
    answer += result * 0.05;
    coins.push(result);
  }

  cout.precision(10);
  cout << std::fixed << answer;

  return 0;
}
