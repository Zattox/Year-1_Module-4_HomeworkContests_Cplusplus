#include <iostream>
#include <string>
#include <vector>

using std::cin, std::cout, std::string, std::vector;

int main() {
  string str;
  vector<char> st;
  cin >> str;

  int ans = 0, n = str.size();
  for (int i = 0; i < n; ++i) {
    if (str[i] == '(') {
      st.push_back(str[i]);
    } else {
      if (st.empty()) {
        ++ans;
      } else {
        st.pop_back();
      }
    }
  }
  ans += st.size();

  cout << ans;

  return 0;
}