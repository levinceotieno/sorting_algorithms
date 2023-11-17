#include "sort.h"

/**
 * merge - sorts and merges two subarrays
 * @array: array
 * @lb: lower bound
 * @ub: upper bound
 * @mid: middle bound
 */

void merge(int *array, int lb, int mid, int ub)
{
	int *temp, i = lb, j = mid + 1, k = 0, size;

	temp = malloc(sizeof(int) * (ub - lb + 1));
	size = ub - lb + 1;
	if (!temp)
		return;

	puts("Merging...");
	printf("[left]: ");
	print_array(array + lb, mid - lb + 1);
	printf("[right]: ");
	print_array(array + mid + 1, ub - (mid + 1) + 1);
	while (i <= mid && j <= ub)
	{
		if (array[i] < array[j])
			temp[k++] = array[i++];
		else
			temp[k++] = array[j++];
	}

	while (i <= mid)
		temp[k++] = array[i++];
	while (j <= ub)
		temp[k++] = array[j++];
	for (k = 0, i = lb; i <= ub; i++, k++)
		array[i] = temp[k];
	printf("[Done]: ");
	print_array(temp, size);
	free(temp);
}

/**
 * split - splits array into sub array
 * @array: array of integers
 * @lb: lowe bound
 * @ub: uppper bound
 */

void split(int *array, int lb, int ub)
{
	int mid;

	if (lb < ub)
	{
		mid = (lb + ub) / 2;
		if ((lb + ub) % 2 == 0)
		{
			split(array, lb, mid - 1);
			split(array, mid, ub);
			merge(array, lb, mid - 1, ub);
		}
		else
		{
			split(array, lb, mid);
			split(array, mid + 1, ub);
			merge(array, lb, mid, ub);
		}
	}
}


/**
 * merge_sort -  sorts an array fo integers using divide and conquer
 * method.
 * @array: array of integers
 * @size: size of @array
 */

void merge_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	split(array, 0, (int)size - 1);
}
