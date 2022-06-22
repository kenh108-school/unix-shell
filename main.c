#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

void print_prompt(void);
char *read_input(void);
char **parse_input(char *);

int main(int argc, char **argv) {
    char *input;
    char **parsed_input;
    char *test = "hello";

    while (true) {
        print_prompt();
        input = read_input();
        parsed_input = parse_input(input);
        
        free(input);
    }
}

void print_prompt(void) {
    printf("$ ");
}

char *read_input(void) {
    char *buffer = NULL;
    size_t bufsize = 0;
    size_t chars;

    chars = getline(&buffer, &bufsize, stdin);

    if (chars == -1) {
        fprintf(stdin, "getline() error.\n");
        return NULL;
    }

    buffer[chars - 1] = '\0';
    return buffer;
}

char **parse_input(char *input) {
    char **tokens = malloc(sizeof(char *));
    char *token = strtok(input, " ");
    int position = 0;

    while (token != NULL) {
        tokens[position++] = token;
        tokens = realloc(tokens, (position + 1) * sizeof(char *));
        token = strtok(NULL, " ");
    }

    return tokens;
}