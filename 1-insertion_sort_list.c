#include "sort.h"

/**
* swap_list - swaps two nodes
* @a: first node
* @b: second node
* @h: pointer to head
* Return: none
*/

void swap_list(listint_t *a, listint_t *b, listint_t **h)
{
	listint_t *temp_b = a->next, *temp_a = b->prev;

	if (temp_b != NULL)
		temp_b->prev = b;
	if (temp_a != NULL)
		temp_a->next = a;
	a->prev = temp_a;
	b->next = temp_b;
	a->next = b;
	b->prev = a;
	if (*h == b)
	{
		*h = a;
	}
	print_list(*h);
}

/**
 * insertion_sort_list - sorts a list using insertion sort
 * @list: input list
 * Return: None
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *post = NULL,	*pre = NULL;

	if (*list == NULL || list == NULL || (*list)->next == NULL)
		return;

	post = (*list)->next;
	pre = post->prev;

	while (post != NULL)
	{
		pre = post->prev;
		while (pre != NULL && pre->n > post->n)
		{
			swap_list(post, pre, list);
			pre = post->prev;
		}
		post = post->next;
	}
}
