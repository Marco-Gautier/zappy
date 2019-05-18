/*
** EPITECH PROJECT, 2019
** exec_client_cmd
** File description:
** exec_client_cmd
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "zappy.h"
#include "my.h"

const struct command command_helper[] = {
    {"msz",     command_msz},
    {NULL,      command_unknown}
};

/*
** 1) Walk through the commands list
** 2) Call all middleware
** 3) Then, call the callback
*/

static int exec_client_cmd(struct server *server, int client, char **cmd)
{
    size_t len;

    for (int i = 0; cmd[i]; i++)
        printf("%s ", cmd[i]);
    putchar('\n');
    for (size_t i = 0; command_helper[i].name != NULL; i++)
        if (!strcmp(command_helper[i].name, cmd[0]) == 0) {
            len = my_tablen(cmd);
            return command_helper[i].callback(server, client, len, cmd);
        }
    return -1;
}

/*
** 1) Extract one command from client buffer
** 2) Erase it from the buffer
*/

char **prepare_command(struct client *client)
{
    char *tmp = client->buffer;
    char *idx = strchr(client->buffer, '\n');
    char **command;

    if (!idx)
        return NULL;
    *idx = '\0';
    command = my_str_to_word_array(client->buffer, " \t");
    if (!command || !command[0])
        return NULL;
    client->buffer = strdup(idx + 1);
    free(tmp);
    return command;
}

/*
** Execute command in the buffer of the client n°i
*/

int exec_client_command(struct server *server, int i)
{
    char **command = prepare_command(server->clients[i]);

    if (!command)
        return -1;
    for (int i = 0; command[i]; i++)
        printf("%s ", command[i]);
    putchar('\n');
    if (server->clients[i]->team_name == NULL);
//        server_get_client_team_name(server, i);
    else
        exec_client_cmd(server, i, command);
    return 0;
}
