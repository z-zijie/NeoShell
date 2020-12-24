//
// Created by Zijie Zhang on 12/23/20.
//

#include <stdio.h>
#include <stdlib.h>

char *read_line(void);
char **split_line(char *line);
int execute(char **args);

void shell_loop(void)
{
    char *line;
    char **args;
    int status;

    do{
        printf("> ");
        line = read_line();
        args = split_line(line);
        status = execute(args);

        free(line);
        free(args);
    } while (status);
}