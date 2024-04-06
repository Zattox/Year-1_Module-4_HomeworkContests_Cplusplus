#include <iostream>

using std::cin, std::cout;

int main() {
  std::string number;
  cin >> number;

  int sum = 0, length = number.size();
  for (int i = 0; i < length; ++i) {
    sum += number[i] - '0';
  }

  cout << sum;
  return 0;
}
