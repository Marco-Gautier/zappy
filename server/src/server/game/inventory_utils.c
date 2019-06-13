/*
** EPITECH PROJECT, 2019
** inventory_utils
** File description:
** inventory_utils
*/

#include "inventory.h"

void inventory_add(inventory_t *inv1, const inventory_t *inv2)
{
    inv1->food += inv2->food;
    for (int i = 0; i < C_CAOUILLOUX_SIZE; i++)
        inv1->stones[i] += inv2->stones[i];
}

bool inventory_ge_cmp(const inventory_t *inv1, const inventory_t *inv2)
{
    if (inv1->food < inv2->food)
        return false;
    for (int i = 0; i < C_CAOUILLOUX_SIZE; i++)
        if (inv1->stones[i] < inv2->stones[i])
            return false;
    return true;
}
