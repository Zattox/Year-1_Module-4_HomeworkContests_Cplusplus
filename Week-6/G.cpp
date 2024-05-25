#include <iostream>
#include <map>

using std::cin, std::cout;
using std::string;

int main() {
  int n;
  cin >> n;
  std::map<string, string> mp;

  for (int i = 0; i < n; ++i) {
    string a, b;
    cin >> a >> b;
    mp[a] = b;
    mp[b] = a;
  }

  int q;
  cin >> q;
  for (int i = 0; i < n; ++i) {
    string question;
    cin >> question;
    cout << mp[question] << '\n';
  }

  return 0;
}
