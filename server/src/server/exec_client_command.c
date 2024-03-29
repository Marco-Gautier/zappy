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
    {"bct",         API_GRAPH,      command_bct},
    {"msz",         API_GRAPH,      command_msz},
    {"mct",         API_GRAPH,      command_mct},
    {"pin",         API_TARGET,     command_pin},
    {"plv",         API_TARGET,     command_plv},
    {"ppo",         API_TARGET,     command_ppo},
    {"sgt",         API_GRAPH,      command_sgt},
    {"sst",         API_GRAPH,      command_sst},
    {"tna",         API_GRAPH,      command_tna},
    {"Forward",     API_AI,         command_forward},
    {"Right",       API_AI,         command_right},
    {"Left",        API_AI,         command_left},
    {"Inventory",   API_AI,         command_inventory},
    {"Connect_nbr", API_AI,         command_connect_nbr},
    {"Take",        API_AI,         command_take},
    {"Set",         API_AI,         command_take},
    {"Look",        API_AI,         command_look},
    {"Incantation", API_AI,         command_incantation},
    {"Fork",        API_AI,         command_fork},
    {"Eject",       API_AI,         command_eject},
    {"Broadcast",   API_AI,         command_broadcast},
    {NULL,          NO_MIDDLEWARE,  command_unknown}
};

/**
** 1) Walk through the commands list
**
** 2) Call all middleware
**
** 3) Then, call the callback
*/

static int exec_client_cmd(struct server *server, struct client *client,
                           char **argv)
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

/**
** 1) Extract one command from client buffer
**
** 2) Erase it from the buffer
*/

static char **prepare_command(struct client *client, char **tmp)
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

/**
** Execute command in the buffer of the client n°i
*/

int exec_client_command(struct server *server, struct client *client)
{
    int ret = 0;
    char *tmp;
    char **command = prepare_command(client, &tmp);

    if (!command)
        return -1;
    if (!client->team_name) {
        ret = client_join_team(server, client, command);
        if (ret == -1)
            dprintf(client->fd, "ko\n");
    } else
        ret = exec_client_cmd(server, client, command);
    return ret;
}
