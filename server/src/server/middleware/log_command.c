/*
** EPITECH PROJECT, 2019
** log_command
** File description:
** log_command
*/

#include <stdio.h>
#include "server.h"

/*
** Middleware use to log each received command on standard output
*/

int log_command(struct server *server, int i, int argc, char **argv)
{
    (void)server;
    printf("Received command [");
    for (int i = 0; i < argc; i++) {
        printf("%s", argv[i]);
        if (i + 1 < argc)
            printf(", ");
    }
    printf("] from client n°%d\n", i);
    return 0;
}
