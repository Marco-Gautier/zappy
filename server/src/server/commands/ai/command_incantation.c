/*
** EPITECH PROJECT, 2019
** command_incantation
** File description:
** command_incantation
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "zappy.h"

const char *format = "Current level: %d\n";

const int client_req[] = {1, 2, 2, 4, 4, 6, 6, 6};

const inventory_t elevation_req[] = {
    {
        .stones = {1, 0, 0, 0, 0, 0}
    },
    {
        .stones = {1, 1, 1, 0, 0, 0}
    },
    {
        .stones = {2, 0, 1, 0, 2, 0}
    },
    {
        .stones = {1, 1, 2, 0, 1, 0}
    },
    {
        .stones = {1, 2, 1, 3, 0, 0}
    },
    {
        .stones = {1, 2, 3, 0, 1, 0}
    },
    {
        .stones = {2, 2, 2, 2, 2, 1}
    },
};

static void send_graphical_elevation_info(struct server *server,
struct client *client, int mode)
{
    char *form = NULL;

    if (mode == START_ELEVATION)
        form = "pic %d %d %d\n";
    if (mode == END_ELEVATION)
        form = "pie %d %d %d\n";
    send_graphical_broadcast(server, form, client->x, client->y, client->level);
}

static bool is_participant_valid(const struct client *a, const struct client *b)
{
    return a->type == CT_AI && a->x == b->x && a->y == b->y;
}

/**
** Depending on the elevation requested :
**
** - You need a minimum number of players of the same level on the same square
** - These players inventories sum is at least equal to the required stones
*/

static bool check_requirement(struct server *server, struct client *client)
{
    int clients = 0;
    inventory_t total_inv = {0};

    for (size_t i = 0; server->clients[i] != NULL; i++) {
        if (is_participant_valid(server->clients[i], client)) {
            inventory_add(&total_inv, &server->clients[i]->inventory);
            clients++;
        }
    }
    return client_req[client->level - 1] <= clients &&
        inventory_ge_cmp(&total_inv, &elevation_req[client->level - 1]);
}

int incantation_callback(struct server *server, struct client *client,
int argc, char **argv)
{
    (void)argc;
    (void)argv;
    if (!check_requirement(server, client))
        return send_client_msg(client, "ko\n"), -1;
    for (size_t i = 0; server->clients[i] != NULL; i++) {
        if (!is_participant_valid(client, server->clients[i]))
            continue;
        if (server->clients[i]->level < 8)
            server->clients[i]->level += 1;
        send_client_msg(server->clients[i], format, server->clients[i]->level);
    }
    send_graphical_elevation_info(server, client, END_ELEVATION);
    return 0;
}

int command_incantation(struct server *server, struct client *client,
                        int argc, char **argv)
{
    suseconds_t time;
    event_t *event;

    (void)argc;
    (void)argv;
    if (!check_requirement(server, client))
        return send_client_msg(client, "ko\n"), -1;
    send_graphical_elevation_info(server, client, START_ELEVATION);
    time = compute_trigger_time(300, server->options.freq);
    if (time == -1)
        return -1;
    event = create_event(time, 0, NULL, &incantation_callback);
    if (!event)
        return -1;
    return add_event(client, event);
}
