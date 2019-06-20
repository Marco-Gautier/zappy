/*
** EPITECH PROJECT, 2019
** client_join_team
** File description:
** client_join_team
*/

#include <stdio.h>
#include <string.h>
#include "event.h"
#include "zappy.h"
#include "my.h"

/**
** Send broadcast message to all graphics clients that a new client is connected
*/

static void broadcast_new_player(struct server *server, struct client *client)
{
    const char *format = "pnw #%d %d %d %d %d %s\n";
    int id = client->id;
    int x = client->x;
    int y = client->y;
    enum direction dir = client->direction;
    int level = client->level;
    const char *team_name = client->team_name;

    send_graphical_broadcast(server, format, id, x, y, dir, level, team_name);
}

/**
** To validate client connection, the server send to the client :
**
**  --> CLIENT_NUM\n
**  --> X Y\n
*/

static void join_team(struct server *server, struct client *client,
int slot, char *team_name)
{
    int width = server->options.width;
    int height = server->options.height;

    dprintf(client->fd, "%d\n%d %d\n", slot - 1, width, height);
    client->team_name = team_name;
    add_food_event(server, client);
    broadcast_new_player(server, client);
    printf("Client n°%d join team '%s'\n", client->id, team_name);
}

int client_join_team(struct server *server, struct client *client, char **cmd)
{
    int slot;

    if (my_tablen(cmd) != 1)
        return -1;
    if (!strcmp(cmd[0], "GRAPHIC")) {
        client->team_name = "GRAPHIC";
        client->client_type = CT_GRAPHIC;
        return 0;
    }
    slot = get_nb_free_team_slot(server, cmd[0]);
    if (slot < 1)
        return -1;
    join_team(server, client, slot, strdup(cmd[0]));
    return 0;
}
