/*
** EPITECH PROJECT, 2019
** command_connect_nbr
** File description:
** command_connect_nbr
*/

#include <stdio.h>
#include "zappy.h"

int command_connect_nbr(struct server *server, int i, int argc, char **argv)
{
    int n = get_nb_free_team_slot(server, server->clients[i]->team_name);

    (void)argc;
    (void)argv;
    return dprintf(server->clients[i]->fd, "%d\n", n);
}
