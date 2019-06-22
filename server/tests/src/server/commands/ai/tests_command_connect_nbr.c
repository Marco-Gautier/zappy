/*
** EPITECH PROJECT, 2019
** PSU_zappy_2018
** File description:
** tests_command_connect_nbr
*/

#include <criterion/criterion.h>
#include <unistd.h>
#include "zappy.h"

Test(command_connect_nbr, basic_connect_nbr_call)
{
    int pipefd[2];
    char *names[2] = { "team1", NULL };
    struct client client = {
        .team_name = "team1",
        .hatched = false
    };
    struct client *clients[] = {
        &client,
        NULL
    };
    struct server server = {
        .clients = clients,
        .options.max_team_nbr = 4,
        .options.team_names = names
    };
    char buffer[512] = { 0 };

    cr_assert(pipe(pipefd) == 0);
    server.clients[0]->fd = pipefd[1];
    cr_assert(command_connect_nbr(&server, 0, 1, NULL) != -1);
    read(pipefd[0], buffer, 512);
    cr_assert(strcmp(buffer, "3\n") == 0);
    close(pipefd[0]);
    close(pipefd[1]);
}

Test(command_connect_nbr, connect_nbr_no_team_name)
{
    int pipefd[2];
    struct client client;
    struct client *clients[] = {
        &client,
        NULL
    };
    struct server server = {
        .clients = clients
    };
    char buffer[512] = { 0 };

    cr_assert(pipe(pipefd) == 0);
    server.clients[0]->fd = pipefd[1];
    cr_assert(command_connect_nbr(&server, 0, 1, NULL) != -1);
    read(pipefd[0], buffer, 512);
    cr_assert(strcmp(buffer, "-1\n") == 0);
    close(pipefd[0]);
    close(pipefd[1]);
}

Test(command_connect_nbr, connect_nbr_no_max_team_nbr)
{
    int pipefd[2];
    struct client client = {
        .team_name = "mdr"
    };
    struct client *clients[] = {
        &client,
        NULL
    };
    struct server server = {
        .clients = clients
    };
    char buffer[512] = { 0 };

    cr_assert(pipe(pipefd) == 0);
    server.clients[0]->fd = pipefd[1];
    cr_assert(command_connect_nbr(&server, 0, 1, NULL) != -1);
    read(pipefd[0], buffer, 512);
    cr_assert(strcmp(buffer, "-1\n") == 0);
    close(pipefd[0]);
    close(pipefd[1]);
}

Test(command_connect_nbr, connect_nbr_invalid_team_name)
{
    int pipefd[2];
    char *names[2] = { "team1", NULL };
    struct client client = {
        .team_name = "mdr"
    };
    struct client *clients[] = {
        &client,
        NULL
    };
    struct server server = {
        .clients = clients,
        .options.max_team_nbr = 4,
        .options.team_names = names
    };
    char buffer[512] = { 0 };

    cr_assert(pipe(pipefd) == 0);
    server.clients[0]->fd = pipefd[1];
    cr_assert(command_connect_nbr(&server, 0, 1, NULL) != -1);
    read(pipefd[0], buffer, 512);
    cr_assert(strcmp(buffer, "-1\n") == 0);
    close(pipefd[0]);
    close(pipefd[1]);
}
