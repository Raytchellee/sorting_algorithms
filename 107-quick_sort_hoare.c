#include "sort.h"

/**
* partition - split using Hoare version
* @array: input array
* @left: start point
* @right: end point
* @size: array length
* Return: split index
*/

size_t partition(int *array, size_t size, ssize_t left, ssize_t right)
{
	int temp, pivot;

	pivot = array[right];
	while (left <= right)
	{
		while (array[left] < pivot)
			left++;
		while (array[right] > pivot)
			right--;
		if (left <= right)
		{
			if (left != right)
			{
				temp = array[left];
				array[left] = array[right];
				array[right] = temp;
				print_array(array, size);
			}
			left++;
			right--;
		}
	}
	return (right);
}

/**
* sort_helper - recursively partitions and sorts array
* @array: input array
* @left: start point
* @right: end point
* @size: length of array
* Return: none
*/

void sort_helper(int *array, size_t size, ssize_t left, ssize_t right)
{
	ssize_t pivot;

	if (left < right)
	{
		pivot = partition(array, size, left, right);
		sort_helper(array, size, left, pivot);
		sort_helper(array, size, pivot + 1, right);

	}
}

/**
* quick_sort_hoare - uses hoare partition to sort array
* @array: Input array
* @size: length of array
* Return: none
*/

void quick_sort_hoare(int *array, size_t size)
{
	if (size < 2 || array == NULL)
		return;
	sort_helper(array, size, 0, size - 1);
}
