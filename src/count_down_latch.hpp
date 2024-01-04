#pragma once

#include <condition_variable>
#include <mutex>

class CountDownLatch {
 public:
  explicit CountDownLatch(int count) noexcept : m_cnt(count) {}

  void wait() noexcept {
    std::unique_lock<std::mutex> lock(m_mtx);
    m_cond.wait(lock, [this] { return m_cnt == 0; });
  }

  void count_down() noexcept {
    std::unique_lock<std::mutex> lock(m_mtx);
    if (m_cnt > 0) {
      --m_cnt;
      if (m_cnt == 0) m_cond.notify_all();
    }
  }

 private:
  std::mutex m_mtx;
  std::condition_variable m_cond;
  int m_cnt;
};
