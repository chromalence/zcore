#ifndef ZCOREMUNMAP_H
#define ZCOREMUNMAP_H

static inline long zmunmap(void *addr, unsigned long length) {
  long ret;
  __asm__ volatile (
      "syscall"
      : "=a"(ret)
      : "a"(11),
      "D"(addr),
      "S"(length)
      : "rcx", "r11", "memory"
      );
  return ret;
}

#endif 
