/*
** EPITECH PROJECT, 2019
** tests_my_push_clear
** File description:
** tests_my_push_clear
*/

#include <assert.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdio.h>
#include <unistd.h>
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

Test(my_list_clear, empty_list)
{
    list_t *list = NULL;

    assert(my_listlen(list) == 0);
    assert(list == NULL);
    my_list_clear(&list, free);
    assert(my_listlen(list) == 0);
    assert(list == NULL);
}

Test(my_list_clear, list_1_node)
{
    list_t *list = create_node(1);

    assert(list != NULL);
    assert(my_listlen(list) == 1);
    my_list_clear(&list, free);
    assert(my_listlen(list) == 0);
    assert(list == NULL);
}

Test(my_list_clear, n_node)
{
    list_t *list = NULL;
    size_t i = 0;

    for (i = 0; i < 100; i++)
        list = my_push_back(list, create_node(i));
    assert(my_listlen(list) == 100);
    my_list_clear(&list, free);
    assert(my_listlen(list) == 0);
    assert(list == NULL);
}

static void custum_destructor(void *ptr)
{
    printf("mdr\n");
    fflush(stdout);
    free(ptr);
}

Test(my_list_clear, custum_destructor)
{
    cr_redirect_stdout();
    list_t *list = create_node(1);

    assert(list != NULL);
    assert(my_listlen(list) == 1);
    my_list_clear(&list, custum_destructor);
    assert(my_listlen(list) == 0);
    assert(list == NULL);
    cr_expect_stdout_eq_str("mdr\n");
}
