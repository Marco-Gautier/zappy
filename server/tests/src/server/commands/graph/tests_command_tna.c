/*
** EPITECH PROJECT, 2019
** tests_command_tna.c
** File description:
** tests_command_tna.c
*/

#include <stdio.h>
#include <unistd.h>
#include <assert.h>
#include <criterion/criterion.h>
#include "zappy.h"

Test(command_tna, success)
{
    char *team_names[5] = {
        "Is",
        "mayonnaise",
        "an",
        "instrument",
        NULL
    };
    struct client client;
    struct client *clients[] = {
        &client,
        NULL
    };
    struct server server = {
        .clients = clients,
        .options = {
            .team_names = team_names
        }
    };
    int pipefd[2];
    int argc = 1;
    char *argv[2] = { "tna", NULL };
    char buffer[512] = { 0 };
    char expected_result[] =
        "tna Is\ntna mayonnaise\ntna an\ntna instrument\n";

    cr_assert(pipe(pipefd) == 0);
    client.fd = pipefd[1];
    cr_assert(command_tna(&server, &client, argc, (char **)argv) != -1);
    read(pipefd[0], buffer, 512);
    cr_assert(strcmp(buffer, expected_result) == 0);
    close(pipefd[0]);
    close(pipefd[1]);
}
