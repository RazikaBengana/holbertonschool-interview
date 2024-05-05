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


typedef struct binary_tree_s heap_t;



/* function for testing */
void binary_tree_print(const binary_tree_t *);


/* task 0 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);

/* task 1 */
size_t max_size_t(size_t a, size_t b);
size_t binary_tree_height(const binary_tree_t *tree);
size_t binary_tree_nodes(const binary_tree_t *tree);
int binary_tree_is_perfect(const binary_tree_t *tree);
heap_t *binary_tree_complete_insert(heap_t *tree, int value);
heap_t *heap_insert(heap_t **root, int value);



#endif /* BINARY_TREES_H */
