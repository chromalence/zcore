#ifndef ZEXECVECALLS_H
#define ZEXECVECALLS_H 

static inline long zexecve(const char *path, char *const argv[], char *const envp[]) {
  long ret;
  __asm__ volatile (
      "syscall"
      : "=a"(ret)
      : "a"(59),
      "D"(path),
      "S"(argv),
      "d"(envp)
      : "rcx", "r11", "memory"
    );
  return ret;
}

#endif
