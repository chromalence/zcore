#ifndef ZWAITCALLS_H
#define ZWAITCALLS_H 

static inline long zwait(void) {
  long ret;
  register long r10 __asm__("r10") = 0;
  __asm__ volatile (
      "syscall"
      : "=a"(ret)
      : "a"(61),     
        "D"(-1),    
        "S"(0),      
        "d"(0),      
        "r"(r10)    
      : "rcx", "r11", "memory"
  );
  return ret;
}

#endif 
