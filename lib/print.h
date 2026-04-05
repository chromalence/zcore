#ifndef ZPRINTCALLS_H
#define ZPRINTCALLS_H

long zprint(int fd, const void *buf, unsigned long count) __asm__("zprint");

__asm__(
    ".intel_syntax noprefix\n"
    "zprint: push 1; pop rax; syscall; ret\n"
    ".att_syntax"
);

#endif
