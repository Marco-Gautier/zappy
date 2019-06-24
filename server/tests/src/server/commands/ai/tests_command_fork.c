/*
** EPITECH PROJECT, 2019
** PSU_zappy_2018
** File description:
** tests_command_fork
*/

#include <criterion/criterion.h>
#include "zappy.h"

Test(command_fork, test_fork_event_creation)
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

    cr_assert(command_fork(&server, &client, 1, NULL) == 0);
    cr_assert(server.clients[0]->event != NULL);
    cr_assert(server.clients[0]->event->callback == fork_callback);
}
