#ifndef ZCOREPIPE_H
#define ZCOREPIPE_H 

static inline long pipe(int pipefd[2]) {
  long ret;
  __asm__ volatile (
    "syscall"
    : "=a"(ret)
    : "a"(22),
      "D"(pipefd)
    : "rcx", "r11", "memory"
  );
  return ret;
}

#endif
