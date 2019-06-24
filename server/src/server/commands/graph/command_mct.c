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

static const char *format = "bct %d %d";

int command_mct_builtin(struct server *server, struct client *client,
                        int height)
{
    char buff[128];
    char **argv;

    for (int i = 0; i < server->options.width; i++) {
        if (snprintf(buff, 128, format, i, height) == -1)
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

int command_mct(struct server *server, struct client *client,
                int argc, char **argv)
{
    (void)argc;
    (void)argv;
    for (int height = 0; height < server->options.height; height++)
        if (command_mct_builtin(server, client, height) == -1)
            return -1;
    return 0;
}
