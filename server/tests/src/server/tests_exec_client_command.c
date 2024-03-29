/*
** EPITECH PROJECT, 2019
** tests_exec_client_command
** File description:
** tests_exec_client_command
*/

#include <assert.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "zappy.h"

Test(exec_client_command, full_msz)
{
    struct client client = {
        .buffer = strdup("GRAPHIC\nmsz\n"),
        .id = 42,
        .team_name = NULL
    };
    struct client *clients[] = {
        &client,
        NULL
    };
    struct server server = {
        .clients = clients,
        .options = {
            .width = 42,
            .height = 24
        }
    };
    int pipefd[2];
    char buffer[512] = {0};

    cr_redirect_stdout();
    assert(pipe(pipefd) == 0);
    client.fd = pipefd[1];
    assert(exec_client_command(&server, &client) != -1);
    assert(exec_client_command(&server, &client) != -1);
    read(pipefd[0], buffer, sizeof(buffer));
    assert(strcmp(buffer, "msz 42 24\n") == 0);
    fflush(stdout);
    cr_assert_stdout_eq_str("Received command [msz] from client n°42\n");
}

Test(exec_client_command, bad_team)
{
    struct client client = {
        .buffer = strdup("teamMDR\n"),
        .id = 42,
        .team_name = NULL
    };
    struct client *clients[] = {
        &client,
        NULL
    };
    struct server server = {
        .clients = clients,
        .options = {
            .width = 42,
            .height = 24
        }
    };
    int pipefd[2];
    char buffer[512] = {0};

    assert(pipe(pipefd) == 0);
    client.fd = pipefd[1];
    assert(exec_client_command(&server, &client) == -1);
    read(pipefd[0], buffer, sizeof(buffer));
    assert(strcmp(buffer, "ko\n") == 0);
}

Test(exec_client_command, mdr)
{
    struct client client = {
        .buffer = strdup("mdr"),
        .id = 42,
        .team_name = NULL
    };
    struct client *clients[] = {
        &client,
        NULL
    };
    struct server server = {
        .clients = clients,
        .options = {
            .width = 42,
            .height = 24
        }
    };

    assert(strcmp(client.buffer, "mdr") == 0);
    assert(exec_client_command(&server, &client) == -1);
    assert(strcmp(client.buffer, "mdr") == 0);
}
