#include <iostream>
#include <cstdlib>

using std::cin, std::cout, std::string;

template <class T>
class MyStack {
 private:
  T *arr_;
  int head_;
  size_t capacity_;

 public:
  MyStack() {
    head_ = -1;
    capacity_ = 100;
    arr_ = new T[capacity_];
  }
  void Push(T x) {
    ++head_;
    arr_[head_] = x;
  }
  T Pop() {
    --head_;
    return arr_[head_ + 1];
  }
  void TaskClear() {
    head_ = -1;
  }
  size_t Size() {
    return head_ + 1;
  }
  T Back() {
    return arr_[head_];
  }
  void FullClear() {
    delete[] arr_;
  }
};

int main() {
  int n;
  cin >> n;

  MyStack<int> st;
  for (int i = 0; i < n; ++i) {
    string comand;
    cin >> comand;
    if (comand == "push") {
      int x;
      cin >> x;
      st.Push(x);
      cout << "ok\n";
    } else if (comand == "pop") {
      int x = st.Pop();
      cout << x << '\n';
    } else if (comand == "back") {
      int x = st.Back();
      cout << x << '\n';
    } else if (comand == "size") {
      int x = st.Size();
      cout << x << '\n';
    } else if (comand == "clear") {
      st.TaskClear();
      cout << "ok" << '\n';
    } else {
      cout << "bye" << '\n';
      break;
    }
  }

  st.FullClear();
  return 0;
}