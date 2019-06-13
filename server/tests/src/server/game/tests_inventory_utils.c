/*
** EPITECH PROJECT, 2019
** tests_inventory_utils
** File description:
** tests_inventory_utils
*/

#include <stdio.h>
#include <unistd.h>
#include <assert.h>
#include <criterion/criterion.h>
#include "zappy.h"

Test(inventory, inventory_add)
{
    inventory_t inv1 = {
        .food = 1,
        .stones = {2, 3, 4, 5, 6, 7}
    };
    inventory_t inv2 = {
        .food = 8,
        .stones = {9, 10, 11, 12, 13, 14}
    };

    inventory_add(&inv1, &inv2);
    assert(inv1.food == 9);
    assert(inv1.stones[C_LINEMATE] == 11);
    assert(inv1.stones[C_DERAUMERE] == 13);
    assert(inv1.stones[C_SIBUR] == 15);
    assert(inv1.stones[C_MENDIANE] == 17);
    assert(inv1.stones[C_PHIRAS] == 19);
    assert(inv1.stones[C_THYSTAME] == 21);
}

Test(inventory, inventory_ge_cmp)
{
    inventory_t inv1 = {
        .food = 1,
        .stones = {2, 3, 4, 5, 6, 7}
    };
    inventory_t inv2 = {
        .food = 8,
        .stones = {9, 10, 11, 12, 13, 14}
    };

    assert(inventory_ge_cmp(&inv2, &inv1) == true);
    assert(inventory_ge_cmp(&inv1, &inv2) == false);
}
