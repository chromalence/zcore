#ifndef ZCHDIRCALLS_H
#define ZCHDIRCALLS_H 

long zchdir(const char *path);

__asm__(
  ".intel_syntax noprefix\n"
  "zchdir: push 80; pop rax; syscall; ret\n" 
  ".att_syntax"
);

#endif 
