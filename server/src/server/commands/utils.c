/*
** EPITECH PROJECT, 2019
** PSU_zappy_2019
** File description:
** description
*/

#include "zappy.h"

enum direction compute_direction(enum direction dir, int offset)
{
    dir -= 1;
    return (dir + offset + (D_DIRECTION_SIZE - 1)) % (D_DIRECTION_SIZE - 1) + 1;
}
