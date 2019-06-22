/*
** EPITECH PROJECT, 2019
** sound
** File description:
** sound
*/

#pragma once

#include <math.h>

#ifndef M_PI_8
# define M_PI_8 (M_PI / 8)
#endif

enum sound_direction {
    SD_NONE,
    SD_NORTH,
    SD_NORTH_WEST,
    SD_WEST,
    SD_SOUTH_WEST,
    SD_SOUTH,
    SD_SOUTH_EAST,
    SD_EAST,
    SD_NORTH_EAST
};

struct vector {
    double  x;
    double  y;
};

struct sound_helper {
    double  min;
    double  max;
    enum sound_direction direction;
};
