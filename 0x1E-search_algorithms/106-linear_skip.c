#include "search_algos.h"

/**
 * linear_skip - searches for a value in a skip list
 *
 * @list: input list
 * @value: value to search in
 * Return: index of the number
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *go;

	if (list == NULL)
		return (NULL);

	go = list;

	do {
		list = go;
		go = go->express;
		printf("Value checked at index ");
		printf("[%d] = [%d]\n", (int)go->index, go->n);
	} while (go->express && go->n < value);

	if (go->express == NULL)
	{
		list = go;
		while (go->next)
			go = go->next;
	}

	printf("Value found between indexes ");
	printf("[%d] and [%d]\n", (int)list->index, (int)go->index);

	while (list != go->next)
	{
		printf("Value checked at index [%d] = [%d]\n", (int)list->index, list->n);
		if (list->n == value)
			return (list);
		list = list->next;
	}

	return (NULL);
}
