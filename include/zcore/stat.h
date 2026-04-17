#ifndef ZCORESTAT_H
#define ZCORESTAT_H

struct zstat {
    unsigned long st_dev;
    unsigned long st_ino;
    unsigned long st_nlink;
    unsigned int  st_mode;
    unsigned int  st_uid;
    unsigned int  st_gid;
    unsigned int  __pad0;
    unsigned long st_rdev;
    long          st_size;
    long          st_blksize;
    long          st_blocks;
    long          st_atime;
    unsigned long st_atime_nsec;
    long          st_mtime;
    unsigned long st_mtime_nsec;
    long          st_ctime;
    unsigned long st_ctime_nsec;
    long          __unused[3];
};

static inline long zstat(const char *path, struct zstat *statbuf) {
  long ret;
  __asm__ volatile (
    "syscall"
    : "=a"(ret)
    : "a"(4), 
      "D"(path),
      "S"(statbuf)
    : "rcx", "r11", "memory"
  );
  return ret;
}

#endif
