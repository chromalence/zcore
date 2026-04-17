#ifndef ZCHDIRCALLS_H
#define ZCHDIRCALLS_H 

static inline long zchdir(const char *path) {
  long ret;
  __asm__ volatile (
      "syscall"
      : "=a"(ret)
      : "a"(80),
      "D"(path)
      : "rcx", "r11", "memory"
    );
  return ret;
}



#endif 
