#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "input.h"

void print_prompt(void);
char *read_input(void);
char **parse_input(char *);

int main(int argc, char **argv) {
    char *input;
    // Array of strings for each word of command
    char **parsed_input;

    // Loop for prompt
    while (true) {
        print_prompt();
        input = read_input();
        parsed_input = parse_input(input);
        
        free(input);
    }

    return EXIT_SUCCESS;
}