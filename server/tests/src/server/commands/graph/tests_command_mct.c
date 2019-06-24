/*
** EPITECH PROJECT, 2019
** tests_command_mct
** File description:
** tests_command_mct
*/

#include <stdio.h>
#include <unistd.h>
#include <assert.h>
#include <criterion/criterion.h>
#include "zappy.h"

static void setup_expected_result(char expected_result[1024])
{
    snprintf(expected_result, 1024,
             "%s\n%s\n%s\n%s\n%s\n%s\n",
             "bct 0 0 0 0 0 0 0 0 0",
             "bct 1 0 0 0 0 0 0 0 0",
             "bct 0 1 0 0 0 0 0 0 0",
             "bct 1 1 0 0 0 0 0 0 0",
             "bct 0 2 0 0 0 0 0 0 0",
             "bct 1 2 0 0 0 0 0 0 0");
}

Test(command_mct, success)
{
    struct client client;
    struct client *clients[] = {
        &client,
        NULL
    };
    struct server server = {
        .clients = clients,
        .options = {
            .width = 2,
            .height = 3
        }
    };
    int pipefd[2];
    int argc = 2;
    char *argv[2] = { "mct", NULL };
    char buffer[1024] = { 0 };
    char expected_result[1024] = { 0 };

    assert(pipe(pipefd) == 0);
    client.fd = pipefd[1];
    setup_expected_result(expected_result);
    init_world(&server.world, &server.options);
    assert(command_mct(&server, &client, argc, argv) == 0);
    read(pipefd[0], buffer, 1024);
    assert(strcmp(buffer, expected_result) == 0);
    close(pipefd[0]);
    close(pipefd[1]);
}
