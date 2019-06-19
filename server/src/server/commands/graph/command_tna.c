/*
** EPITECH PROJECT, 2019
** command_tna
** File description:
** command_tna
*/

#include <stdio.h>
#include <string.h>
#include "zappy.h"

static const char *format = "tna %s\n";

int command_tna(struct server *server, int i, int argc, char **argv)
{
    char buffer[BUFSIZ];
    char tmp[128];

    (void)argc;
    (void)argv;
    buffer[0] = '\0';
    for (size_t j = 0; server->options.team_names[j] != NULL; j++) {
        snprintf(tmp, sizeof(tmp), format, server->options.team_names[j]);
        strcat(buffer, tmp);
    }
    if (buffer[0] != '\0')
        return send_client_msg(server->clients[i], "%s", buffer);
    return -1;
}
