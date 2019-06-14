/*
** EPITECH PROJECT, 2019
** zappy
** File description:
** zappy
*/

#pragma once

#include "client.h"
#include "commands.h"
#include "middleware.h"

#define ARRAY_SIZE(arr)     (sizeof(arr) / sizeof((arr)[0]))

#define MAX_CLIENTS (1024)

void    read_clients_fd(struct server *server);
int     exec_client_command(struct server *server, int i);
void    kick_client_from_server(struct server *server, int i);
void    send_graphical_broadcast(struct server *serve, const char *format, ...);
int     get_nb_free_team_slot(struct server *server, const char *team_name);
int     client_join_team(struct server *serv, struct client *clien, char **cmd);
void    update_events(struct server *server);
bool    is_game_over(struct server *server);
void    kick_dead_client(struct server *server);
