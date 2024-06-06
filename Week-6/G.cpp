#include <iostream>
#include <unordered_map>

using std::cin, std::cout;
using std::string;

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  std::ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n = 0;
  std::unordered_map<string, string> dict;
  cin >> n;

  string word;
  string synonym;
  for (int i = 0; i < n; ++i) {
    cin >> word >> synonym;
    dict[word] = synonym;
    dict[synonym] = word;
  }

  int q = 0;
  cin >> q;
  string question;
  for (int i = 0; i < q; ++i) {
    cin >> question;
    cout << dict[question] << '\n';
  }

  return 0;
}