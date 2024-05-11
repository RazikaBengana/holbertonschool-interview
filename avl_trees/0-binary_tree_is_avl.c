#include "binary_trees.h"

/**
 * binary_tree_is_avl - program that checks if a binary tree is an AVL tree
 * (a self-balancing binary search tree)
 *
 * @tree: a pointer to the root node of the binary tree
 *
 * Return: 1 if tree is an AVL tree, 0 otherwise
 */

int binary_tree_is_avl(const binary_tree_t *tree)
{
	int height;

	if (!tree)
		return (0); /* Empty tree is considered AVL */

	return (checkAVL(tree, INT_MIN, INT_MAX, &height));
}



/**
 * checkAVL - helper function to determine if a binary tree is AVL
 * by checking node values and heights
 *
 * @tree: a pointer to the current node of the binary tree
 * @min: the minimum valid value for the current node to maintain BST property
 * @max: the maximum valid value for the current node to maintain BST property
 * @height: a pointer to store the height of the current subtree
 *
 * Return: 1 if subtree is AVL, 0 otherwise
 */

int checkAVL(const binary_tree_t *tree, int min, int max, int *height)
{
	int leftHeight = 0, rightHeight = 0;

	if (!tree)
		return (1);

	if (tree->n <= min || tree->n >= max)
		return (0);

	if (!checkAVL(tree->left, min, tree->n, &leftHeight) ||
	    !checkAVL(tree->right, tree->n, max, &rightHeight))
		return (0);

	*height = MAX(leftHeight, rightHeight) + 1;

	return (ABS(leftHeight - rightHeight) <= 1);
}
