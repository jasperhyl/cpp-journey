// 重新回忆vector的用法，并实现自己的vector
#include <iostream>
#include <string>
#include <vector>
int main() {

  // 一：vector的使用
  // 1.1 构造函数
  // 无参构造
  std::vector<int> vec1;
  // vector( size_type count, const T& value,const Allocator& alloc =
  // Allocator()
  // );
  std::vector<std::string> word(3, "hello");
  // 使用迭代器构造
  std::vector<char> a = {'a', 'b', 'c'};
  std::vector<char> b(a.begin(), a.end());
  // vector( std::initializer_list<T> init,const Allocator& alloc = Allocator()
  // ); 针对有std::initializer_list<T>构造方式的，可以采用以下方式：
  std::vector<int> c{1, 2, 3};   // 直接列表初始化
  std::vector<int> d({4, 5, 6}); // 直接初始化
  std::vector<int> e = {
      7, 8,
      9}; // 拷贝列表初始化，名字有拷贝，但是不是先造临时对象，再拷贝构造，只是从语法上起这个名字而已

  // 1.2析构函数(不建议手动析构)
  //~vector();

  // 1.3 operator=
  // vector重载了=，用于实现让一个已经存在的vector，能够用不同来源的内容去“替换自己”。
  // vector& operator=(const vector&other); 拷贝赋值,把 other 的内容复制一份，覆盖到当前 vector 里。
  c = d;

  // vector& operator=(vector&& other); 移动赋值,尽量直接接管 other 的资源，而不是逐个复制元素
  d = std::move(e);
  // std::move(e) 后 e 会怎样
  // e 仍然是有效对象，但内容进入“可用但未指定状态”。
  // 你可以理解成：
  // e 还能析构
  // e 还能重新赋值
  // e.empty() 在很多实现里可能是 true，但标准不要求必须是某个具体内容
  // 所以不要依赖移动后的具体值，只要知道它还能安全销毁和重新使用。

  // vector& operator=(std::initializer_list<value_type>);   // 列表赋值
  a = {'d', 'e'};

  // 它们的返回值都是vector&，是为了支持链式写法，即a=b=c的形式，先执行b=c之后，b返回自己的引用，再赋值a

  // 1.4 operator=

  //  vector的容量增长不是按照固定数值，而是按照固定倍数，比如按当前容量的两倍增加
}