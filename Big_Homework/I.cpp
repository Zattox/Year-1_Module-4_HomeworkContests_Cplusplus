#include <iostream>
#include <string>
#include <unordered_map>

using std::cin, std::cout;

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  std::ios_base::sync_with_stdio(false);

  std::unordered_map<std::string, int> word_count;
  std::string word;
  while (cin >> word) {
    cout << word_count[word] << ' ';
    ++word_count[word];
  }
}