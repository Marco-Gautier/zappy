/*
** EPITECH PROJECT, 2019
** client
** File description:
** client
*/

#pragma once

#include <stdbool.h>
#include "inventory.h"
#include "event.h"

enum direction {
    D_NORTH = 1,
    D_EAST,
    D_SOUTH,
    D_WEST,
    D_DIRECTION_SIZE
};

enum client_type {
    CT_AI,
    CT_GRAPHIC
};

struct client {
    int     fd;
    int     id;
    int     y;
    int     x;
    int     level;
    int     egg_id;
    int     egg_nb;
    char    *buffer;
    bool    hatched;
    char    *team_name;
    struct event        *event;
    enum client_type    client_type;
    enum direction      direction;
    inventory_t         inventory;
};
