#include "sort.h"


/**
 * shell_sort - sorts an array of integers using the knuth
 * gapping sequence
 * @array: array of integers to sort
 * @size: size of @array
 */

void shell_sort(int *array, size_t size)
{
	size_t gap = 1;
	size_t j, k;
	int temp;

	if (!array || size < 2)
		return;

	while (gap <= size)
		gap = gap * 3 + 1;

	for (gap = (gap - 1) / 3; gap >= 1; gap = (gap - 1) / 3)
	{
		for (j = gap; j < size; j++)
		{
			k = j;
			while (k >= gap && array[k] < array[k - gap])
			{
				temp = array[k];
				array[k] = array[k - gap];
				array[k - gap] = temp;
				k -= gap;
			}
		}
		print_array(array, size);
	}
}
