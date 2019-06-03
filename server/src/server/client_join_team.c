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

/*
** Send broadcast message to all graphics clients that a new client is connected
*/

static void broadcast_new_player(struct server *server, struct client *client)
{
    char buf[128];
    char *format = "pnw #%d %d %d %d %d %s\n";
    int id = client->id;
    int x = client->x;
    int y = client->y;
    int level = client->level;
    const char *team_name = client->team_name;

    snprintf(buf, sizeof(buf), format, id, x, y, 1, level, team_name);
    send_graphical_broadcast(server, buf);
}

/*
** To validate client connection, the server send to the client :
**  --> CLIENT_NUM\n
**  --> X Y\n
*/

static void join_team(struct server *server, int i, int slot, char *team_name)
{
    struct client *client = server->clients[i];
    int width = server->options.width;
    int height = server->options.height;

    dprintf(client->fd, "%d\n%d %d\n", slot - 1, width, height);
    client->team_name = team_name;
    add_food_event(server, client);
    broadcast_new_player(server, client);
    printf("Client n°%d join team '%s'\n", server->clients[i]->id, team_name);
}

int client_join_team(struct server *server, int i, char **command)
{
    int slot;

    if (my_tablen(command) != 1) {
        dprintf(server->clients[i]->fd, "ko\n");
        return -1;
    }
    if (!strcmp(command[0], "GRAPHIC")) {
        server->clients[i]->team_name = "GRAPHIC";
        server->clients[i]->client_type = CT_GRAPHIC;
        return 0;
    }
    slot = get_nb_free_team_slot(server, command[0]);
    if (slot == -1) {
        dprintf(server->clients[i]->fd, "ko\n");
        return -1;
    } else
        join_team(server, i, slot, strdup(command[0]));
    return 0;
}
