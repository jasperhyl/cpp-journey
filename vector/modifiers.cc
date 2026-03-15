#include <algorithm>
#include <iostream>
#include <vector>
int main() {
  std::vector<int> a = {1, 2, 3, 4, 5};
  a.clear();
  std::cout << a.size() << std::endl;
  a = {6, 7, 8, 9};
  auto pos = a.insert(a.begin() + 2, 4, 11);
  std::cout << *(pos - 1) << std::endl;
  std::vector<int> b(10, 0);
#ifdef __cpp_lib_containers_ranges
  a.insert_range(a.end(), b);
#else
  std::cout << "请使用C++23及以上编译" << std::endl;
#endif

  std::for_each(a.begin(), a.end(), [](int x) {
    std::cout << x << " ";
  });
  std::cout << std::endl;

  a.erase(a.begin());
  std::for_each(a.begin(), a.end(), [](int x) {
    std::cout << x << " ";
  });
  std::cout << std::endl;

  a.emplace(a.begin() + 1, 66);
  a.push_back(77);
  a.emplace_back(99);
  std::for_each(a.begin(), a.end(), [](int x) {
    std::cout << x << " ";
  });
  std::cout << std::endl;

  a.append_range(b);
  std::for_each(a.begin(), a.end(), [](int x) {
    std::cout << x << " ";
  });
  std::cout << std::endl;

  a.pop_back();
  std::for_each(a.begin(), a.end(), [](int x) {
    std::cout << x << " ";
  });
  std::cout << std::endl;

  a.resize(4);
  std::for_each(a.begin(), a.end(), [](int x) {
    std::cout << x << " ";
  });
  std::cout << std::endl;

  a.resize(100);
  std::for_each(a.begin(), a.end(), [](int x) {
    std::cout << x << " ";
  });
  std::cout << std::endl;
  if (b >= a) {
    std::cout << "b>=a" << std::endl;
  } else {
    std::cout << "b<=a" << std::endl;
  }

  a.swap(b);
  std::for_each(a.begin(), a.end(), [](int x) {
    std::cout << x << " ";
  });
  std::cout << std::endl;
  std::for_each(b.begin(), b.end(), [](int x) {
    std::cout << x << " ";
  });
  std::cout << std::endl;

  std::erase(b, 0); // 删除b中的0
  std::for_each(b.begin(), b.end(), [](int x) {
    std::cout << x << " ";
  });
  std::cout << std::endl;
  std::erase_if(b, [](int x) { return x % 2 == 0; }); // 删除b中的偶数
  std::for_each(b.begin(), b.end(), [](int x) {
    std::cout << x << " ";
  });
  std::cout << std::endl;
}