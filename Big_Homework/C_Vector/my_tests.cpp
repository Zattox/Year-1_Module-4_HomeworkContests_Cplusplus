#include <iostream>
#include <string>
#include <string_view>
#include <vector>
#include <type_traits>
#include "vector.h"
#include <memory>

void test1() {
  std::vector<int> arr = {1, 2, 3, 4, 5};
  std::cout << "arr == {1, 2, 3, 4, 5 }\n========================================================\n";
  std::cout << ".begin() 0 +1 -1 : " << *arr.begin() << " ; " << *(++arr.begin()) << " ; " << *(--arr.begin()) << '\n';
  std::cout << ".cbegin() 0 +1 -1 : " << *arr.cbegin() << " ; " << *(++arr.cbegin()) << " ; " << *(--arr.cbegin())
            << '\n';
  std::cout << ".rbegin() 0 +1 -1 : " << *arr.rbegin() << " ; " << *(++arr.rbegin()) << " ; " << *(--arr.rbegin())
            << '\n';
  std::cout << ".crbegin() 0 +1 -1 : " << *arr.crbegin() << " ; " << *(++arr.crbegin()) << " ; " << *(--arr.crbegin())
            << '\n';

  std::cout << "========================================================\n";

  std::cout << ".end() 0 +1 -1 : " << *arr.end() << " ; " << *(++arr.end()) << " ; " << *(--arr.end()) << '\n';
  std::cout << ".cend() 0 +1 -1 : " << *arr.cend() << " ; " << *(++arr.cend()) << " ; " << *(--arr.cend()) << '\n';
  std::cout << ".rend() 0 +1 -1 : " << *arr.rend() << " ; " << *(++arr.rend()) << " ; " << *(--arr.rend()) << '\n';
  std::cout << ".crend() 0 +1 -1 : " << *arr.crend() << " ; " << *(++arr.crend()) << " ; " << *(--arr.crend()) << '\n';

  std::cout << "========================================================\n";
}

void test2() {
  std::vector<int> arr = {1, 2, 3, 4, 5, 6};
  std::cout << arr.size() << ' ' << arr.capacity() << "\n";
  arr.resize(2);
  std::cout << arr.size() << ' ' << arr.capacity() << "\n";
  arr.pop_back();
  std::cout << arr.size() << ' ' << arr.capacity() << "\n";
  arr.clear();
  std::cout << arr.size() << ' ' << arr.capacity() << "\n";
  arr.pop_back();
  std::cout << arr.size() << ' ' << arr.capacity() << "\n";
}

void test3() {
  std::vector<int> arr1 = {1, 2, 3};
  std::vector<int> arr2 = {1, 2, 7};
  std::vector<int> arr3 = {1, 2, 1};
  std::cout << (arr1 < arr2) << ' ' << (arr1 > arr3) << "\n";
  std::vector<int> arr4 = {1, 2};
  std::vector<int> arr5 = {1, 2, 3, 0};
  std::cout << (arr1 > arr4) << ' ' << (arr1 < arr5) << "\n";
}

void test4() {
  std::vector<int> arr = {1, 2, 3, 4};
  auto x = arr.end() - arr.begin();
  std::cout << x << "\n";
  auto y = arr.begin() - arr.end();
  std::cout << y << "\n";
}

void test5() {
  int *arr = new int[2];
  delete[] arr;

  int *gg = new int[4];
  gg[0] = 12;
  gg[3] = 211;
  std::move(gg, gg + 4, arr);
  std::cout << arr[0] << ' ' << arr[3];
}

void test6() {
  Vector<std::unique_ptr<int>> empty;
  empty.Reserve(10u);
  empty.ShrinkToFit();

  Vector<std::unique_ptr<int>> v;
  v.Reserve(0u);
  v.Resize(0u);
  v.PushBack(std::make_unique<int>(1));
}

void test7() {
  const Vector<int> v(0, 5);
  int x = 0;
}

void test8() {
  const Vector<int> empty;
  const auto v = empty;
  int y = 0;
}

