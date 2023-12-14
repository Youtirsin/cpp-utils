#include "noncopable.hpp"

class Obj : noncopyable {};

int main(int argc, char *argv[]) {
  Obj obj1;
  // error
  // Obj obj2 = obj1;

  return 0;
}
