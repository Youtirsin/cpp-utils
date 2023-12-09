#include "threadpool.hpp"

#include <iostream>
#include <thread>

int main() {
  std::unique_ptr<Threadpool> pool(new Threadpool);

  auto a = pool->add_task([]() {
    for (int i = 0; i < 10; ++i) {
      std::cout << "hello world" << std::endl;
      std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    return 2;
  });

  auto b = pool->add_task([]() {
    std::this_thread::sleep_for(std::chrono::milliseconds(800));
    return 4;
  });

  std::cout << a.get() << std::endl;
  std::cout << b.get() << std::endl;

  return 0;
}
