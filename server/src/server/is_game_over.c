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
        if (server->clients[i]->client_type != CT_AI)
            continue;
        if (strcmp(team, server->clients[i]->team_name) != 0)
            continue;
        if (server->clients[i]->level < 6)
            continue;
        elevation++;
    }
    return elevation;
}

/*
** If a team has a member who has a level higher than 6, they win
*/

bool is_game_over(struct server *server)
{
    char buff[512];

    if (!server->clients)
        return false;
    for (int i = 0; server->options.team_names[i] != NULL; i++) {
        if (get_team_elevation(server, server->options.team_names[i]) < 6)
            continue;
        snprintf(buff, sizeof(buff), "seg %s\n", server->options.team_names[i]);
        send_graphical_broadcast(server, buff);
        printf("%s has won.\n", server->options.team_names[i]);
        return true;
    }
    return false;
}
