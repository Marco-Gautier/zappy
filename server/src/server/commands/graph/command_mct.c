/*
** EPITECH PROJECT, 2019
** command_mct
** File description:
** command_mct
*/

#include <stdio.h>
#include <stdlib.h>
#include "zappy.h"
#include "my.h"

int command_mct_builtin(struct server *server, int client, int j)
{
    char buff[128];
    char **argv;

    for (int i = 0; i < server->options.width; i++) {
        if (snprintf(buff, 128, "bct %d %d", i, j) == -1)
            return -1;
        argv = my_str_to_word_array(buff, " ");
        if (!argv)
            return -1;
        if (command_bct(server, client, 3, argv) == -1)
            return -1;
        free(argv);
    }
    return 0;
}

int command_mct(struct server *server, int client, int argc, char **argv)
{
    (void)argc;
    (void)argv;
    for (int j = 0; j < server->options.height; j++)
        if (command_mct_builtin(server, client, j) == -1)
            return -1;
    return 0;
}
