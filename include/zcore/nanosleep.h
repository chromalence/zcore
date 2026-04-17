#ifndef ZCORENANOSLEEP_H
#define ZCORENANOSLEEP_H

static inline long znanosleep(const struct timespec *rqtp, struct timespec *rmtp) {
  long ret;
  __asm__ volatile (
    "syscall"
    : "=a"(ret)
    : "a"(35),
      "D"(rqtp),
      "S"(rmtp)
    : "rcx", "r11", "memory"
  );
  return ret;
}

#endif
