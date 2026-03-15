#include <iostream>
#include <vector>
int main() {
  std::vector<char> vec1(5, 'a');
  std::vector<char> vec2({'b', 'c'});
  std::vector<char> vec3 = {'e', 'f', 'g', 'h'};
  vec1.assign(vec2.begin(), vec2.end());
  auto print_vector = [&]() {
    for (char i : vec1) {
      std::cout << i;
    }
    std::cout << std::endl;
  };

  print_vector();
  vec1.assign(3, 'z');
  print_vector();
  vec1.assign({'h', '1', '`', ';'});
  print_vector();
}