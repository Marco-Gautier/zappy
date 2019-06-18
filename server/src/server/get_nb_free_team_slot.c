/*
** EPITECH PROJECT, 2019
** get_nb_free_team_slot
** File description:
** get_nb_free_team_slot
*/

#include <string.h>
#include "zappy.h"

static int get_current_team_size(struct server *server, const char *team_name)
{
    int size = 0;

    for (size_t i = 0; server->clients[i] != NULL; i++) {
        if (!server->clients[i]->team_name)
            continue;
        if (!strcmp(server->clients[i]->team_name, team_name))
            size++;
    }
    return size;
}

static int get_team_hatched_eggs_nb(struct server *server,
const char *team_name)
{
    int size = 0;

    for (size_t i = 0; server->clients[i] != NULL; i++) {
        if (!server->clients[i]->team_name || !server->clients[i]->hatched)
            continue;
        if (!strcmp(server->clients[i]->team_name, team_name))
            size++;
    }
    return size;
}

static bool is_team_name_valid(struct server *server, const char *team_name)
{
    for (int i = 0; server->options.team_names[i] != NULL; i++)
        if (!strcmp(server->options.team_names[i], team_name))
            return true;
    return false;
}

int get_nb_free_team_slot(struct server *server, const char *team_name)
{
    int ret = server->options.max_team_nbr;

    if (!team_name || !is_team_name_valid(server, team_name))
        return -1;
    ret -= get_current_team_size(server, team_name);
    ret += get_team_hatched_eggs_nb(server, team_name) * 2;
    return ret;
}
