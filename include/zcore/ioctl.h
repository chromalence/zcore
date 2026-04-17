#ifndef ZCOREIOCTL_H
#define ZCOREIOCTL_H

static inline long zioctl(int fd, unsigned long op, void *arg) {
  long ret;
  __asm__ volatile (
    "syscall"
    : "=a"(ret)
    : "a"(16),
      "D"(fd),
      "S"(op),
      "d"(arg)
    : "rcx", "r11", "memory"
  );
  return ret;
}

#endif
