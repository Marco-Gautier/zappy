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
    static const char * const tab[] = {
        "Lolmdr",
        NULL
    };
    assert(my_tablen((char **)tab) == 1);
}

Test(tablen, medium)
{
    static const char * const tab[] = {
        "Lolmdr",
        "Lolmdr",
        "Lolmdr",
        "Lolmdr",
        NULL
    };
    assert(my_tablen((char **)tab) == 4);
}
