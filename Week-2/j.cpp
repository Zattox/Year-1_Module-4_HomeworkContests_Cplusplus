#include <iostream>
#include <algorithm>

using std::cin, std::cout;

void Sort(int* begin, int* end) {
  for (int* i = begin; i <= end; ++i) {
    for (int* j = i + 1; j <= end; ++j) {
      if (*i > *j) {
        int t = *i;
        *i = *j;
        *j = t;
      }
    }
  }
}

int main() {
  int n;
  int arr[10000];
  cin >> n;

  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }

  Sort(&arr[0], &arr[n - 1]);

  for (int i = 0; i < n; ++i) {
    cout << arr[i] << ' ';
  }

  return 0;
}
