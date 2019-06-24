/*
** EPITECH PROJECT, 2019
** is_game_over
** File description:
** is_game_over
*/

#include <string.h>
#include <stdio.h>
#include "zappy.h"

static int get_team_elevation(struct server *server, const char *team)
{
    int elevation = 0;

    for (size_t i = 0; server->clients[i] != NULL; i++) {
        if (!server->clients[i]->team_name)
            continue;
        if (server->clients[i]->type != CT_AI)
            continue;
        if (strcmp(team, server->clients[i]->team_name) != 0)
            continue;
        if (server->clients[i]->level < 6)
            continue;
        elevation++;
    }
    return elevation;
}

/**
** If a team has 6 members who has a level higher than 6, they win
*/

bool is_game_over(struct server *server)
{
    const char *format = "seg %s\n";

    if (!server->clients)
        return false;
    for (int i = 0; server->options.team_names[i] != NULL; i++) {
        if (get_team_elevation(server, server->options.team_names[i]) < 6)
            continue;
        send_graphical_broadcast(server, format, server->options.team_names[i]);
        printf("%s has won.\n", server->options.team_names[i]);
        return true;
    }
    return false;
}
