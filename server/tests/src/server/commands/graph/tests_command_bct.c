/*
** EPITECH PROJECT, 2019
** tests_command_bct
** File description:
** tests_command_bct
*/

#include <stdio.h>
#include <unistd.h>
#include <assert.h>
#include <criterion/criterion.h>
#include "zappy.h"

Test(command_bct, error_parameter_nbr)
{
        struct client client = {
            .fd = STDOUT_FILENO
        };
        struct client *clients[] = {
            &client,
            NULL
        };
        struct server server = {
            .clients = clients,
            .options = {
                .width = 10,
                .height = 10
            }
        };

        close(STDOUT_FILENO);
        cr_assert(command_bct(&server, 0, 2, NULL) == -1);
        cr_assert(command_bct(&server, 0, 4, NULL) == -1);
}

Test(command_bct, error_bad_parameter)
{
        struct client client = {
            .fd = STDOUT_FILENO
        };
        struct client *clients[] = {
            &client,
            NULL
        };
        int argc = 3;
        struct server server = {
            .clients = clients,
            .options = {
                .width = 10,
                .height = 10
            }
        };
        static const char * const argv1[] = { "bct", "1", "-1" };
        static const char * const argv2[] = { "bct", "-1", "1" };
        static const char * const argv3[] = { "bct", "1", "10" };
        static const char * const argv4[] = { "bct", "10", "1" };

        close(STDOUT_FILENO);
        cr_assert(command_bct(&server, 0, argc, (char **)argv1) == -1);
        cr_assert(command_bct(&server, 0, argc, (char **)argv2) == -1);
        cr_assert(command_bct(&server, 0, argc, (char **)argv3) == -1);
        cr_assert(command_bct(&server, 0, argc, (char **)argv4) == -1);
}

Test(command_bct, success)
{
    struct client client;
    struct client *clients[] = {
        &client,
        NULL
    };
    int argc = 3;
    int pipefd[2];
    struct server server = {
        .clients = clients,
        .options = {
            .width = 10,
            .height = 10
        }
    };
    static const char * const argv[] = { "bct", "2", "3" };
    char buffer[512] = { 0 };
    cell_t cell = {
        .food = 1,
        .stones = {2, 3, 4, 5, 6, 7}
    };

    assert(pipe(pipefd) == 0);
    client.fd = pipefd[1];
    init_world(&server.world, &server.options);
    server.world.map[3][2] = cell;
    assert(command_bct(&server, 0, argc, (char **)argv) != -1);
    read(pipefd[0], buffer, 512);
    assert(strcmp(buffer, "bct 2 3 1 2 3 4 5 6 7\n") == 0);
    close(pipefd[0]);
    close(pipefd[1]);
}
