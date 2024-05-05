#ifndef LISTS_H
#define LISTS_H


#include <stddef.h>



/**
 * struct listint_s - Structure that defines a node
 * in a singly linked list
 *
 * @n: integer value held by this node
 * @next: pointer to the next node in the list
 */

typedef struct listint_s
{
    int n;
    struct listint_s *next;
} listint_t;



/* functions for testing */   /* linked_lists.c */
size_t print_listint(const listint_t *h);
listint_t *add_nodeint_end(listint_t **head, const int n);
void free_listint(listint_t *head);


/* 0-is_palindrome.c */
int check_palindrome_recursively(listint_t **head, listint_t *right);
int is_palindrome(listint_t **head);


#endif /* LISTS_H */