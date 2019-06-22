/*
** EPITECH PROJECT, 2019
** PSU_zappy_2018
** File description:
** tests_command_eject
*/

#include <criterion/criterion.h>
#include "zappy.h"

int eject_callback(struct server *s, struct client *client, int ac, char **av);

Test(command_eject, test_forward_event_creation)
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

    cr_assert(command_eject(&server, 0, 1, NULL) == 0);
    cr_assert(server.clients[0]->event != NULL);
    cr_assert(server.clients[0]->event->callback == eject_callback);
}
