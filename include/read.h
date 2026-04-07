#ifndef ZREADCALLS_H
#define ZREADCALLS_H

static inline long zread(int fd, void *buf, unsigned long count) {
  long ret;
  __asm__ volatile (
      "syscall"
      : "=a"(ret)
      : "a"(0),
      "D"(fd),
      "S"(buf),
      "d"(count)
      : "rcx", "r11", "memory"
    );
  return ret;
}


#endif
