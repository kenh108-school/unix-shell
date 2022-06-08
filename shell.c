#include <stdio.h>

void command_loop(void);
char * read_line(void);
char ** split_line(char *);
int execute_command(char **);

int main(int argc, char **argv) {

    // Loop for commands

    return EXIT_SUCCESS;
}

void command_loop(void) {
    
    char *line;
    char **args;
    int status;
    
    do {
        printf("$ ");
        line = read_line();
        args = split_line();
        status = execute_command();

        free(line);
        free(args);
    } while (status);
}