#ifndef ZCOREVFORK_H
#define ZCOREVFORK_H

static inline long zvfork(void) {
  long ret;
  __asm__ volatile (
    "syscall"
    : "=a"(ret)
    : "a"(58)
    : "rcx", "r11", "memory"
  );
  return ret;
}

#endif
