#ifndef ZEXITCALLS_H
#define ZEXITCALLS_H 

void zexit(int status) __asm__("zexit");

__asm__(
  ".intel_syntax noprefix\n"
  "zexit: push 60; pop rax; syscall\n"
  ".att_syntax"
);

#endif
