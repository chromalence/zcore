#include <zcore/print.h>
#include <zcore/exit.h> 

void _start() {
  zprint(1, "hello world\n", 12);
  zexit(0);
}
