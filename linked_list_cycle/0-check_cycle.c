#include "lists.h"

/**
 * check_cycle - program that checks if a singly linked list has a cycle in it
 * using the two-pointer technique
 *
 * Two pointers, slow and fast, are used where slow moves one step at a time,
 * and fast moves two steps at a time;
 * if there is a cycle, the fast pointer will eventually meet the slow pointer,
 * indicating a cycle in the list
 *
 * @list: a pointer to the head of the linked list
 *
 * Return: 0 if there is no cycle, 1 if there is a cycle
 */

int check_cycle(listint_t *list)
{
	listint_t *slow, *fast;

	slow = list;
	fast = list;

	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast)
		{
			return (1);
		}
	}
	return (0);
}
