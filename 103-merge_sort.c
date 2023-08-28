#include "sort.h"

/**
* mergeSorted - combine and sorts the array
* @left: start point
* @mid: mid point
* @right: stop point
* @res: merged data
* @input: input array
* Return: none
*/

void mergeSorted(size_t left, size_t mid, size_t right, int *res, int *input)
{
	size_t idx, idy, idz;

	printf("Merging...\n[left]: ");
	print_array(input + left, mid - left);
	printf("[right]: ");
	print_array(input + mid, right - mid);
	idx = left;
	idy = mid;

	for (idz = left; idz < right; idz++)
	{
		if (idx < mid && (idy >= right || input[idx] <= input[idy]))
		{
			res[idz] = input[idx];
			idx++;
		}
		else
		{
			res[idz] = input[idy];
			idy++;
		}
	}
	printf("[Done]: ");
	print_array(res + left, right - left);
}

/**
* merge_sort_split - splits array down to one
* @left: start point
* @right: end point
* @array: input array
* @copy: a copy of the array
* Return: none
*/

void merge_sort_split(size_t left, size_t right, int *array, int *copy)
{
	size_t mid;

	if (right - left <= 1)
		return;
	mid = (left + right) / 2;
	merge_sort_split(left, mid, array, copy);
	merge_sort_split(mid, right, array, copy);
	mergeSorted(left, mid, right, array, copy);
	for (mid = left; mid < right; mid++)
		copy[mid] = array[mid];
}

/**
* merge_sort - sorts an array using merge sort
* @array: input array
* @size: array size
* Return: none
*/

void merge_sort(int *array, size_t size)
{
	int *copy;
	size_t idx = 0;

	if (size <= 1 || array == NULL)
	{
		return;
	}

	copy = malloc(sizeof(int) * size);
	if (copy == NULL)
		return;
	while (idx < size)
	{
		copy[idx] = array[idx];
		idx++;

	}
	merge_sort_split(0, size, array, copy);
	free(copy);
}
