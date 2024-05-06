#ifndef BINARY_TREES_H
#define BINARY_TREES_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>


/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */

typedef struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
} binary_tree_t;


typedef struct binary_tree_s heap_t;



/* function for testing */   /* binary_tree_print.c */
void binary_tree_print(const binary_tree_t *);


/* 0-heap_extract.c */
void heapify(binary_tree_t *current_node);
int count_nodes(heap_t *current_node);
binary_tree_t *get_last_node(heap_t *current_node);
int heap_extract(heap_t **root);



#endif /* BINARY_TREES_H */
