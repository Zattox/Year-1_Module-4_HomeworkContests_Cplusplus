#include <iostream>
#include <vector>
#include <algorithm>

using std::cin, std::cout;
using std::vector;

int main() {
  int n;
  cin >> n;
  vector<int> arr(n);

  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }

  int m;
  cin >> m;
  for (int i = 0; i < m; ++i) {
    int number;
    cin >> number;
    auto count = std::upper_bound(arr.begin(), arr.end(), number) - std::lower_bound(arr.begin(), arr.end(), number);
    cout << count << "\n";
  }

  return 0;
}
