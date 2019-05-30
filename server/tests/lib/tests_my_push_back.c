/*
** EPITECH PROJECT, 2019
** tests_my_push_back
** File description:
** tests_my_push_back
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

    if (!new)
        return NULL;
    new->next = NULL;
    new->prev = NULL;
    new->nb = nb;
    return new;
}

Test(my_push_back, no_new_node)
{
    list_t *list = create_node(1);
    list_t *tmp;

    tmp = my_push_back(list, NULL);
    assert(list == tmp);
    assert(list->prev == NULL);
    assert(list->next == NULL);
    assert(list->nb == 1);
}

Test(my_push_back, simple_1_node)
{
    list_t *list = create_node(1);

    list = my_push_back(NULL, list);
    assert(list != NULL);
    assert(list->prev == NULL);
    assert(list->next == NULL);
    assert(list->nb == 1);
}

Test(my_push_back, simple_2_node)
{
    list_t *list1 = create_node(1);
    list_t *list2 = create_node(2);

    list1 = my_push_back(list1, list2);
    assert(list1 != NULL);
    assert(list1->prev == NULL);
    assert(list1->next != NULL);
    assert(list1->next == list2);
    assert(list1->nb == 1);
    assert(list2 != NULL);
    assert(list2->prev == list1);
    assert(list2->next == NULL);
    assert(list2->nb == 2);
}

Test(my_push_back, simple_n_node)
{
    list_t *list = NULL;
    list_t *head;
    int i = 0;

    for (i = 0; i < 100; i++)
        list = my_push_back(list, create_node(i));
    i = 0;
    head = list;
    for (list_t *it = list; it != NULL; it = it->next) {
        assert(it->nb == i);
        i++;
    }
    while (list != NULL && list->next != NULL)
        list = list->next;
    i = 100 - 1;
    while (list != NULL && list->prev != NULL) {
        assert(list->nb == i);
        i--;
        list = list->prev;
    }
    assert(list == head);
}
