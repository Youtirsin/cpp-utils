#include "singleton.hpp"

#include <iostream>
#include <string>

void test() {
  auto& str = singleton<std::string>::instance();
  std::cout << str << std::endl;
}

int main(int argc, char* argv[]) {
  auto& str = singleton<std::string>::instance("hello world");
  std::cout << str << std::endl;
  test();

  return 0;
}
