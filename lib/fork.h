#ifndef ZFORKCALLS_H
#define ZFORKCALLS_H

long zfork(void);

__asm__(
    ".intel_syntax noprefix\n"
    "zfork: push 57; pop rax; syscall; ret\n"
    ".att_syntax"
);

#endif
