/*
** EPITECH PROJECT, 2019
** my
** File description:
** my
*/

#pragma once

#include <stddef.h>

#define IS_DIGIT(x) (x >= '0' && x <= '9')

char    **my_str_to_word_array(char *str, const char *delim);
char    **my_tabndup(char **tab, size_t size);
char    **my_tabdup(char **tab);
size_t  my_tablen(char **tab);
