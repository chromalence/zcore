#ifndef ZCOREMMAP_H
#define ZCOREMMAP_H

static inline void *zmmap(void *addr,
  unsigned long length,
  int prot,
  int flags,
  int fd,
  unsigned long offset) {

  long ret;
  register long r10 __asm__("r10") = flags;
  register long r8 __asm__("r8") = fd;
  register long r9 __asm__("r9") = offset;
  __asm__ volatile (
      "syscall"
      : "=a"(ret)
      : "a"(9),
      "D"(addr),
      "S"(length),
      "d"(prot),
      "r"(r10),
      "r"(r8),
      "r"(r9)
      : "rcx", "r11", "memory"
    );
  return (void *)ret;
}

#endif
