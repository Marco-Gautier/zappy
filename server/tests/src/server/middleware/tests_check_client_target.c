/*
** EPITECH PROJECT, 2019
** tests_check_client_target
** File description:
** tests_check_client_target
*/

#include <assert.h>
#include <criterion/criterion.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "zappy.h"

Test(check_client_target, true)
{
    struct client client1 = {
        .id = 4,
        .type = CT_AI,
        .team_name = "team1"
    };
    struct client client2 = {
        .id = 8,
        .type = CT_AI,
        .team_name = "team1"
    };
    struct client *clients[] = {
        &client1,
        &client2,
        NULL
    };
    struct server server = {
        .clients = clients,
    };
    int argc = 2;
    char *argv[3] = { "pin", "4", NULL };

    assert(check_client_target(&server, &client1, argc, argv) == 0);
}

Test(check_client_target, false_graphic)
{
    struct client client = {
        .id = 4,
        .type = CT_GRAPHIC,
        .team_name = "team1"
    };
    struct client *clients[] = {
        &client,
        NULL
    };
    struct server server = {
        .clients = clients,
    };
    int argc = 2;
    char *argv[3] = { "pin", "4", NULL };

    assert(check_client_target(&server, &client, argc, argv) == -1);
}

Test(check_client_target, false_id)
{
    struct client client = {
        .id = 123,
        .type = CT_AI,
        .team_name = "team1"
    };
    struct client *clients[] = {
        &client,
        NULL
    };
    struct server server = {
        .clients = clients,
    };
    int argc = 2;
    char *argv[3] = { "pin", "42", NULL };

    assert(check_client_target(&server, &client, argc, argv) == -1);
}

Test(check_client_target, bad_argc)
{
    struct client client = {
        .id = 123,
        .type = CT_AI,
        .team_name = "team1"
    };
    struct client *clients[] = {
        &client,
        &client,
        NULL
    };
    struct server server = {
        .clients = clients,
    };
    int argc = 1;
    char *argv[2] = { "pin", NULL };

    assert(check_client_target(&server, &client, argc, argv) == -1);
}

Test(check_client_target, argv_neg)
{
    struct client client1 = {
        .id = 123,
        .type = CT_AI,
        .team_name = "team1"
    };
    struct client client2 = {
        .id = 246,
        .type = CT_AI,
        .team_name = "team1"
    };
    struct client *clients[] = {
        &client1,
        &client2,
        NULL
    };
    struct server server = {
        .clients = clients,
    };
    int argc = 2;
    char *argv[3] = { "pin", "-42", NULL };

    assert(check_client_target(&server, &client1, argc, argv) == -1);
}

Test(check_client_target, team_NULL)
{
    struct client client = {
        .id = 123,
        .type = CT_AI,
        .team_name = NULL
    };
    struct client *clients[] = {
        &client,
        NULL
    };
    struct server server = {
        .clients = clients,
    };
    int argc = 2;
    char *argv[3] = { "pin", "42", NULL };

    assert(check_client_target(&server, &client, argc, argv) == -1);
}
