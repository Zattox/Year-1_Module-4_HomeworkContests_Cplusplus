#include <iostream>
#include <algorithm>
#include <vector>

using std::cin, std::cout;
using std::vector, std::pair;

struct row {
  int ind = 0;
  int tasks = 0;
  int penalty = 0;
};

bool cmp(const row &r1, const row &r2) {
  if (r1.tasks == r2.tasks) {
    if (r1.penalty == r2.penalty) {
      return r1.ind < r2.ind;
    }
    return r1.penalty < r2.penalty;
  }
  return r1.tasks > r2.tasks;
}

int main() {
  int n;
  cin >> n;
  vector<row> arr(n);

  for (int i = 0; i < n; ++i) {
    arr[i].ind = i + 1;
    cin >> arr[i].tasks >> arr[i].penalty;
  }

  std::sort(arr.begin(), arr.end(), cmp);

  for (auto &el : arr) {
    cout << el.ind << '\n';
  }

  return 0;
}
