/* zcore shell demo 0 */

#include <zcore/chdir.h> /* changing directory */
#include <zcore/execve.h> /* executing */
#include <zcore/fork.h> /* forking so that it doesnt replace our shell */
#include <zcore/read.h> /* getting the actual input */
#include <zcore/strsep.h> /* separating the buffer for arguments */
#include <zcore/strcmp.h> /* comparing the buffer for builtins */
#include <zcore/exit.h> /* exiting */
#include <zcore/print.h> /* printing to file descriptor 1, stdout */
#include <zcore/wait.h> /* waiting for the program */

/* main function */
void _start(void) {
  char input[1024]; /* buffer for characters */
  char *envp[] = { 0 }; /* no env passed in, yet */
  for (;;) { /* loop */
  zprint(1, "> ", 2); /* prompt */ 
  char *token;
  char *p;
  int n = zread(0, input, 1023); /* getting the input */
  if (n <= 0) continue; /* if its empty, continue the loop and do nothing */

  if (n > 0) { 
  input[n-1] = '\0'; /* strip trailing newline */
  } 
  else {
    zexit(0); /* if not, exit gracefully */
  }
  
  char *argv[64]; /* our argument buffer */

  int i = 0;
  p = input;
  while (i < 63 && (token = zstrsep(&p, " ")) != 0) {
    if (*token != '\0') {
      argv[i++] = token;
    }
  } /* splitting all of our arguments and separating them with null terminators */
  argv[i] = 0;
    
  if (i == 0) { continue; } /* extra safety */

  if (zstrcmp(argv[0], "exit") == 0 ) { break; } /* if it says exit, we break out the loop */
  else if (zstrcmp(argv[0], "cd") == 0) {
      if (argv[1] != 0) zchdir(argv[1]);
      continue; 
  } /* cd is a builtin, not a program, we need to check if it says cd, if so we use the syscall */

  if (zfork() == 0) {
    zexecve(argv[0], argv, envp);
    zprint(1, "?\n", 2); /* this is impossible to reach unless zexecve failed because zexecve replaces the process if successful, we need to let them know something went wrong */
    zexit(1); /* exit with a failure */
  } else {
    zwait(); /* else just wait */
  }
  }
  zexit(0);
}

