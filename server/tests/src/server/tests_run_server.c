/*
** EPITECH PROJECT, 2019
** tests_run_server
** File description:
** tests_run_server
*/

#include <assert.h>
#include <criterion/criterion.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "zappy.h"

Test(run_server, team_win)
{
    struct client client = {
        .team_name = "team1",
        .type = CT_AI,
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
        .events = NULL,
        .clients = clients
    };

    close(STDOUT_FILENO);
    assert(parse_options(&server.options, 0, NULL) == 0);
    assert(run_server(&server) == 0);
}
