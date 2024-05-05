#include "binary_trees.h"

/**
 * create_tree_node - program that creates a binary tree node
 *
 * @parent: a pointer to the parent node
 * @value: the integer stored in the new node
 *
 * Return: a pointer to the new node of the AVL tree,
 *         or NULL on failure
 */

binary_tree_t *create_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	new_node = malloc(sizeof(binary_tree_t));

	if (!new_node)
		return (NULL);

	new_node->n = value;
	new_node->parent = parent;
	new_node->left = NULL;
	new_node->right = NULL;

	return (new_node);
}



/**
 * sortedArrayToAVL - Recursive helper function to build an AVL tree
 * from a sorted array of integers
 *
 * @array: the sorted array of integers
 * @start: the starting index of the current subarray
 * @end: the ending index of the current subarray
 * @parent: a pointer to the parent node from the previous recursion frame
 *
 * Return: a pointer to the root node of the new subtree, or NULL on failure
 */

avl_t *sortedArrayToAVL(int *array, int start, int end, avl_t *parent)
{
	avl_t *root = NULL;
	int mid;

	if (!array)
		return (NULL);

	if (start > end)
		return (NULL);

	mid = (start + end) / 2;
	root = create_tree_node(parent, array[mid]);

	if (!root)
		return (NULL);

	root->left = sortedArrayToAVL(array, start, mid - 1, root);
	root->right = sortedArrayToAVL(array, mid + 1, end, root);

	return (root);
}



/**
 * sorted_array_to_avl - program that builds an AVL tree
 * from a sorted array of integers
 *
 * @array: the sorted array of integers
 * @size: the number of elements in the array
 *
 * Return: a pointer to the root node of the new AVL tree,
 *         or NULL on failure
 */

avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (array == NULL || size == 0)
		return (NULL);

	return (sortedArrayToAVL(array, 0, (int)(size - 1), NULL));
}
