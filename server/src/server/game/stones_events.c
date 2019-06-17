/*
** EPITECH PROJECT, 2019
** stones_events
** File description:
** stones_events
*/

#include <stdio.h>
#include <stdlib.h>
#include "zappy.h"
#include "my.h"

int stones_callback(struct server *server, struct client *c, int ac, char **av)
{
    int pos_x = rand() % server->options.width;
    int pos_y = rand() % server->options.height;
    int stone = rand() % C_CAOUILLOUX_SIZE;
    int caouillioux_nb = abs(rand() % 42 - rand() % 42);

    (void)ac;
    (void)av;
    (void)c;
    server->world.map[pos_x][pos_y].stones[stone] += caouillioux_nb;
    return add_stones_event(server);
}

int add_stones_event(struct server *server)
{
    int freq = DIGEST_TIME / 5;
    suseconds_t time = compute_trigger_time(freq, server->options.freq);
    event_t *event;

    if (time == -1)
        return -1;
    event = create_event(time, 0, NULL, &stones_callback);
    if (!event)
        return -1;
    server->events = my_push_back(server->events, event);
    return 0;
}
