/*
** EPITECH PROJECT, 2019
** tests_get_nb_free_team_slot
** File description:
** tests_get_nb_free_team_slot
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

Test(get_nb_free_team_slot, bad_team_name)
{
    struct server server = {
        .options = {
            .max_team_nbr = 10,
            .team_names = (char **)team_names
        },
    };

    assert(get_nb_free_team_slot(&server, "mdr") == -1);
}

Test(get_nb_free_team_slot, no_client)
{
    struct client *clients[] = {
        NULL
    };
    struct server server = {
        .options = {
            .max_team_nbr = 10,
            .team_names = (char **)team_names
        },
        .clients = clients
    };

    assert(get_nb_free_team_slot(&server, "team1") == 10);
}

Test(get_nb_free_team_slot, 1_client)
{
    struct client client = {
        .team_name = "team1"
    };
    struct client *clients[] = {
        &client,
        NULL
    };
    struct server server = {
        .options = {
            .max_team_nbr = 10,
            .team_names = (char **)team_names
        },
        .clients = clients
    };

    assert(get_nb_free_team_slot(&server, "team1") == 9);
}

Test(get_nb_free_team_slot, 2_client)
{
    struct client client = {
        .team_name = "team1"
    };
    struct client *clients[] = {
        &client,
        &client,
        NULL
    };
    struct server server = {
        .options = {
            .max_team_nbr = 10,
            .team_names = (char **)team_names
        },
        .clients = clients
    };

    assert(get_nb_free_team_slot(&server, "team1") == 8);
}

Test(get_nb_free_team_slot, full_team)
{
    struct client client = {
        .team_name = "team1"
    };
    struct client *clients[] = {
        &client,
        &client,
        &client,
        &client,
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
            .max_team_nbr = 10,
            .team_names = (char **)team_names
        },
        .clients = clients
    };

    assert(get_nb_free_team_slot(&server, "team1") == 0);
}
