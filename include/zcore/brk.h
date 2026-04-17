#ifndef ZCOREBRK_H
#define ZCOREBRK_H

static inline long zbrk(void *addr) {
  long ret;
  __asm__ volatile (
    "syscall"
    : "=a"(ret)
    : "a"(12),
      "D"(addr)
    : "rcx", "r11", "memory"
  );
  return ret;
}

#endif
