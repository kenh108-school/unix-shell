#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "input.h"

void print_prompt(void) {
    printf("$ ");
}

char *read_input(void) {
    char *buffer = NULL;
    size_t bufsize = 0;
    size_t chars;

    chars = getline(&buffer, &bufsize, stdin);

    // If there is error with getline
    if (chars == -1)
    {
        if (errno == EINTR) return NULL;
        else {
            fprintf(stdout, "getline() error.\n");
            exit(EXIT_FAILURE);
        }
    }

    // Remove newline char
    buffer[chars - 1] = '\0';
    
    return buffer;
}

char **parse_input(char *input) {
    // Assign space for char pointer
    char **tokens = malloc(sizeof(char *));
    char *token = strtok(input, " ");
    int position = 0;

    while (token != NULL) {
      tokens[position++] = token;
      // Assign space for another char pointer
      tokens = realloc(tokens, (position + 1) * sizeof(char *));
      token = strtok(NULL, " ");
    }

    // End array of strings with null
    tokens[position] = NULL;

    return tokens;
}


