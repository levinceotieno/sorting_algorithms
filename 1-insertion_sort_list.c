#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list,
 * of integers in ascending order
 * @list: pointer to the head of the list
 */

void insertion_sort_list(listint_t **list)
{
listint_t *current;
listint_t *prev;

if (!list || !*list || !(*list)->next)
return;

current = (*list)->next;

do
{
prev = current->prev;
/*current = current;*/

do
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
} while (prev && prev->n > current->n)

current = current->next;
} while (current)
}

