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

int filter_ai_request(struct server *server, struct client *client,
                      int argc, char **argv)
{
    (void)argc;
    (void)server;
    if (client->client_type == CT_AI)
        return 0;
    printf("Command [");
    for (int i = 0; i < argc; i++) {
        printf("%s", argv[i]);
        if (i + 1 < argc)
            printf(", ");
    }
    printf("] from client n°%d rejected :\n", client->id);
    printf(COMMAND_NO_ACCESS, "AI");
    return -1;
}
