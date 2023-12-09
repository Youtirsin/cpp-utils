#include <iostream>

template <class T, class... Rest>
static void error_(T&& val, Rest... rest) noexcept {
  std::cerr << std::forward<T>(val);
  if constexpr (sizeof...(Rest)) error_(rest...);
}

template <class T, class... Rest>
static void info_(T&& val, Rest... rest) noexcept {
  std::cout << std::forward<T>(val);
  if constexpr (sizeof...(Rest)) info_(rest...);
}

template <class T, class... Rest>
void error(T&& val, Rest... rest) noexcept {
  std::cerr << "[ERROR] ";
  error_(std::forward<T>(val), rest...);
}

template <class T, class... Rest>
void info(T&& val, Rest... rest) noexcept {
  std::cout << "[INFO] ";
  info_(std::forward<T>(val), rest...);
}

template <class T, class... Rest>
void errorln(T&& val, Rest... rest) noexcept {
  error(std::forward<T>(val), rest...);
  std::cerr << std::endl;
}

template <class T, class... Rest>
void infoln(T&& val, Rest... rest) noexcept {
  info(std::forward<T>(val), rest...);
  std::cout << std::endl;
}

