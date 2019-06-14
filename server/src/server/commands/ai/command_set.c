/*
** EPITECH PROJECT, 2019
** command_take
** File description:
** command_take
*/

#include <stdio.h>
#include <string.h>
#include "zappy.h"

/*
** Return index of cayou, FOOD means food, JE_SUIS_PAS_FIER means error
*/

static int get_cayou_id(char **argv)
{
    int i;

    for (i = 0; i < C_CAOUILLOUX_SIZE; i++)
        if (!strcmp(cayou_names[i], argv[1]))
            return i;
    if (!strcmp("food", argv[1]))
        return FOOD;
    return JE_SUIS_PAS_FIER;
}

static int set_builtin(struct server *server, struct client *client, int cayou)
{
    int x = client->x;
    int y = client->y;

    if (cayou == FOOD) {
        if (!client->inventory.food)
            return -1;
        server->world.map[y][x].food += 1;
        client->inventory.food -= 1;
    } else if (cayou != JE_SUIS_PAS_FIER) {
        if (!client->inventory.stones[cayou])
            return -1;
        server->world.map[y][x].stones[cayou] += 1;
        client->inventory.stones[cayou] -= 1;
    } else
        return -1;
    send_graphical_broadcast(server, "pdr %d %d\n", client->id, cayou);
    return 0;
}

static int set_callback(struct server *server, struct client *client,
int cayou_id, char **argv __attribute__((unused)))
{
    if (set_builtin(server, client, cayou_id) != -1)
        return dprintf(client->fd, "ok\n");
    else
        return dprintf(client->fd, "ko\n");
}

int command_set(struct server *server, int client, int argc, char **argv)
{
    suseconds_t time;
    event_t *event;
    int cayou_id;

    if (argc < 2)
        return dprintf(server->clients[client]->fd, "ko\n"), -1;
    cayou_id = get_cayou_id(argv);
    if (cayou_id == JE_SUIS_PAS_FIER)
        return dprintf(server->clients[client]->fd, "ko\n"), -1;
    time = compute_trigger_time(7, server->options.freq);
    if (time == -1)
        return -1;
    event = create_event(time, cayou_id, NULL, &set_callback);
    if (!event)
        return -1;
    return add_event(server->clients[client], event);
}
