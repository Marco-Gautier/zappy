/*
** EPITECH PROJECT, 2019
** tests_my_tabdup
** File description:
** tests_my_tabdup
*/

#include <assert.h>
#include <criterion/criterion.h>
#include "my.h"

Test(tabdup, dup)
{
    static const char * const tab[] = {
        "bonobo",
        "gorille",
        "ouistiti",
        "babouin",
        NULL
    };
    char **copy = my_tabdup((char **)tab);

    assert(my_tablen((char **)tab) == 4);
    for (size_t i = 0; tab[i] != NULL; i++)
        assert(!strcmp(tab[i], copy[i]));
}