void test9() {
  Vector<std::vector<int>> values{{1, 2}, {3, 4, 5}};
  const auto v = std::move(values);
  int z = 0;
  std::cout << (values.Size() == 0u);
  std::cout << (values.Capacity() == 0u);
  std::cout << (values.Data() == nullptr);
}

void test10() {
  const Vector<int> empty;
  Vector<int> v{1, 2, 3};
  v = empty;
}

void test_che() {
  int *arr = new int[2];
  delete[] arr;
  std::cout << (arr == nullptr);
}

template <class T>
void Equal(const Vector<T>& real, const std::vector<T>& required) {
  std::cout << std::endl << "EQUAL: ";
  std::cout << (real.Size() == required.size());
  for (size_t i = 0u; i < real.Size(); ++i) {
    std::cout << (real[i] == required[i]);
  }
  std::cout << std::endl;
}

void test11() {
  Vector<int> values{1, 2, 3};
  const auto p_values = values.Data();
  Vector<int> v;
  v = std::move(values);
  Equal(v, std::vector<int>{1, 2, 3});
  std::cout << (p_values == v.Data());
  std::cout << (values.Size() == 0u);
  std::cout << (values.Capacity() == 0u);
  std::cout << (values.Data() == nullptr);

  v = Vector<int>{4, 5, 6};
  Equal(v, std::vector<int>{4, 5, 6});
  std::cout << (p_values != v.Data());
}

void test12() {
  Vector<std::vector<int>> values{{1, 2}, {3, 4, 5}};
  const auto v = std::move(values);
  Equal(v, std::vector<std::vector<int>>{{1, 2}, {3, 4, 5}});
  std::cout <<(values.Size() == 0u);
  std::cout <<(values.Capacity() == 0u);
  std::cout <<(values.Data() == nullptr);
}

void test13() {
  Vector<int> empty;
  empty.Reserve(10u);
  Equal(empty, std::vector<int>{});
  std::cout <<(empty.Capacity() >= 10u);
  std::cout <<(empty.Data() != nullptr);
}

void test14() {
  Vector<int> v;
  v.Resize(5u, 11);
  Equal(v, std::vector<int>(5u, 11));
  std::cout <<(v.Capacity() >= 5u);
  std::cout <<(v.Capacity() <= 10u);
}

void test15() {
  Vector<std::unique_ptr<int>> v;
  for (int i = 0; i < 100; ++i) {
    v.PushBack(std::make_unique<int>(i));
    std::cout <<(v.Size() == static_cast<unsigned>(i + 1));
    std::cout <<(v.Capacity() >= v.Size());
    std::cout <<(v.Capacity() <= 2 * v.Size());
  }
  for (int i = 0; i < 100; ++i) {
    std::cout <<(*v[i] == i);
  }
}

class Exception {};

class Throwable {
  std::unique_ptr<int> p_ = std::make_unique<int>();  // check d-tor is called

 public:
  static int until_throw;

  Throwable() {
    --until_throw;
    if (until_throw <= 0) {
      throw Exception{};
    }
  }

  Throwable(const Throwable&) : Throwable() {
  }

  Throwable(Throwable&&) noexcept = default;

  Throwable& operator=(const Throwable&) {
    --until_throw;
    if (until_throw <= 0) {
      throw Exception{};
    }
    return *this;
  }

  Throwable& operator=(Throwable&&) noexcept = default;
};

int Throwable::until_throw = 0;
void test16(){
  Throwable::until_throw = 200;
  Vector<Throwable> v;
  v.Reserve(100u);
  const auto capacity = v.Capacity();
  const auto data = v.Data();
  Throwable::until_throw = static_cast<int>(capacity) + 2;
  for (size_t i = 0; i < capacity; ++i) {
    v.PushBack({});
  }
}

void test17() {
  const Vector<int> large(1000, 11);
  Vector<int> small{1, 2, 3};
  small = large;
  Equal(large, std::vector<int>(1000, 11));
  Equal(small, std::vector<int>(1000, 11));
}

int main() {
  test17();
  return 0;
}