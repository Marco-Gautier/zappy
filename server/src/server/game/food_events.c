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

    (void)ac;
    (void)av;
    client->inventory.food--;
    s->world.map[x][y].food++;
    fprintf(stderr, "%s\n", __func__);
    return add_food_event(s, client);
}

int add_food_event(struct server *server, struct client *client)
{
    suseconds_t time = compute_trigger_time(DIGEST_TIME, server->options.freq);
    event_t *event;

    if (time == -1)
        return fprintf(stderr, "error during event creation\n"), -1;
    event = create_event(time, 0, NULL, &food_callback);
    if (!event)
        return fprintf(stderr, "error during event creation\n"), -1;
    return add_event(client, event);
}
