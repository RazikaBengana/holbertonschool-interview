#include "list.h"

/**
 * add_node_end - program that adds a new node at the end
 * of a doubly linked list
 *
 * @list: a pointer to the pointer of the first node of the list
 * @str: the string content to store in the new node
 *
 * Return: a pointer to the newly added node,
 *         or NULL if the node cannot be created
 */

List *add_node_end(List **list, char *str)
{
	List *new_node = malloc(sizeof(List));

	if (new_node == NULL)
		return (NULL);

	new_node->str = strdup(str);

	if (new_node->str == NULL)
	{
		free(new_node);
		return (NULL);
	}

	if (*list == NULL)
	{
		new_node->prev = new_node;
		new_node->next = new_node;
		*list = new_node;
	}
	else
	{
		new_node->prev = (*list)->prev;
		new_node->next = *list;
		(*list)->prev->next = new_node;
		(*list)->prev = new_node;
	}

	return (new_node);
}



/**
 * add_node_begin - program that adds a new node at the beginning
 * of a doubly linked list
 *
 * @list: a pointer to the pointer of the first node of the list
 * @str: the string content to store in the new node
 *
 * Return: a pointer to the newly added node,
 *         or NULL if the node cannot be created
 */

List *add_node_begin(List **list, char *str)
{
	List *new_node = malloc(sizeof(List));

	if (new_node == NULL)
		return (NULL);

	new_node->str = strdup(str);

	if (new_node->str == NULL)
	{
		free(new_node);
		return (NULL);
	}

	if (*list == NULL)
	{
		new_node->prev = new_node;
		new_node->next = new_node;
		*list = new_node;
	}
	else
	{
		new_node->prev = (*list)->prev;
		new_node->next = *list;
		(*list)->prev->next = new_node;
		(*list)->prev = new_node;
		*list = new_node;
	}

	return (new_node);
}
