/*
** EPITECH PROJECT, 2019
** filter_ai_request
** File description:
** filter_ai_request
*/

#include <stdio.h>
#include "zappy.h"

/**
** Middleware use to restrict request to AI clients
*/

int filter_ai_request(struct server *server, int i, int argc, char **argv)
{
    (void)argc;
    if (server->clients[i]->client_type != CT_AI) {
        printf("Command [");
        for (int i = 0; i < argc; i++) {
            printf("%s", argv[i]);
            if (i + 1 < argc)
                printf(", ");
        }
        printf("] from client n°%d rejected :\n", i);
        printf(COMMAND_NO_ACCESS, "AI");
        return -1;
    } else
        return 0;
}
