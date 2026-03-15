#include <iostream>
#include <memory>
#include <vector>

int main() {
  std::vector<int> v = {1, 2, 3};
  auto alloc = v.get_allocator();
  int *p = alloc.allocate(3);
  for (int i = 0; i < 3; i++) {
    p[i] = i;
    std::cout << p[i] << " ";
  }
  std::cout << std::endl;
  alloc.deallocate(p, 3);
}