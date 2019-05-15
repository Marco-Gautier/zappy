/*
** EPITECH PROJECT, 2018
** tests_my_str_to_word_array
** File description:
** tests_my_str_to_word_array
*/

#include <assert.h>
#include <criterion/criterion.h>
#include "my.h"

Test(my_str_to_word_array, hard)
{
    char *s = strdup(" je test \t mon my_str_to_word_array  \n");
    char **test = my_str_to_word_array(s, " \t\n");

    assert(strcmp(test[0], "je") == 0);
    assert(strcmp(test[1], "test") == 0);
    assert(strcmp(test[2], "mon") == 0);
    assert(strcmp(test[3], "my_str_to_word_array") == 0);
    assert(test[4] == NULL);
}

Test(my_str_to_word_array, simple1)
{
    char *s = strdup("mdr");
    char **test = my_str_to_word_array(s, " \t\n");

    assert(strcmp(test[0], "mdr") == 0);
    assert(test[1] == NULL);
}

Test(my_str_to_word_array, empty)
{
    char *s = strdup("\n\n     \t");
    char **test = my_str_to_word_array(s, " \t\n");

    assert(test[0] == NULL);
}
