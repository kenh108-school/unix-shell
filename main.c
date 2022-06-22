#include <stdio.h>

void print_prompt(void);
char * read_input(void);
char ** parse_input(char *);

int main(int argc, char **argv) {
    char *input;
    char **parsed_input;

    print_prompt();
    input = read_input();
    parsed_input = parse_input(input);
}

void print_prompt(void) {
    printf("$ ");
}

char *read_input(void) {

}

char ** parse_input(char *input) {

}