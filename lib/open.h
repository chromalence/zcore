#ifndef ZOPENCALLS_H 
#define ZOPENCALLS_H 

int zopen(const char *path, int flags, int mode);

__asm__(
  ".intel_syntax noprefix\n"
  "zopen: push 2; pop rax; syscall; ret\n"
  ".att_syntax\n"
);

#endif
