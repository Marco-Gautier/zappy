/*
** EPITECH PROJECT, 2019
** PSU_zappy_2018
** File description:
** description
*/

#include <stdio.h>
#include <stdlib.h>
#include "event.h"
#include "server.h"

int food_callback(struct server *s, struct client *client, int ac, char **av)
{
    int x = rand() % s->world.width;
    int y = rand() % s->world.height;
    client->inventory.food --;
    s->world.map[x][y].food ++;
    fprintf(stderr, "food_callback\n");
    return add_food_event(s, client);
}

int add_food_event(struct server *server, struct client *client)
{
    suseconds_t time = compute_trigger_time(DIGEST_TIME, server->options.freq);
    event_t *event = create_event(time, 0, NULL, food_callback);

    if (!event || time == -1) {
        fprintf(stderr, "error during event creation\n");
        return -1;
    }
    return add_event(client, event);
}