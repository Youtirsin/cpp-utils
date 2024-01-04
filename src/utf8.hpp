#pragma once

#include <stdexcept>
#include <string>

inline void delete_back_utf8(std::string& str) {
  if (str.empty()) throw std::runtime_error("empty string.");
  // check if its `0xxx xxxx` which is a ascii character
  if ((str.back() & 0x80) == 0) {
    str.pop_back();
    return;
  }
  // delete util `11xx xxxx` which is the first byte of multi bytes utf8
  while ((str.back() & 0xC0) != 0xC0) {
    str.pop_back();
    // utf8 string must starts with `11xx xxxx` byte
    if (str.empty()) throw std::runtime_error("invalid utf8 string.");
  }
  str.pop_back();
}
