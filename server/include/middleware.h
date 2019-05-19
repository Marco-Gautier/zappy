/*
** EPITECH PROJECT, 2019
** middleware
** File description:
** middleware
*/

#pragma once

#include "server.h"

#define COMMAND_NO_ACCESS ("Only %s client can access this request.\n")

#define MIDDLEWARE_NB   3

#define NO_MIDDLEWARE   {NULL}
#define API_AI          {log_command, filter_ai_request}
#define API_GRAPH       {log_command, filter_graphic_request}

typedef int (*middleware_t)(struct server *serve, int i, int argc, char **argv);

int log_command(struct server *server, int i, int argc, char **argv);
int filter_ai_request(struct server *server, int i, int argc, char **argv);
int filter_graphic_request(struct server *server, int i, int argc, char **argv);
