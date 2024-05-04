#include "lists.h"

/**
 * insert_node - program that inserts a new node with a specified number
 * into a sorted singly linked list
 *
 * @head: a double pointer to the head of the list
 * @number: the integer value to be inserted into the list
 *
 * Return: a pointer to the newly inserted node,
 *         or NULL if the node cannot be created due to memory constraints
 */

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new_node, *current;

	new_node = malloc(sizeof(listint_t));

	if (new_node == NULL)
	{
		return (NULL);
	}
	new_node->n = number;
	new_node->next = NULL;

	if (*head == NULL)
	{
		*head = new_node;
		return (new_node);
	}

	if (number < (*head)->n)
	{
		new_node->next = *head;
		*head = new_node;
		return (new_node);
	}

	current = *head;

	while (current->next != NULL && current->next->n <= number)
	{
		current = current->next;
	}
	new_node->next = current->next;
	current->next = new_node;

	return (new_node);
}
