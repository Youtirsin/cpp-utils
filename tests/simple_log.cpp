#include "print.hpp"

int main (int, char**) {
  const int x = 1;
  info("hello world ", x);
  error("hello world ", x);
  infoln("hello world ", x);
  errorln("hello world ", x);
  
  return 0;
}
