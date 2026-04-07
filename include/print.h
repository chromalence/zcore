#ifndef ZPRINTCALLS_H
#define ZPRINTCALLS_H

static inline long zprint(int fd, const void *buf, unsigned long count) {
  long ret;
  __asm__ volatile (
      "syscall"
      : "=a"(ret)
      : "a"(1),
      "D"(fd),
      "S"(buf),
      "d"(count)
      : "rcx", "r11", "memory"
    );
  return ret;
}

#endif
