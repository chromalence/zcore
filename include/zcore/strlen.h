#ifndef ZCORESTRLEN_H
#define ZCORESTRLEN_H

static inline long zstrlen(const char *s) {
    long len = 0;
    while (s[len] != '\0') len++;
    return len;
}

#endif
