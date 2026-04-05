#ifndef ZCLOSECALLS_H
#define ZCLOSECALLS_H 

int zclose(int fd);

__asm__(
  ".intel_syntax noprefix\n"
  "zclose: push 3; pop rax; syscall; ret\n"
  ".att_syntax"
);

#endif 
