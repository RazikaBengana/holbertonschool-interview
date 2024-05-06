#include <stdio.h>
#include <stdlib.h>
#include "search.h"

/**
 * print_skiplist - Prints the contents of a skiplist
 *
 * This function iterates through the skiplist twice:
 * - once through the normal linked list path
 * - and once through the express lane;
 *
 * Each node's index and value are printed during each
 * traversal
 *
 * @list: Pointer to the head of the list
 *
 * Return: nothing (void)
 */

void print_skiplist(const skiplist_t *list)
{
	const skiplist_t *node;

	printf("List :\n");

	for (node = list; node; node = node->next)
	{
		printf("Index[%lu] = [%d]\n", node->index, node->n);
	}
	printf("\nExpress lane :\n");

	for (node = list; node; node = node->express)
	{
		printf("Index[%lu] = [%d]\n", node->index, node->n);
	}
	printf("\n");
}