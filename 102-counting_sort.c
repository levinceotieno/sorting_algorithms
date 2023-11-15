#include "sort.h"

/**
 * set_count_array - sets count array
 * @count_array: takes counts
 * @max: max index of @count_array
 */

void set_count_array(int *count_array, int max)
{
	int i;

	/* Updates and print count_array */
	for (i = 0; (int)i <= max; i++)
	{
		count_array[i] = count_array[i] + count_array[i - 1];
	}
}

/**
 * counting_sort - sorts array of positive integers
 * @array: array to sort
 * @size: size of @array
 */

void counting_sort(int *array, size_t size)
{
	size_t i, j;
	int *count_array, *sorted_array, max = array[0], k;

	if (!array || size < 2)
		return;

	for (i = 0; i < size; i++)
		if (array[i] > max)
			max = array[i];

	count_array = malloc(sizeof(int) * (max + 1));
	if (!count_array)
		return;
	/* sets array to zeros */
	memset(count_array, 0, max + 1);
	sorted_array = malloc(sizeof(int) * size);
	if (!sorted_array)
	{
		free(count_array);
		return;
	}
	for (i = 0; i < size; i++)
		count_array[array[i]]++;

	set_count_array(count_array, max);
	print_array(count_array, max + 1);

	for (j = size - 1; (int)j >= 0; j--)
	{
        if (k >= 0)
		    k = count_array[array[j]] - 1;
		sorted_array[k] = array[j];
	}
	for (i = size - 1; (int)i >= 0; i--)
		array[i] = sorted_array[i];
	free(count_array);
	free(sorted_array);
}
