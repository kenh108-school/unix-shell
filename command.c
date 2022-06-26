#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include "command.h"

void execute_command(char **command) {
  // Fork for subprocess
  if (fork() == 0) {
    int r = execvp(command[0], command);

    // Check for errors
    if (r == -1) printf("Invalid command\n");
  } else {
    // Parent waits for child to finish
    wait(NULL);
  }
}