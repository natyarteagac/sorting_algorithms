#include "sort.h"

/**
 * insertion_sort_list - sorts a double linked list
 * @list: Double link list
 *
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current = *list;

	if (current == NULL)
		return;

	current = (*list)->next;
	while (current)
	{
		while (current->prev && current->prev->n > current->n)
		{
			current->prev->next = current->next;
			if (current->next)
				current->next->prev = current->prev;

			current->next = current->prev;
			current->prev = current->next->prev;
			current->next->prev = current;

			if (!current->prev)
				*list = current;
			else
				current->prev->next = current;
			print_list(*list);
		}
		current = current->next;
	}
}
