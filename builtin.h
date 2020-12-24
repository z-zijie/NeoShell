//
// Created by Zijie Zhang on 12/23/20.
//

#ifndef NEOSHELL_BUILTIN_H
#define NEOSHELL_BUILTIN_H

#include <stdio.h>
char *builtin_str[] = {
        "cd",
        "help",
        "exit"};

int num_builtins()
{
    return sizeof(builtin_str) / sizeof(char *);
}

int neosh_help(char **args)
{
    int i;
    printf("Neo SHELL\n");
    printf("The following are built in:\n");

    for (i = 0; i < num_builtins(); i++)
        printf("  %s\n", builtin_str[i]);

    printf("Use the man command for information on other programs.\n");
    return 1;
}

int neosh_cd(char **args);
int neosh_exit(char **args);

int (*builtin_func[])(char **) = {
        &neosh_cd,
        &neosh_help,
        &neosh_exit};

#endif //NEOSHELL_BUILTIN_H
