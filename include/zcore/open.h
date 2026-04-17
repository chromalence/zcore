#ifndef ZOPENCALLS_H 
#define ZOPENCALLS_H 

static inline long zopen(const char *path, int flags, int mode) {
  long ret;

  __asm__ volatile (
      "syscall"
      : "=a"(ret)
      : "a"(2),
        "D"(path),
        "S"(flags),
        "d"(mode)
      : "rcx", "r11", "memory"
  );
  return ret;
}

#endif
