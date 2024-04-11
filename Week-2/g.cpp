#include <iostream>

using std::cin, std::cout;

bool IsDigit(unsigned char c) {
  return (c >= '0') && (c <= '9');
}

int main() {
  char sym;
  cin >> sym;

  if (IsDigit(sym)) {
    cout << "yes";
  } else {
    cout << "no";
  }

  return 0;
}
