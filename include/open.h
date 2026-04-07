#ifndef ZOPENCALLS_H 
#define ZOPENCALLS_H 

/* this is instead openat */

static inline long zopen(const char *path, int flags, int mode) {
  long ret;
  register long r10 __asm__("r10") = mode;

  __asm__ volatile (
      "syscall"
      : "=a"(ret)
      : "a"(257),
        "D"(-100),
        "S"(path),
        "d"(flags),
        "r"(r10)
      : "rcx", "r11", "memory"
  );
  return ret;
}

#endif

