/*
** EPITECH PROJECT, 2018
** tests_my_tabndup
** File description:
** tests_my_tabndup
*/

#include <assert.h>
#include <criterion/criterion.h>
#include "my.h"

Test(my_tabndup, 0_len)
{
        assert(my_tabndup(NULL, 0) == NULL);
}

Test(my_tabndup, copy)
{
        static const char * const tab[] = {
                "bonobo",
                "gorille",
                "ouistiti",
                "babouin",
                NULL
        };
        char **copy = my_tabndup((char **)tab, my_tablen((char **)tab));

        assert(my_tablen((char **)tab) == 4);
        for (int i = 0; tab[i] != 0; i++)
                assert(strcmp(tab[i], copy[i]) == 0);
}
