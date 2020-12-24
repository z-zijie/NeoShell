//
// Created by Zijie Zhang on 12/23/20.
//

#include <stdio.h>
#include <stdlib.h>

#define NEOSH_RL_BUFSIZE 1024

char *read_line(void)
{
    int bufsize = NEOSH_RL_BUFSIZE;
    int position = 0;
    char *buffer = malloc(sizeof(char) * bufsize);
    int c;

    if (!buffer)
    {
        fprintf(stderr, "neosh: allocation error\n");
        exit(EXIT_FAILURE);
    }

    while (1)
    {
        // Read a char
        c = getchar();

        // If hit EOF, replace it with a null character and return.
        if (c == EOF || c == '\n')
        {
            buffer[position] = '\0';
            return buffer;
        }
        else
        {
            buffer[position] = c;
        }
        position++;

        // If exceeded the buffer, reallocate.
        if (position >= bufsize)
        {
            bufsize += NEOSH_RL_BUFSIZE;
            buffer = realloc(buffer, bufsize);
            if (!buffer)
            {
                fprintf(stderr, "neosh: allocation error\n");
                exit(EXIT_FAILURE);
            }
        }
    }
    return buffer;
}
