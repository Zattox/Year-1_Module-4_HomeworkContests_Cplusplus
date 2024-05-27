#include <iostream>
#include <vector>

using std::cin, std::cout;
using std::vector;

int main() {
  const int max_num = 1001;

  int n;
  cin >> n;
  vector<int> count(max_num);
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    ++count[x];
  }

  int question;
  cin >> question;
  cout << count[question];

  return 0;
}
