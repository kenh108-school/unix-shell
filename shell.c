#include <stdio.h>

#define BUFSIZE 1024

void command_loop(void);
char * read_line(void);
char ** split_line(char *);
int execute_command(char **);

int main(int argc, char **argv) {

    // Loop for commands
    command_loop();

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

char * read_line(void) {

    int bufsize = BUFSIZE;
    int position = 0;
    char *buffer = malloc(sizeof(char) * bufsize);
    int c;

    // Exit if memory allocation fails
    if (!buffer) {
        fprintf(stderr, "Allocation error.\n");
        exit(EXIT_FAILURE);
    }

    while (true) {
        c = getchar();

        // Return on end of input
        if (c == EOF || c == '\n') {
            buffer[position] = '/0';
            return buffer;
        } else {
            buffer[position] = c;
        }
        position++;

        // Allocate more memory if necessary for input
        if (position == bufsize) {
            bufsize += BUFSIZE;
            buffer = realloc(buffer, bufsize);

            if (!buffer) {
                fprintf(stderr, "Allocation error.\n");
                exit(EXIT_FAILURE);
            }
        }
    }
}