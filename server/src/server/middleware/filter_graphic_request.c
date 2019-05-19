/*
** EPITECH PROJECT, 2018
** filter_graphic_request
** File description:
** filter_graphic_request
*/

#include <stdio.h>
#include "zappy.h"

/*
** Restrict request to graphical clients
*/

int filter_graphic_request(struct server *server, int i, int argc, char **argv)
{
    (void)argc;
    if (server->clients[i]->client_type != CT_GRAPHIC) {
        printf("Command [");
        for (int i = 0; i < argc; i++) {
            printf("%s", argv[i]);
            if (i + 1 < argc)
                printf(", ");
        }
        printf("] from client n°%d rejected :\n", i);
        printf(COMMAND_NO_ACCESS, "graphical");
        return -1;
    } else
        return 0;
}
