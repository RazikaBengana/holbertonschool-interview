#include "binary_trees.h"

/**
 * binary_tree_node - program that creates a new binary tree node
 * with a specified value
 *
 * @parent: a pointer to the parent node of the new node;
 *          it can be NULL if the new node is the root
 * @value: the integer value to store in the new node
 *
 * Return: a pointer to the newly created node,
 *         or NULL if memory allocation fails
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new = NULL;

	new = malloc(sizeof(binary_tree_t));

	if (!new)
		return (NULL);

	new->n = value;
	new->parent = parent;
	new->left = NULL;
	new->right = NULL;

	return (new);
}