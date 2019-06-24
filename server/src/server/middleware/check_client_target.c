/*
** EPITECH PROJECT, 2019
** check_client_target
** File description:
** check_client_target
*/

#include <stdio.h>
#include <stdlib.h>
#include "zappy.h"

static int my_getnbr(const char *str)
{
    size_t i;
    int n = 0;

    for (i = 0; str[i] >= '0' && str[i] <= '9'; i++)
        n = n * 10 + (str[i] - '0');
    return str[i] == '\0' ? n : -1;
}

/**
** Middleware use to check if the client target is valid
*/

int check_client_target(struct server *server, struct client *client,
                        int argc, char **argv)
{
    int id;
    struct client *target = NULL;

    (void)client;
    if (argc != 2)
        return -1;
    id = my_getnbr(argv[1]);
    if (id == -1)
        return -1;
    for (size_t i = 0; server->clients[i] != NULL; i++)
        if (server->clients[i]->id == id)
            target = server->clients[i];
    if (!target)
        return -1;
    if (target->client_type != CT_AI)
        return -1;
    return 0;
}
