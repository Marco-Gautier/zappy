/*
** EPITECH PROJECT, 2019
** PSU_zappy_2018
** File description:
** command_fork
*/

#include <stdio.h>
#include <stdlib.h>
#include "zappy.h"

static struct client *create_client(int id, int egg_id, struct client *client)
{
    struct client *tmp = malloc(sizeof(struct client));

    if (!tmp)
        return NULL;
    *tmp = (struct client) {
        .fd = -1,
        .id = id,
        .x = client->x,
        .y = client->y,
        .level = 1,
        .egg_id = egg_id,
        .hatched = true,
        .direction = rand() % (D_DIRECTION_SIZE) + 1
    };
    tmp->inventory.food = 10;
    return tmp;
}

struct client *create_new_player(struct server *s, struct client *c, int egg_id)
{
    size_t i = 0;
    void *tmp;

    if (s->clients)
        while (s->clients[i] != NULL)
            i++;
    tmp = realloc(s->clients, sizeof(struct client *) * (i + 2));
    if (!tmp)
        return NULL;
    s->clients = tmp;
    s->clients[i] = create_client(i, egg_id, c);
    s->clients[i + 1] = NULL;
    return s->clients[i];
}

int new_player_callback(struct server *s, struct client *c, int ac, char **av)
{
    struct client *tmp;

    tmp = create_new_player(s, c, (ac == 3 && av && av[1]) ? atoi(av[1]) : 0);
    printf("new client created with id %d\n", tmp->egg_id);
    return 0;
}

// TODO add broadcast to all player enw e n X Y\n
int fork_callback(struct server *s, struct client *client, int ac, char **av)
{
    suseconds_t trigger_time = compute_trigger_time(600, s->options.freq);
    event_t *event;
    char **tmp = malloc(sizeof(char *) * 2);

    if (!tmp)
        return -1;
    tmp[0] = av[0];
    tmp[1] = av[1];
    if (trigger_time == -1)
        return fprintf(stderr, "error during event time computing\n"), -1;
    event = create_event(trigger_time, ac, tmp, &new_player_callback);
    if (!event)
        return fprintf(stderr, "error during event creation\n"), -1;
    send_graphical_broadcast(s, "enw %d %d %d %d\n",
client->egg_id, client->id, client->x, client->y);
    return add_event(client, event);
}

int command_fork(struct server *server, struct client *client,
                 int argc, char **argv)
{
    suseconds_t trigger_time = compute_trigger_time(42, server->options.freq);
    event_t *event;
    char **av = malloc(sizeof(char *) * 3);
    char tmp[128];

    (void)argc;
    (void)argv;
    if (trigger_time == -1)
        return fprintf(stderr, "error during event time computing\n"), -1;
    if (!av)
        return -1;
    snprintf(tmp, sizeof(tmp), "%d", client->egg_nb);
    av[0] = "Fork";
    av[1] = tmp;
    event = create_event(trigger_time, 2, av, &fork_callback);
    if (!event)
        return fprintf(stderr, "error during event creation\n"), -1;
    client->egg_nb += 1;
    return add_event(client, event);
}
