#include <iostream>
#include <unordered_map>

using std::cin, std::cout;
using std::unordered_map;

int main() {
  int n = 0;
  cin >> n;
  unordered_map<int, int> count;
  for (int i = 0; i < n; ++i) {
    int x = 0;
    cin >> x;
    ++count[x];
  }

  int question = 0;
  cin >> question;
  cout << count[question];

  return 0;
}
