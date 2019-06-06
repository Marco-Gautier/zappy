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
    {"bct", API_GRAPH,      command_bct},
    {"msz", API_GRAPH,      command_msz},
    {"mct", API_GRAPH,      command_mct},
    {"pin", API_TARGET,     command_pin},
    {"plv", API_TARGET,     command_plv},
    {"ppo", API_TARGET,     command_ppo},
    {"sgt", API_GRAPH,      command_sgt},
    {"sst", API_GRAPH,      command_sst},
    {"tna", API_GRAPH,      command_tna},
    {"test", API_AI,        command_test},
    {"Forward", API_AI,     command_forward},
    {"Right", API_AI,       command_right},
    {NULL,  NO_MIDDLEWARE,  command_unknown}
};

/*
** 1) Walk through the commands list
** 2) Call all middleware
** 3) Then, call the callback
*/

static int exec_client_cmd(struct server *server, int client, char **argv)
{
    size_t i;
    int argc = my_tablen(argv);
    middleware_t middleware;

    for (i = 0; command_helper[i].name != NULL; i++)
        if (!strcmp(command_helper[i].name, argv[0]))
            break;
    for (int j = 0; command_helper[i].middleware[j] != NULL; j++) {
        middleware = command_helper[i].middleware[j];
        if (middleware(server, client, argc, argv) == -1)
            return command_unknown(server, client, argc, argv), -1;
    }
    return command_helper[i].callback(server, client, argc, argv);
}

/*
** 1) Extract one command from client buffer
** 2) Erase it from the buffer
*/

char **prepare_command(struct client *client, char **tmp)
{
    char *idx = strchr(client->buffer, '\n');
    char **command;

    *tmp = client->buffer;
    if (!idx)
        return NULL;
    *idx = '\0';
    command = my_str_to_word_array(client->buffer, " \t");
    if (!command)
        return NULL;
    if (!command[0])
        return free(command), NULL;
    client->buffer = strdup(idx + 1);
    return command;
}

/*
** Execute command in the buffer of the client n°i
*/

int exec_client_command(struct server *server, int i)
{
    char *tmp;
    char **command = prepare_command(server->clients[i], &tmp);

    if (!command)
        return -1;
    if (!server->clients[i]->team_name)
        client_join_team(server, i, command);
    else
        exec_client_cmd(server, i, command);
    free(tmp);
    free(command);
    return 0;
}
