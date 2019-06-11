/*
** EPITECH PROJECT, 2019
** tests_command_ppo
** File description:
** tests_command_ppo
*/

#include <stdio.h>
#include <unistd.h>
#include <assert.h>
#include <criterion/criterion.h>
#include "zappy.h"

Test(command_ppo, success)
{
    for (int i = 0; i < D_DIRECTION_SIZE; i++) {
        int id = rand() % 100;
        int x = rand() % 100;
        int y = rand() % 100;
        struct client client = {
            .id = id,
            .x = x,
            .y = y,
            .direction = i
        };
        struct client *clients[] = {
            &client,
            NULL
        };
        int argc = 2;
        int pipefd[2];
        struct server server = { .clients = clients };
        char *player_id = calloc(1, 16);
        snprintf(player_id, 16, "%d", id);
        const char *argv[] = { "ppo", player_id };
        char buffer[512] = {0};
        char expected[BUFSIZ] = {0};

        cr_assert(pipe(pipefd) == 0);
        client.fd = pipefd[1];
        cr_assert(command_ppo(&server, 0, argc, (char **)argv) != -1);
        read(pipefd[0], buffer, sizeof(buffer));
        snprintf(expected, sizeof(expected), "ppo %d %d %d %d\n", id, x, y, i);
        cr_assert(strcmp(buffer, expected) == 0);
        close(pipefd[0]);
        close(pipefd[1]);
    }
}
