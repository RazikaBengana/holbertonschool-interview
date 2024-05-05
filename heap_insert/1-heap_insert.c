#include "binary_trees.h"

/**
 * max_size_t - program that finds the larger of two size_t values
 *
 * @a: the first value to compare
 * @b: the second value to compare
 *
 * Return: the larger of the two size_t values,
 *         or the value of both if they are equal
 */

size_t max_size_t(size_t a, size_t b)
{
	return ((a > b) ? a : b);
}



/**
 * binary_tree_height - program that measures the height of a binary tree
 *
 * @tree: a pointer to the root node of the tree to measure from
 *
 * Return: the height of the tree from the root node, or 0 if tree is NULL
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (1 + max_size_t(binary_tree_height(tree->left),
			       binary_tree_height(tree->right)));
}



/**
 * binary_tree_nodes - program that counts the total number of nodes
 * in a binary tree
 *
 * @tree: a pointer to the root node of the tree to measure from
 *
 * Return: the total number of non-leaf nodes in the tree starting
 *         at 'tree', or 0 if tree is NULL
 */

size_t binary_tree_nodes(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (1 + binary_tree_nodes(tree->left) +
		binary_tree_nodes(tree->right));
}



/**
 * binary_tree_is_perfect - program that checks if a binary tree is perfect
 *
 * a perfect binary tree has all interior nodes with two children
 * and all leaves at the same level
 *
 * @tree: a pointer to the root node to check below
 *
 * Return: 1 if the tree is perfect, 0 otherwise or if tree is NULL
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int height, i, pow2 = 1;
	size_t total_nodes;

	if (!tree)
		return (0);

	height = binary_tree_height(tree);
	total_nodes = binary_tree_nodes(tree);

	for (i = 0; i < height; i++)
		pow2 *= 2;

	return (pow2 - 1 == (int)total_nodes);
}



/**
 * binary_tree_complete_insert - program that inserts a new node
 * in a binary tree while maintaining the tree's completeness
 *
 * @tree: a pointer to the root node of the tree to insert into
 * @value: the value to store in the new node
 *
 * Return: a pointer to the newly inserted node, or NULL on failure
 */

heap_t *binary_tree_complete_insert(heap_t *tree, int value)
{
	heap_t *new = NULL;

	if (tree->left && tree->right)
	{
		if (!binary_tree_is_perfect(tree) &&
		    binary_tree_is_perfect(tree->left))
			new = binary_tree_complete_insert(tree->right, value);
		else
			new = binary_tree_complete_insert(tree->left, value);
	}
	else
	{
		new = binary_tree_node(tree, value);

		if (!new)
			return (NULL);

		if (!(tree->left))
			tree->left = new;
		else
			tree->right = new;
	}
	return (new);
}



/**
 * heap_insert - program that inserts a value into a max binary heap
 *
 * @root: a double pointer to the root node of the heap
 * @value: the value to store in the new node
 *
 * Return: a pointer to the inserted node, or NULL if insertion fails
 */

heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new = NULL, *temp = NULL;
	int swap;

	if (!(*root))
	{
		new = binary_tree_node(NULL, value);

		if (!new)
			return (NULL);

		*root = new;

		return (new);
	}

	new = binary_tree_complete_insert(*root, value);

	if (!new)
		return (NULL);

	temp = new;

	while (temp && temp->parent && temp->n > temp->parent->n)
	{
		swap = temp->n;
		temp->n = temp->parent->n;
		temp->parent->n = swap;
		temp = temp->parent;
	}
	return (temp);
}
