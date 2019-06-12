/*
** EPITECH PROJECT, 2019
** PSU_zappy_2018
** File description:
** command_look
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "zappy.h"

static int get_x_offset(struct client *client, int i, int j, int width)
{
    int tmp = 0;

    if (client->direction == D_NORTH)
        tmp = (client->x - (i + 1) + j) % width;
    if (client->direction == D_SOUTH)
        tmp = (client->x + (i + 1) - j) % width;
    if (client->direction == D_WEST)
        tmp = (client->x - (i + 1)) % width;
    if (client->direction == D_EAST)
        tmp = (client->x + (i + 1)) % width;
    return tmp >= 0 ? tmp : tmp + width;
}

static int get_y_offset(struct client *client, int i, int j, int height)
{
    int tmp = 0;

    if (client->direction == D_NORTH)
        tmp = (client->y - (i + 1)) % height;
    if (client->direction == D_SOUTH)
        tmp = (client->y + (i + 1)) % height;
    if (client->direction == D_WEST)
        tmp = (client->y + (i + 1) + j) % height;
    if (client->direction == D_EAST)
        tmp = (client->y - (i + 1) - j) % height;
    return tmp >= 0 ? tmp : height + tmp;
}

int look_callback(struct server *s, struct client *client, int ac, char **av)
{
    char buffer[BUFSIZ];
    char *tmp;

    (void)ac;
    (void)av;
    snprintf(buffer, sizeof(buffer),  "[");
    tmp = list_case_content(s->world, client->x, client->y);
    if (tmp)
        strcat(buffer, tmp);
    for (int i = 0; i < client->level; i++) {
        for (int j = 0; j < (i + 1) * 2 + 1; j++) {
            strcat(buffer, ",");
            tmp = list_case_content(s->world, get_x_offset(client, i, j,\
s->world.width), get_y_offset(client, i, j, s->world.height));
            if (tmp)
                strcat(buffer, tmp);
        }
    }
    strcat(buffer, "]");
    return dprintf(client->fd, "%s\n", buffer);
}

int command_look(struct server *server, int i, int argc, char **argv)
{
    suseconds_t trigger_time = compute_trigger_time(7, server->options.freq);
    event_t *event;

    if (trigger_time == -1)
        return fprintf(stderr, "error during event time computing\n"), -1;
    event = create_event(trigger_time, argc, argv, &look_callback);
    if (!event)
        return fprintf(stderr, "error during event creation\n"), -1;
    if (dprintf(server->clients[i]->fd, "ok\n") < 0)
        return -1;
    return add_event(server->clients[i], event);
}
