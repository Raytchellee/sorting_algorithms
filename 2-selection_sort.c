#include "sort.h"

/**
 * selection_sort - sorts array using selection sort
 * @array: input array
 * @size: array length
 * Return: none
 */

void selection_sort(int *array, size_t size)
{
	size_t idx = 0, idy = 0, min;
	int temp;

	if (size < 2 || !array)
	{
		return;
	}
	for (idx = 0; idx < size - 1; idx++)
	{
		min = idx;
		for (idy = idx + 1; idy < size; idy++)
		{
			if (array[idy] < array[min])
			{
				min = idy;
			}
		}
		if (min != idx)
		{
			temp = array[idx];
			array[idx] = array[min];
			array[min] = temp;
			print_array(array, size);
		}
	}
}
