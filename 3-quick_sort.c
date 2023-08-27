#include "sort.h"

/**
 * partition - divides array in subs
 * @array: input array
 * @start: start point
 * @end: end point
 * @size: array size
 * Return: index
 */

int partition(int *array, size_t size, int start, int end)
{
	int pivot = array[end], temp;
	int pivIdx = start, idx = start;

	for (idx = start; idx < end; idx++)
	{
		if (array[idx] <= pivot)
		{
			temp = array[idx];
			array[idx] = array[pivIdx];
			array[pivIdx] = temp;
			if (pivIdx != idx)
			{
				print_array(array, size);
			}
			pivIdx += 1;
		}
	}
	temp = array[pivIdx];
	array[pivIdx] = pivot;
	array[end] = temp;
	if (pivIdx != end)
		print_array(array, size);
	return (pivIdx);
}

/**
 * sort_helper - helper function
 * @array: input array
 * @start: start index
 * @end: end index
 * @size: array size
 * Return: none
 */

void sort_helper(int *array, size_t size, int start, int end)
{
	int pivIdx;

	if (start < end)
	{
		pivIdx = partition(array, size, start, end);
		sort_helper(array, size, start, pivIdx - 1);
		sort_helper(array, size, pivIdx + 1, end);
	}
}

/**
 * quick_sort - sorts an array using quick sort
 * @array: input array
 * @size: array size
 * Return: none
 */

void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	sort_helper(array, size, 0, size - 1);
}
