/*
** EPITECH PROJECT, 2018
** tests_my_tablen
** File description:
** tests_my_tablen
*/

#include <assert.h>
#include <criterion/criterion.h>
#include "my.h"

Test(tablen, simple)
{
        char *tab[] = {
                "Lolmdr",
                NULL
        };
        assert(my_tablen(tab) == 1);
}

Test(tablen, medium)
{
        char *tab[] = {
                "Lolmdr",
                "Lolmdr",
                "Lolmdr",
                "Lolmdr",
                NULL
        };
        assert(my_tablen(tab) == 4);
}