#ifndef BINARY_TREES_H
#define BINARY_TREES_H


#include <stdio.h>
#include <limits.h>


#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define ABS(x) ((x) > 0 ? (x) : (-(x)))



/**
 * struct binary_tree_s - Structure that represents a binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */

struct binary_tree_s
{
    int n;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
};


typedef struct binary_tree_s binary_tree_t;
typedef struct binary_tree_s avl_t;



/* function for testing */   /* binary_tree_print.c */
void binary_tree_print(const binary_tree_t *);


/* 0-binary_tree_is_avl.c */
int binary_tree_is_avl(const binary_tree_t *tree);
int checkAVL(const binary_tree_t *tree, int min, int max, int *height);



#endif /* BINARY_TREES_H */
