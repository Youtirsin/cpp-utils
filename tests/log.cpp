#include "log.hpp"

int main (int, char**) {
  auto log = log::get();

  const int x = 1;
  log->info("hello world ", x);
  log->error("hello world ", x);
  log->infoln("hello world ", x);
  log->errorln("hello world ", x);

  log->on(false);
  log->info("hello world ", x);
  log->error("hello world ", x);
  log->infoln("hello world ", x);
  log->errorln("hello world ", x);

  log->on(true);
  log->with_log_file("./test.log");
  log->info("hello world ", x);
  log->error("hello world ", x);
  log->infoln("hello world ", x);
  log->errorln("hello world ", x);
  
  return 0;
}
