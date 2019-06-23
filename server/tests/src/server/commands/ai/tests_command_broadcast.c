/*
** EPITECH PROJECT, 2019
** PSU_zappy_2018
** File description:
** tests_command_broadcast
*/

#include <criterion/criterion.h>
#include "zappy.h"

int broadcast_callback(struct server *s, struct client *client, int ac, char **av);

Test(command_broadcast, test_forward_event_creation)
{
    struct client client = { .event = NULL };
    struct client *clients[] = {
        &client,
        NULL
    };
    struct server server = {
        .clients = clients,
        .options.freq = 100
    };
    char *argv[3] = {
        "Broadcast",
        "mdr",
        NULL
    };

    cr_assert(command_broadcast(&server, 0, 3, argv) == 0);
    cr_assert(server.clients[0]->event != NULL);
    cr_assert(server.clients[0]->event->callback == broadcast_callback);
}
