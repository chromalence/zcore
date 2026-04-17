#ifndef ZSTRCMPCALLS_H
#define ZSTRCMPCALLS_H 

static inline long zstrcmp(const char *s1, const char *s2) {
  while (*s1 && (*s1 == *s2)) {
    s1++;
    s2++;
  }
  return *(unsigned char *)s1 - *(unsigned char *)s2;
}

#endif
