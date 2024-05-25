#include <iostream>
#include <map>

using std::cin, std::cout;
using std::map, std::string;

int main() {
  int n;
  cin >> n;

  map<string, int> bank;
  for (int i = 0; i < n; ++i) {
    int command;
    string name;
    cin >> command >> name;
    if (command == 1) {
      int delta;
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
