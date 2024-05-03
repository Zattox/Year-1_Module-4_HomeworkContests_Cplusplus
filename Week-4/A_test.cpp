#include "rational.h"
#include "rational.cpp"
#include <cassert>
#include <string>
#include <type_traits>
#include <utility>

using std::cin, std::cout;

int main() {
  try {
    Rational x = 5, y, z(7, 11);
    cout << x << ' ' << y << ' ' << z << std::endl;

    cout << z.GetNumerator() << ' ' << z.GetDenominator() << std::endl;

    y.SetNumerator(22);
    cout << y << std::endl;
    y.SetDenominator(13);
    cout << y << std::endl;

    cout << "x := " << x << " y := " << y << "\n";
    cout << x + y << ' ' << x - y << ' ' << x * y << ' ' << x / y << std::endl;

    Rational res1 = x, res2 = x, res3 = x, res4 = x;
    res1 += y;
    res2 -= y;
    res3 *= y;
    res4 /= y;
    cout << res1 << ' ' << res2 << ' ' << res3 << ' ' << res4 << std::endl;

    cout << +x << ' ' << -x << std::endl;
    cout << ++x << ' ' << --x << ' ' << x++ << ' ' << x-- << std::endl;

    cout << (x == y) << ' ' << (x != y) << ' ' << (x < y) << ' ' << (x > y) << std::endl;

    (y += std::as_const(x)) = {-13, 3};

    if (0 > x) {
      cout << "test 1\n";
    }
    if (x < 0) {
      cout << "test 2\n";
    }

    Rational rational;
    int numerator = 7;
    if (rational.GetNumerator() == numerator) {
      cout << 12;
    }

    cin >> rational;
    cout << rational;
  } catch (const std::exception e){
    std::cerr << e.what() << std::endl;
  }
  return 0;
}
