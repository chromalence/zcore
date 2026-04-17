#ifndef ZCOREDUP_H
#define ZCOREDUP_H

static inline long zdup(int oldfd) {
  long ret;
  __asm__ volatile (
    "syscall"
    : "=a"(ret)
    : "a"(32),
      "D"(oldfd)
    : "rcx", "r11", "memory"
  );
  return ret;
}

#endif
