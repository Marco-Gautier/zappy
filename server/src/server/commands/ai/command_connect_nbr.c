/*
** EPITECH PROJECT, 2019
** command_connect_nbr
** File description:
** command_connect_nbr
*/

#include <stdio.h>
#include "zappy.h"

int command_connect_nbr(struct server *server, struct client *client,
                        int argc, char **argv)
{
    int n = get_nb_free_team_slot(server, client->team_name);

    (void)argc;
    (void)argv;
    return send_client_msg(client, "%d\n", n);
}
