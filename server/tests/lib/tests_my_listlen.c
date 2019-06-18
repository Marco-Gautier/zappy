/*
** EPITECH PROJECT, 2019
** tests_my_listlen
** File description:
** tests_my_listlen
*/

#include <assert.h>
#include <criterion/criterion.h>
#include "my.h"

typedef struct list {
    struct list *next;
    struct list *prev;
    int nb;
} list_t;

static list_t *create_node(int nb)
{
    list_t *new = malloc(sizeof(list_t));

    new->next = NULL;
    new->prev = NULL;
    new->nb = nb;
    return new;
}

Test(my_listlen, null)
{
    assert(my_listlen(NULL) == 0);
}

Test(my_listlen, simple_1_node)
{
    list_t *list = create_node(1);

    assert(my_listlen(list) == 1);
}

Test(my_listlen, simple_2_node)
{
    list_t *list1 = create_node(1);
    list_t *list2 = create_node(2);

    list1 = my_push_back(list1, list2);
    assert(my_listlen(list1) == 2);
}

Test(my_listlen, simple_n_node)
{
    list_t *list = NULL;

    for (int i = 0; i < 100; i++)
        list = my_push_back(list, create_node(i));
    assert(my_listlen(list) == 100);
}
