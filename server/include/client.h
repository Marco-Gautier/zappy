/*
** EPITECH PROJECT, 2019
** client
** File description:
** client
*/

#pragma once

#include <stdbool.h>
//#include "inventory.h"

enum direction {
    D_EAST,
    D_WEST,
    D_NORTH,
    D_SOUTH,
    D_DIRECTION_SIZE
};

enum client_type {
    CT_AI,
    CT_GRAPHIC
};

struct client {
    int     fd;
    int     y;
    int     x;
    int     level;
    int     egg_id;
    char    *buffer;
    bool    hatched;
    enum client_type    client_type;
    const char          *team_name;
    enum direction      direction;
//    struct inventory    inventory;
};
