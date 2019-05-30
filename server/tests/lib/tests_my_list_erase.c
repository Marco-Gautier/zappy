/*
** EPITECH PROJECT, 2019
** tests_my_push_erase
** File description:
** tests_my_push_erase
*/

#include <assert.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdio.h>
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

Test(my_list_erase, no_list)
{
    assert(my_list_erase(NULL, NULL + 1, free) == NULL);
}

Test(my_list_erase, no_to_remove_node)
{
    list_t *list = create_node(1);

    list = my_push_back(list, create_node(2));
    assert(list != NULL);
    assert(my_listlen(list) == 2);
    assert(my_list_erase(list, NULL, free) == list);
    assert(my_listlen(list) == 2);
}

Test(my_list_erase, 1_node_from_list_1_node)
{
    list_t *list = create_node(1);

    assert(list != NULL);
    assert(my_list_erase(list, list, free) == NULL);
}

Test(my_list_erase, list_2_node_erase_tail)
{
    list_t *list = create_node(1);
    list_t *last = create_node(2);
    list_t *tmp;

    list = my_push_back(list, last);
    assert(list != NULL);
    assert(my_listlen(list) == 2);
    tmp = my_list_erase(list, last, free);
    assert(tmp == list);
    assert(list->next == NULL);
    assert(my_listlen(list) == 1);
}

Test(my_list_erase, list_2_node_erase_head)
{
    list_t *head = create_node(1);
    list_t *node = create_node(2);
    list_t *tmp;

    head = my_push_back(head, node);
    assert(head != NULL);
    assert(my_listlen(head) == 2);
    tmp = my_list_erase(head, head, free);
    assert(tmp == node);
    assert(node->next == NULL);
    assert(node->prev == NULL);
    assert(my_listlen(node) == 1);
}

Test(my_list_erase, n_node)
{
    list_t *list = NULL;
    size_t i = 0;

    for (i = 0; i < 100; i++)
        list = my_push_back(list, create_node(i));
    assert(my_listlen(list) == i);
    for (list_t *it = list; it != NULL; it = it->next) {
        list = my_list_erase(list, it, free);
        i--;
        assert(my_listlen(list) == i);
        it = list;
    }
    assert(my_listlen(list) == 1);
    list = my_list_erase(list, list, free);
    assert(my_listlen(list) == 0);
}

Test(my_list_erase, no_destructor_so_detach_from_list_but_pointer_toujours_la)
{
    list_t *list = create_node(1);
    list_t *node = create_node(2);

    list = my_push_back(list, node);
    cr_assert(list != NULL);
    assert(my_listlen(list) == 2);
    cr_assert(my_list_erase(list, node, NULL) == list);
    assert(my_listlen(list) == 1);
    cr_assert(node != NULL);
    cr_assert(node->nb == 2);
    cr_assert(node->next == NULL);
    cr_assert(node->prev == list);
}

static void custum_destructor(void *ptr)
{
    printf("mdr\n");
    fflush(stdout);
    free(ptr);
}

Test(my_list_erase, custum_destructor)
{
    cr_redirect_stdout();
    list_t *list = create_node(1);

    cr_assert(list != NULL);
    cr_assert(my_list_erase(list, list, custum_destructor) == NULL);
    cr_expect_stdout_eq_str("mdr\n");
}
