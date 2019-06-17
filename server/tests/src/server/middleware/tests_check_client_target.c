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
    struct client client = {
        .id = 4,
        .client_type = CT_AI,
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
    int argc = 2;
    static const char * const argv[] = { "pin", "4" };

    assert(check_client_target(&server, 0, argc, (char **)argv) == 0);
}

Test(check_client_target, false_graphic)
{
    struct client client = {
        .id = 4,
        .client_type = CT_GRAPHIC,
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
    int argc = 2;
    static const char * const argv[] = { "pin", "4" };

    assert(check_client_target(&server, 0, argc, (char **)argv) == -1);
}

Test(check_client_target, false_id)
{
    struct client client = {
        .id = 123,
        .client_type = CT_AI,
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
    int argc = 2;
    static const char * const argv[] = { "pin", "42" };

    assert(check_client_target(&server, 0, argc, (char **)argv) == -1);
}
