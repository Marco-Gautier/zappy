/*
** EPITECH PROJECT, 2018
** my_listlen
** File description:
** my_listlen
*/

#include "my.h"

size_t my_listlen(void *list)
{
	size_t i = 0;
	__list_t *__list = (__list_t *) list;

	if (list != NULL)
		for (; __list != NULL; __list = __list->next, i++);
	return (i);
}
