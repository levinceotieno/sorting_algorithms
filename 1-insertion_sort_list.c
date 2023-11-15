#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers in ascending
 * order
 * @list: pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current;
	listint_t *prev;

	if (!list || !*list || !(*list)->next)
		return;

	current = (*list)->next;

	while (current)
	{
		prev = current->prev;
		/*current = current;*/

		while (prev && prev->n > current->n)
		{
			if (current->next)
				current->next->prev = prev;
			prev->next = current->next;
			current->prev = prev->prev;
			if (prev->prev)
				prev->prev->next = current;
			else
				*list = current;
			prev->prev = current;
			current->next = prev;
			prev = current->prev;
			print_list(*list);
		}

		current = current->next;
	}
}
