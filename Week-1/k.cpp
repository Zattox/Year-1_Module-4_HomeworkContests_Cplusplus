#include <iostream>

using std::cin, std::cout;

int main() {
  int x;
  cin >> x;

  int first_max = 0, second_max = 0;
  while (x != 0) {
    if (x > first_max) {
      second_max = first_max;
      first_max = x;
    } else if (x > second_max) {
      second_max = x;
    }

    cin >> x;
  }

  cout << second_max;
  return 0;
}
