#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "input.h"
#include "command.h"

int main(int argc, char **argv) {
    char *input;
    // Array of strings for each word of command
    char **command;

    // Loop for prompt
    while (true) {
        print_prompt();
        input = read_input();
        command = parse_input(input);

        execute_command(command);

        
        free(input);
    }

    return EXIT_SUCCESS;
}

