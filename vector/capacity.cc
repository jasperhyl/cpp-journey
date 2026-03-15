#include <iostream>
#include <ostream>
#include <vector>
int main() {
  std::vector<int> vec = {1, 2};
  if (vec.empty() && vec.size() == 0) {
    std::cout << "vec是空的" << std::endl;
  } else {
    std::cout << "vec不是空的,size=" << vec.size() << std::endl;
  }
  std::cout << "int类型的vector的max_size为 " << vec.max_size() << std::endl;
  std::vector<double> vecd;
  std::cout << "dpuble类型的vector的max_size为 " << vecd.max_size() << std::endl;
  std::cout << "当前vector申请的存储int的个数为 " << vec.capacity() << std::endl;
  std::vector<int> a;
  std::cout << a.capacity() << std::endl;
  a.reserve(10000);
  std::cout << a.capacity() << std::endl;
  a = {1, 2, 3};
  a.shrink_to_fit();
  std::cout << a.capacity() << std::endl;
  return 0;
}