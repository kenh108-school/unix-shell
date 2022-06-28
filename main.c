#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include "input.h"
#include "command.h"

void sig_handler(int signo) {
    write(1, "\n$ ", 4);
}

int main(int argc, char **argv) {
   struct sigaction SIGINT_action = {0};
   SIGINT_action.sa_handler = sig_handler;
   sigfillset(&SIGINT_action.sa_mask);
   SIGINT_action.sa_flags = SA_RESTART;
   sigaction(SIGINT, &SIGINT_action, NULL);

   char *input;
   // Array of strings for each word of command
   char **command;

   // Loop for prompt
   while (true) {
        print_prompt();
        input = read_input();

        if (input == NULL) continue;

        command = parse_input(input);

        // Exit if exit is typed
        if (strcmp(command[0], "exit") == 0) return EXIT_SUCCESS;

        // Implement cd command
        if (strcmp(command[0], "cd") == 0) {
        int r = chdir(command[1]);

        if (r == -1) {
            printf("Invalid command\n");
        }
        } else {
        execute_command(command);
        }

        free(input);
    }

    return EXIT_SUCCESS;
}

