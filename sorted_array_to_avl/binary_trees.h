#ifndef BINARY_TREES_H
#define BINARY_TREES_H


#include <stddef.h>
#include <stdlib.h>


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


typedef struct binary_tree_s avl_t;



/* function for testing */   /* binary_tree_print.c */
void binary_tree_print(const binary_tree_t *);


/* 0-sorted_array_to_avl.c */
binary_tree_t *create_tree_node(binary_tree_t *parent, int value);
avl_t *sortedArrayToAVL(int *array, int start, int end, avl_t *parent);
avl_t *sorted_array_to_avl(int *array, size_t size);



#endif /* BINARY_TREES_H */
