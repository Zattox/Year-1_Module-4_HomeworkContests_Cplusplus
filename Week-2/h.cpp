#include <iostream>
#include <cmath>
#include <iomanip>

using std::cin, std::cout;

double Dist(std::pair<int, int> x, std::pair<int, int> y) {
  int64_t first = x.first - y.first;
  int64_t second = x.second - y.second;
  return sqrt(first * first + second * second);
}

int main() {
  std::pair<int, int> x, y, z;
  cin >> x.first >> x.second;
  cin >> y.first >> y.second;
  cin >> z.first >> z.second;

  double perimetr = Dist(x, y) + Dist(x, z) + Dist(y, z);
  cout << std::fixed << std::setprecision(6) << perimetr;

  return 0;
}
