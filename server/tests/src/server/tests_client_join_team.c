/*
** EPITECH PROJECT, 2019
** tests_client_join_team
** File description:
** tests_client_join_team
*/

#include <assert.h>
#include <criterion/criterion.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "zappy.h"

Test(client_join_team, join_graphic)
{
    struct client client;
    struct client *clients[] = {
        &client,
        NULL
    };
    struct server server = {
        .clients = clients,
    };
    static const char * const argv[] = {"GRAPHIC", NULL};

    assert(client_join_team(&server, &client, (char **)argv) == 0);
    assert(strcmp("GRAPHIC", client.team_name) == 0);
    assert(client.client_type == CT_GRAPHIC);
}

Test(client_join_team, join_team1)
{
    struct client client = {
        .x = 24,
        .y = 42,
        .id = 84,
        .level = 168,
        .event = NULL
    };
    struct client *clients[] = {
        &client,
        NULL
    };
    struct server server = {
        .clients = clients,
    };
    static const char * const argv[] = {"team1", NULL};

    close(STDOUT_FILENO);
    cr_assert(parse_options(&server.options, 0, NULL) == 0);
    cr_assert(client_join_team(&server, &client, (char **)argv) == 0);
    cr_assert(strcmp("team1", client.team_name) == 0);
    cr_assert(client.client_type == CT_AI);
}
