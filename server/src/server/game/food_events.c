/*
** EPITECH PROJECT, 2019
** PSU_zappy_2019
** File description:
** description
*/

#include <stdio.h>
#include <stdlib.h>
#include "event.h"
#include "server.h"

int food_callback(struct server *serv, struct client *client, int ac, char **av)
{
    int x = rand() % serv->world.width;
    int y = rand() % serv->world.height;

    (void)ac;
    (void)av;
    client->inventory.food--;
    serv->world.map[x][y].food++;
    fprintf(stderr, "%s\n", __func__);
    return add_food_event(serv, client);
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
