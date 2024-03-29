/*
** EPITECH PROJECT, 2019
** kick_dead_client
** File description:
** kick_dead_client
*/

#include "zappy.h"

/**
** Kick all AI client who are too hungry from the server
*/

void kick_dead_client(struct server *server)
{
    for (size_t i = 0; server->clients[i] != NULL; i++) {
        if (server->clients[i]->type == CT_GRAPHIC)
            continue;
        if (server->clients[i]->inventory.food < 0) {
            kick_client_from_server(server, i);
            i = 0;
        }
    }
}
