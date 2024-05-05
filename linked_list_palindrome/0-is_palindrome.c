#include "lists.h"

/**
 * is_palindrome - program that checks if a singly linked list is a palindrome
 *
 * @head: a pointer to the head of the list
 *
 * Return: 1 if the list is a palindrome, 0 otherwise
 */

int is_palindrome(listint_t **head)
{
	listint_t *current = *head;
	int is_palindrome_result;

	/* A single node or empty list is always a palindrome */
	if (!current || !(current->next))
		return (1);

	is_palindrome_result = check_palindrome_recursively(head, current);
	head = &current;

	return (is_palindrome_result);
}



/**
 * check_palindrome_recursively - helper function to determine if the sublist
 * is a palindrome using recursion
 *
 * @head: a pointer to the head pointer of the list
 *        for tracking the left part in comparison
 * @right: the current node at the right part of the list for comparison
 *
 * Return: 1 if the current sublist is a palindrome, 0 otherwise
 */

int check_palindrome_recursively(listint_t **head, listint_t *right)
{
	int is_sublist_palindrome, are_values_equal;

	if (!right)
		return (1);

	is_sublist_palindrome = check_palindrome_recursively(head, right->next);

	if (is_sublist_palindrome == 0)
		return (is_sublist_palindrome);

	are_values_equal = ((*head)->n == right->n) ? 1 : 0;

	*head = (*head)->next;

	return (are_values_equal);
}
