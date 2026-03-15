#include <algorithm>
#include <cassert>
#include <iostream>
#include <list>
#include <vector>
int main() {
  const auto source = std::list<int>{1, 2, 3};
  auto destination = std::vector<int>{4, 5, 6};
#ifdef __cpp_lib_containers_ranges
  destination.assign_range(source);
  assert(std::ranges::equal(source, destination));
  std::cout << "两者相等" << std::endl;
#else
  std::cout << "请使用-std=c++23及以上编译该程序" << std::endl;
#endif

  return 0;
}