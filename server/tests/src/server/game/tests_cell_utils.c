/*
** EPITECH PROJECT, 2019
** tests_cell_utils
** File description:
** tests_cell_utils
*/

#include <stdio.h>
#include <unistd.h>
#include <assert.h>
#include <criterion/criterion.h>
#include "zappy.h"

Test(init_cell, mdr)
{
    cell_t cell;
    char *ptr = (char *)&cell;

    init_cell(&cell);
    for (size_t i = 0; i < sizeof(cell); i++)
        assert(!ptr[i]);
}

Test(cell_is_empty, true)
{
    cell_t cell;

    init_cell(&cell);
    assert(cell_is_empty(&cell) == true);
}

Test(cell_is_empty, false)
{
    cell_t cell = {
        .food = 5,
        .stones = {1, 2, 3, 4, 5, 6}
    };

    assert(cell_is_empty(&cell) == false);
}
