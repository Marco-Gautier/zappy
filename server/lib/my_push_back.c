/*
** EPITECH PROJECT, 2018
** my_push_back
** File description:
** my_push_back
*/

#include "my.h"

void *my_push_back(void *l1, void *l2)
{
	__list_t *tmp = (__list_t *) l1;
	__list_t *list = (__list_t *) l1;
	__list_t *new = (__list_t *) l2;

	if (!list)
		return (l2);
	for (; list != NULL && list->next != NULL; list = list->next);
	list->next = new;
	if (new != NULL)
		new->prev = list;
	return (tmp);
}
