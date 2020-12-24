//
// Created by Zijie Zhang on 12/23/20.
//

#include <stdio.h>
#include <stddef.h>
#include <unistd.h>

int neosh_cd(char **args)
{
    if (args[1] == NULL) {
        fprintf(stderr, "neosh: expected argument to \"cd\"\n");
    } else {
        if (chdir(args[1]) != 0) perror("neosh");
    }
    return 1;
}