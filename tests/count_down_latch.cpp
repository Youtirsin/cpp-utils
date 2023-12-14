#include "count_down_latch.hpp"

#include <chrono>
#include <iostream>
#include <thread>

int main(int argc, char* argv[]) {
  CountDownLatch latch(3);

  auto worker = [](CountDownLatch& latch, const std::string& name, int sec) {
    std::this_thread::sleep_for(std::chrono::seconds(sec));
    std::cout << name << std::endl;
    latch.count_down();
  };

  std::thread worker1(worker, std::ref(latch), "worker 1", 1);
  std::thread worker2(worker, std::ref(latch), "worker 2", 2);
  std::thread worker3(worker, std::ref(latch), "worker 3", 3);

  worker1.join();
  worker2.join();
  worker3.join();

  latch.wait();

  std::cout << "all workers done." << std::endl;
  return 0;
}
