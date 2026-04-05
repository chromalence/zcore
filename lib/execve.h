#ifndef ZEXECVECALLS_H
#define ZEXECVECALLS_H 

long zexecve(const char *path, char *const argv[], char *const envp[]);

__asm__(
  ".intel_syntax noprefix\n"
  "zexecve: push 59; pop rax; syscall; ret\n"
  ".att_syntax"
);

#endif 
