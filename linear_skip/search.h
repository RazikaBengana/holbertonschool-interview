#ifndef SEARCH_H
#define SEARCH_H


#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


/**
 * struct skiplist_s - Structure for a singly linked list node
 * with an express lane
 *
 * @n: Integer
 * @index: Index of the node in the list
 * @next: Pointer to the next node
 * @express: Pointer to the next node in the express lane
 */

typedef struct skiplist_s
{
	int n;
	size_t index;
	struct skiplist_s *next;
	struct skiplist_s *express;
} skiplist_t;



/* create_skiplist.c */
skiplist_t *create_skiplist(int *array, size_t size);

/* print_skiplist.c */
void print_skiplist(const skiplist_t *list);

/* free_skiplist.c */
void free_skiplist(skiplist_t *list);



/* 0-linear_skip.c */
skiplist_t *linear_skip(skiplist_t *head, int value);



#endif /* SEARCH_H */
