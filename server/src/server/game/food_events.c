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
    int x;
    int y;

    (void)ac;
    (void)av;
    for (int i = 0; i < rand() % 42; i++) {
        x = rand() % serv->world.width;
        y = rand() % serv->world.width;
        serv->world.map[x][y].food++;
    }
    client->inventory.food--;
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
