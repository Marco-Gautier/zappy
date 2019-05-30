/*
** EPITECH PROJECT, 2019
** my
** File description:
** my
*/

#pragma once

#include <stddef.h>

#define IS_DIGIT(x) (x >= '0' && x <= '9')

typedef struct __list_s
{
        struct __list_s *next;
        struct __list_s *prev;
} __list_t;

char    **my_str_to_word_array(char *str, const char *delim);
char    **my_tabndup(char **tab, size_t size);
char    **my_tabdup(char **tab);
size_t  my_tablen(char **tab);
void *  my_push_back(void *l1, void *l2);
size_t  my_listlen(void *list);
void *  my_node_destroy(void *l1, void *l2);