#ifndef ZCOREFNCTL_H
#define ZCOREFNCTL_H

static inline long fcntl(int fd, int op, long arg) {
  long ret; 
  __asm__ volatile (
    "syscall"
    : "=a"(ret)
    : "a"(72),
      "D"(fd),
      "S"(op),
      "d"(arg)
    : "rcx", "r11", "memory"
  );
  return ret;
}

#endif
