#ifndef ZFORKCALLS_H
#define ZFORKCALLS_H

static inline long zfork(void) {
  long ret;
  __asm__ volatile (
      "syscall"
      : "=a"(ret)
      : "a"(57)
      : "rcx", "r11", "memory"
    );
  return ret;
}

#endif
