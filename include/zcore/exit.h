#ifndef ZEXITCALLS_H
#define ZEXITCALLS_H 

__attribute__((noreturn))
static inline void zexit(int status) {
  __asm__ volatile (
      "syscall"
      : /* nothing */
      : "a"(60),
      "D"(status)
      : "rcx", "r11", "memory"
    );
  __builtin_unreachable();
}

#endif
