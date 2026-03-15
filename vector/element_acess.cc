#include <iostream>
#include <vector>

// 尝试hardened implementation越界检查
void func() {
  // g++ -std=c++23 -O2 -D_GLIBCXX_ASSERTIONS element_acess.cc -o element_acesscc 编译
  // 和使用g++ -std=c++23 -O2  element_acess.cc -o element_acesscc编译,可以看到不同的现象
  // g++ 不写优化程度，默认是-O0,-O0默认启用 _GLIBCXX_ASSERTIONS，这样可以默认检查更多标准库前置条件错误
  std::vector<int> sr = {1, 2, 3, 4, 5, 6, 7};
  std::cout << "测试" << std::endl;
  std::cout << sr[100] << std::endl;
}

int main() {
  std::vector<int> vec = {1, 2, 3, 4, 5, 6};
  int pos1 = vec.at(1);
  std::cout << "pos1=" << pos1 << std::endl;
  std::cout << "pos0=" << vec.front() << std::endl;
  func();
}