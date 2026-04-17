#ifndef ZSTRSEPCALLS_H
#define ZSTRSEPCALLS_H 

static inline char *zstrsep(char **stringp, const char *delim) {
    char *start = *stringp;
    
    if (start == 0 || *start == '\0') {
        return 0;
    }

    char *p = start;
    while (*p != '\0' && *p != *delim) {
        p++;
    }

    if (*p == '\0') {
        *stringp = 0;
    } else {
        *p = '\0';          
        *stringp = p + 1;   
    }

    return start;
}

#endif
