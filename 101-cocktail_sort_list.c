#include "sort.h"
/**
 * swap - swaps two nodes
 * @list: pointer to list head
 * @first: first node
 * @second: second node
 * Return: 1
 */

int swap(listint_t **list, listint_t *first, listint_t *second)
{
	first->next = second->next;
	second->prev = first->prev;

	if (second->next)
		second->next->prev = first;

	second->next = first;
	if (first->prev)
		first->prev->next = second;
	else
		*list = second;
	first->prev = second;
	return (1);
}

/**
 * cocktail_sort_list - sorts linked list using the cocktail sort
 * algorithm
 * @list: linked list to sort
 */

void cocktail_sort_list(listint_t **list)
{
	listint_t *first, *next;
	int swapped = 1;

	if (!list || !*list || !(*list)->next)
		return;

	while (swapped)
	{
		first = *list;
		next = (*list)->next;
		swapped = 0;
		while (next && first)
		{
			if (first->n > next->n)
			{
				swapped = swap(list, first, next);
				print_list(*list);
			}
			else
			first = next;
			next = first->next;
		}
		if (!swapped)
			break;
		next = first;
		first = first->prev;
		swapped = 0;
		while (first != NULL)
		{
			if (first->n > next->n)
			{
				swapped = swap(list, first, next);
				print_list(*list);
			}
			next = first;
			first = next->prev;
		}
		if (!swapped)
			break;
	}
}
