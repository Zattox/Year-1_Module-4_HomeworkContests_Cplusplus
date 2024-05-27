#include <iostream>
#include <unordered_map>

using std::cin, std::cout;
using std::string;

int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n = 0;
  cin >> n;
  std::unordered_map<string, string> dict;

  for (int i = 0; i < n; ++i) {
    string word;
    string synonym;
    cin >> word >> synonym;
    dict[word] = synonym;
    dict[synonym] = word;
  }

  int q = 0;
  cin >> q;
  for (int i = 0; i < q; ++i) {
    string question;
    cin >> question;
    cout << dict[question] << '\n';
  }

  return 0;
}
