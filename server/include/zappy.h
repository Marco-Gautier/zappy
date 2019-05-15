/*
** EPITECH PROJECT, 2019
** zappy
** File description:
** zappy
*/

#pragma once

#include "options.h"

#define ARRAY_SIZE(arr)     (sizeof(arr) / sizeof((arr)[0]))
#define destructor(dtor)    __attribute__((cleanup(dtor)))

#define MAX_CLIENTS (1024)

struct server {
    struct server_opt   options;
    int                 fd;
};

int init_server(struct server *server);
