#ifndef ZCOREDUP2_H
#define ZCOREDUP2_H

static inline long zdup2(int oldfd, int newfd) {
  long ret;
  __asm__ volatile (
    "syscall"
    : "=a"(ret)
    : "a"(33),
      "D"(oldfd),
      "S"(newfd)
    : "rcx", "r11", "memory"
  );
  return ret;
}

#endif
