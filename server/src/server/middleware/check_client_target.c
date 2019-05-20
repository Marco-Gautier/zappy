/*
** EPITECH PROJECT, 2019
** check_client_target
** File description:
** check_client_target
*/

#include <stdio.h>
#include <stdlib.h>
#include "zappy.h"

static size_t get_clients_nb(struct client **client)
{
    size_t i = 0;

    if (client)
        while (client[i] != NULL)
            i++;
    return i;
}

/*
** Middleware use to check if the client target is valid
*/

int check_client_target(struct server *server, int clien, int argc, char **argv)
{
    int tmp;

    (void)clien;
    if (argc != 2)
        return -1;
    tmp = atoi(argv[1]);
    if (tmp < 1)
        return -1;
    if (tmp >= (int)get_clients_nb(server->clients))
        return -1;
    if (server->clients[tmp]->client_type != CT_AI)
        return -1;
    if (!server->clients[tmp]->team_name)
        return -1;
    return 0;
}
