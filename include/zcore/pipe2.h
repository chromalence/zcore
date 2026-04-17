#ifndef ZCOREPIPE2_H
#define ZCOREPIPE2_H

static inline long zpipe2(int pipefd[2]) {
  long ret;
  __asm__ volatile (
    "syscall"
    : "=a"(ret)
    : "a"(293),
      "D"(pipefd)
    : "rcx", "r11", "memory"
  );
  return ret;
}

#endif
