#include <iostream>
#include <unordered_map>

using std::cin, std::cout;
using std::unordered_map, std::string;

int main() {
  int n = 0;
  cin >> n;

  unordered_map<string, int> bank;
  for (int i = 0; i < n; ++i) {
    int command = 0;
    string name;
    cin >> command >> name;
    if (command == 1) {
      int delta = 0;
      cin >> delta;
      bank[name] += delta;
    } else {
      if (bank.find(name) != bank.end()) {
        cout << bank[name];
      } else {
        cout << "ERROR";
      }
      cout << "\n";
    }
  }

  return 0;
}
