#pragma once

#include <memory>
#include <utility>

template <typename T>
class singleton {
 public:
  template <typename... Args>
  static T &instance(Args &&...args) noexcept {
    if (!val()) val() = std::unique_ptr<T>(new T(std::forward<Args>(args)...));
    return *val();
  }

 private:
  static std::unique_ptr<T> &val() noexcept {
    static std::unique_ptr<T> t;
    return t;
  };
};
