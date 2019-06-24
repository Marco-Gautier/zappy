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

Test(client_join_team, bad_argc)
{
    struct client client;
    struct client *clients[] = {
        &client,
        NULL
    };
    struct server server = {
        .clients = clients,
    };
    char *argv[3] = {"ppo", "42", NULL};

    assert(client_join_team(&server, &client, argv) == -1);
}

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
    char *argv[2] = {"GRAPHIC", NULL};

    assert(client_join_team(&server, &client, argv) == 0);
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
    char *argv[2] = {"team1", NULL};

    close(STDOUT_FILENO);
    cr_assert(parse_options(&server.options, 0, NULL) == 0);
    cr_assert(client_join_team(&server, &client, argv) == 0);
    cr_assert(strcmp("team1", client.team_name) == 0);
    cr_assert(client.client_type == CT_AI);
}

Test(client_join_team, full_team)
{
    struct client client1 = {
        .x = 24,
        .y = 42,
        .id = 84,
        .level = 168,
        .event = NULL,
        .team_name = NULL
    };
    struct client client2 = {
        .x = 42,
        .y = 24,
        .id = 48,
        .level = 861,
        .event = NULL,
        .team_name = NULL
    };
    struct client *clients[] = {
        &client1,
        &client2,
        NULL
    };
    struct server server = {
        .clients = clients,
    };
    char *argv[2] = {"team1", NULL};

    close(STDOUT_FILENO);
    cr_assert(parse_options(&server.options, 0, NULL) == 0);
    server.options.max_team_nbr = 1;
    cr_assert(client_join_team(&server, &client1, argv) == 0);
    cr_assert(strcmp("team1", client1.team_name) == 0);
    cr_assert(client1.client_type == CT_AI);
    cr_assert(client_join_team(&server, &client2, argv) == -1);
}
