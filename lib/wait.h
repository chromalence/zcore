#ifndef ZWAITCALLS_H
#define ZWAITCALLS_H 

long zwait(void);

__asm__(
  ".intel_syntax noprefix\n"
  "zwait:\n"
  "    push -1\n"
  "    pop rdi\n"
  "    xor rsi, rsi\n"  
  "    xor rdx, rdx\n" 
  "    xor r10, r10\n" 
  "    push 61\n"
  "    pop rax\n"
  "    syscall\n"
  "    ret\n"
  ".att_syntax"
);

#endif 
