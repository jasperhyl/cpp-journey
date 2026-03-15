// 使用raii的原理实现一个SmartPtr类
#include <exception>
#include <iostream>
#include <stdexcept>

template <class T>
class SmartPtr {
public:
  SmartPtr(T *ptr = nullptr)
      : _ptr(ptr) {}
  ~SmartPtr() {
    if (_ptr) {
      delete _ptr;
      std::cout << "释放掉一个" << std::endl;
    }
  }
  T &operator*() { return *_ptr; }
  // 这里的返回值是左值引用是因为，解引用就是要返回一个可修改低层对象的左值引用
  // int x = 10;
  // int* p = &x;
  //*p = 100;
  T *operator->() { return _ptr; }

private:
  T *_ptr;
};

class Date {
public:
  Date() {}
  ~Date() {}
  int _year = 2026;
  int _month = 1;
  int _day = 1;
};

double div() {
  double a, b;
  std::cin >> a >> b;
  if (b == 0) {
    throw std::invalid_argument("除0错误");
  }
  return a / b;
}
void Func() {
  SmartPtr<int> a(new int);
  *a = 100; // 测试一下模仿指针的行为
  std::cout << *a;
  SmartPtr<int> b(new int);
  std::cout << div() << std::endl;
}
int main() {
  try {
    Func();
  } catch (const std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  // 支持默认的指针行为，即*和->
  SmartPtr<Date> date(new Date);
  date->_year = 2018;
  std::cout << date->_year << std::endl;
  return 0;
}