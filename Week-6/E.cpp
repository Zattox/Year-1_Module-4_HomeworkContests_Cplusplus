#include <iostream>
#include <algorithm>
#include <cstdint>

using std::cin, std::cout;

struct Row {
  int ind = 0;
  int16_t tasks = 0;
  int penalty = 0;
};

bool Cmp(const Row &r1, const Row &r2) {
  if (r1.tasks == r2.tasks) {
    if (r1.penalty == r2.penalty) {
      return r1.ind < r2.ind;
    }
    return r1.penalty < r2.penalty;
  }
  return r1.tasks > r2.tasks;
}

int main() {
  const int max_n = 100000;
  int n = 0;
  cin >> n;

  Row arr[max_n];
  for (int i = 0; i < n; ++i) {
    arr[i].ind = i + 1;
    cin >> arr[i].tasks >> arr[i].penalty;
  }

  std::sort(arr, arr + n, Cmp);

  for (int i = 0; i < n; ++i) {
    cout << arr[i].ind << '\n';
  }

  return 0;
}
