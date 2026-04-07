#include "zcore_headers.h"

void _start(void) {
  char input[1024];
  for (;;) { /* loop */
  zprint(1, "> ", 2);
  char *envp[] = { 0 };
  char *token;
  char *p;
  int n = zread(0, input, 1023);
  if (n <= 0) continue;

  if (n > 0) {
  input[n-1] = '\0';
  } 
  else {
    zexit(0);
  }
  
  char *argv[64];

  int i = 0;
  p = input;
  while (i < 63 && (token = zstrsep(&p, " ")) != 0) {
    if (*token != '\0') {
      argv[i++] = token;
    }
  }
  argv[i] = 0;
    
  if (i == 0) { continue; }

  if (zstrcmp(argv[0], "exit") == 0 ) { break; }
  else if (zstrcmp(argv[0], "cd") == 0) {
      if (argv[1] != 0) zchdir(argv[1]);
      continue; 
  }

  if (zfork() == 0) {
    zexecve(argv[0], argv, envp);
    zexit(1);
  } else {
    zwait(); 
  }
  }
  zexit(0);
}
