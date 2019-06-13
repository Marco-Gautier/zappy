/*
** EPITECH PROJECT, 2019
** inventory
** File description:
** inventory
*/

#pragma once

#include "cell.h"

typedef struct cell inventory_t;

void inventory_add(inventory_t *inv1, const inventory_t *inv2);
bool inventory_ge_cmp(const inventory_t *inv1, const inventory_t *inv2);
