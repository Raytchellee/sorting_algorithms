#include "sort.h"

/**
 * bubble_sort - sorts an array using bubble sort
 * @array: input array
 * @size: lendgth of array
 * Return: None
 */

void bubble_sort(int *array, size_t size)
{
	size_t idx = 0, idy = 0;
	int isSorted = 0, temp;

	if (size < 2 || !array)
	{
		return;
	}
	for (idx = 0; idx < size - 1; idx++)
	{
		if (isSorted)
			return;
		isSorted = 1;
		for (idy = 0; idy < size - 1 - idx; idy++)
		{
			if (array[idy] > array[idy + 1])
			{
				isSorted = 0;
				temp = array[idy];
				array[idy] = array[idy + 1];
				array[idy + 1] = temp;
				print_array(array, size);
			}
		}
	}
}
