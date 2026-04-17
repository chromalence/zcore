#ifndef ZCOREDUP3_H
#define ZCOREDUP3_H

static inline long zdup3(int oldfd, int newfd, int flags) {
  long ret;
  __asm__ volatile (
    "syscall"
    : "=a"(ret)
    : "a"(292),
      "D"(oldfd),
      "S"(newfd),
      "d"(flags)
    : "rcx", "r11", "memory"
  );
  return ret;
}

#endif
