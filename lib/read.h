#ifndef ZREADCALLS_H
#define ZREADCALLS_H

long zread(int fd, void *buf, unsigned long count);

__asm__(
    ".intel_syntax noprefix\n"
    "zread: xor eax, eax; syscall; ret\n"
    ".att_syntax"
);

#endif
