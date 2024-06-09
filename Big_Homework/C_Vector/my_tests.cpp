#include <iostream>
#include <vector>
#include <string>
#include <string_view>
#include <type_traits>
#include "vector.h"
#include <memory>

void test1() {
  std::vector<int> arr = {1, 2, 3, 4, 5};
  std::cout << "arr == {1, 2, 3, 4, 5}\n========================================================\n";
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

void test11() {
  const Vector<int> large(1000, 11);
  Vector<int> small{1, 2, 3};
  small = large;
}

void test_it1() {
  std::cout << "test_id1 : ";
  using ConstIterator = Vector<int>::ConstIterator;

  std::cout << (std::is_same_v<ConstIterator, decltype(std::declval<const Vector<int>>().begin())>);
  std::cout << (std::is_same_v<ConstIterator, decltype(std::declval<const Vector<int>>().end())>);

  using Traits = std::iterator_traits<ConstIterator>;
  std::cout << ((std::is_same_v<Traits::value_type, int>));
  std::cout << ((std::is_same_v<Traits::reference, decltype(*std::declval<ConstIterator>())>));
  std::cout << ((std::is_base_of_v<std::random_access_iterator_tag, Traits::iterator_category>));

}

void test_it2() {
  std::cout << "test_id2 : ";

  using ReverseIterator = Vector<int>::ReverseIterator;
  std::cout << ((std::is_same_v<ReverseIterator, decltype(std::declval<Vector<int>>().rbegin())>));
  std::cout <<((std::is_same_v<ReverseIterator, decltype(std::declval<Vector<int>>().rend())>));
  std::cout <<((std::is_same_v<ReverseIterator, std::reverse_iterator<Vector<int>::Iterator>>));

  using Traits = std::iterator_traits<ReverseIterator>;
  std::cout <<((std::is_same_v<Traits::value_type, int>));
  std::cout <<((std::is_same_v<Traits::reference, decltype(*std::declval<ReverseIterator>())>));
  std::cout <<((std::is_base_of_v<std::random_access_iterator_tag, Traits::iterator_category>));
}

void test_it2_2(){
  Vector<int> v(10u);
  int i = 0;
  for (auto it = v.rbegin(); it != v.rend(); ++it) {
    *it = ++i;
  }
  i = 11;
  for (auto& x : v) {
    std::cout << (x == --i);
  }
}

void test_it3() {
  std::cout << "test_id3 : ";
  using ConstReverseIterator = Vector<int>::ConstReverseIterator;
  std::cout <<((std::is_same_v<ConstReverseIterator, decltype(std::declval<Vector<int>>().crbegin())>));
  std::cout <<((std::is_same_v<ConstReverseIterator, decltype(std::declval<Vector<int>>().crend())>));
  std::cout <<((std::is_same_v<ConstReverseIterator, decltype(std::declval<const Vector<int>>().rbegin())>));
  std::cout <<((std::is_same_v<ConstReverseIterator, decltype(std::declval<const Vector<int>>().rend())>));
  std::cout <<((std::is_same_v<ConstReverseIterator, std::reverse_iterator<Vector<int>::ConstIterator>>));

  using Traits = std::iterator_traits<ConstReverseIterator>;
  std::cout <<((std::is_same_v<Traits::value_type, int>));
  std::cout <<((std::is_same_v<Traits::reference, decltype(*std::declval<ConstReverseIterator>())>));
  std::cout <<((std::is_base_of_v<std::random_access_iterator_tag, Traits::iterator_category>));
}

int main() {
  test_it2_2();
  return 0;
}