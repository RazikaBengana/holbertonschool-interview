#include "search.h"

/**
 * linear_skip - program that searches for a value in a sorted skip list
 *
 * a skip list improves search speed by building levels above the original list,
 * with express lanes that skip several nodes, increasing traversal speed;
 * nodes in express lanes are placed at intervals equal to the square root
 * of the list size;
 * the list is sorted in ascending order
 *
 * @list: a pointer to the head of the skip list
 * @value: the value to find
 *
 * Return: a pointer to the node containing the value,
 *         or NULL if the value is not found or the list is empty
 */

skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *current = NULL, *stop = NULL;

	if (list == NULL)
		return (NULL);

	current = list;

	while (current && current->express && current->express->n < value)
	{
		printf("Value checked at index [%lu] = [%i]\n",
		       current->express->index, current->express->n);
		current = current->express;
	}
	stop = current;

	while (stop && stop->next != stop->express)
		stop = stop->next;

	if (current->express)
	{
		printf("Value checked at index [%lu] = [%i]\n",
		       current->express->index, current->express->n);
		printf("Value found between indexes [%lu] and [%lu]\n",
		       current->index, current->express->index);
	}
	else
	{
		printf("Value found between indexes [%lu] and [%lu]\n",
		       current->index, stop->index);
	}
	while (current != stop && current->n < value)
	{
		printf("Value checked at index [%lu] = [%i]\n",
		       current->index, current->n);
		current = current->next;
	}
	printf("Value checked at index [%lu] = [%i]\n",
	       current->index, current->n);

	if (current == stop)
		return (NULL);

	return (current);
}
