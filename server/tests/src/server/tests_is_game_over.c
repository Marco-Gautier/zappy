/*
** EPITECH PROJECT, 2019
** tests_is_game_over
** File description:
** tests_is_game_over
*/

#include <assert.h>
#include <criterion/criterion.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "zappy.h"

static const char * const team_names[] = {
    "team1",
    "team2",
    NULL
};

Test(is_game_over, no_client)
{
    struct server server = {
        .options = {
            .team_names = (char **)team_names
        },
        .clients = NULL
    };

    assert(is_game_over(&server) == false);
}

Test(is_game_over, win)
{
    struct client client = {
        .team_name = "team1",
        .client_type = CT_AI,
        .level = 6
    };
    struct client *clients[] = {
        &client,
        &client,
        &client,
        &client,
        &client,
        &client,
        NULL
    };
    struct server server = {
        .options = {
            .team_names = (char **)team_names
        },
        .clients = clients
    };

    close(STDOUT_FILENO);
    assert(is_game_over(&server) == true);
}

Test(is_game_over, lose)
{
    struct client client = {
        .team_name = "team1",
        .client_type = CT_AI,
        .level = 6
    };
    struct client client_no = {
        .team_name = "team1",
        .client_type = CT_AI,
        .level = 1
    };
    struct client *clients[] = {
        &client,
        &client,
        &client_no,
        &client,
        &client,
        &client,
        NULL
    };
    struct server server = {
        .options = {
            .team_names = (char **)team_names
        },
        .clients = clients
    };

    close(STDOUT_FILENO);
    assert(is_game_over(&server) == false);
}
