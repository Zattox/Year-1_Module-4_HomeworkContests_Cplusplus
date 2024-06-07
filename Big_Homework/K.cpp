#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

using std::cin, std::cout;
using std::vector, std::string;

std::unordered_set<string> FindSubstr(const string &main_str) {
  std::unordered_set<string> all_substr;
  for (size_t i = 0; i < main_str.size(); ++i) {
    string substr;
    for (size_t j = i; j < main_str.size(); ++j) {
      substr += main_str[j];
      all_substr.insert(substr);
    }
  }
  return all_substr;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n = 0;
  cin >> n;

  vector<string> password(n);
  std::unordered_map<string, int> all_substr;
  for (int i1 = 0; i1 < n; ++i1) {
    string passphrase;
    cin >> passphrase;
    password[i1] = passphrase;

    std::unordered_set<string> substr_of_pass = FindSubstr(passphrase);
    for (auto &elem : substr_of_pass) {
      all_substr[elem] += 1;
    }
  }

  int answer = 0;
  for (int i = 0; i < n; ++i) {
    answer += all_substr[password[i]] - 1;
  }

  cout << answer;
}