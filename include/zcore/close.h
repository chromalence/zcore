#ifndef ZCLOSECALLS_H
#define ZCLOSECALLS_H 

static inline long zclose(int fd) {
  long ret;
  __asm__ volatile (
      "syscall"
      : "=a"(ret)
      : "a"(3),
      "D"(fd)
      : "rcx", "r11", "memory"
    );
  return ret;
}

#endif


