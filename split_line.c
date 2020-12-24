//
// Created by Zijie Zhang on 12/23/20.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NEOSH_TOK_BUFSIZE 64
#define NEOSH_TOK_DELIM " \t\r\n\a"

char **split_line(char *line)
{
    int bufsize = NEOSH_TOK_BUFSIZE, position = 0;
    char **tokens = malloc(bufsize * sizeof(char *));
    char *token;

    if (!tokens)
    {
        fprintf(stderr, "neosh: allocation error\n");
        exit(EXIT_FAILURE);
    }

    token = strtok(line, NEOSH_TOK_DELIM);
    while (token != NULL){
        tokens[position++] = token;
        if (position >= bufsize){
            bufsize += NEOSH_TOK_BUFSIZE;
            tokens = realloc(tokens, bufsize * sizeof(char*));
            if (!tokens){
                fprintf(stderr, "neosh: allocation error\n");
                exit(EXIT_FAILURE);
            }
        }
        token = strtok(NULL, NEOSH_TOK_DELIM);
    }
    tokens[position] = NULL;
    return tokens;
}