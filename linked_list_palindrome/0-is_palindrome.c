#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * reversed - reversed a palindrome
 * @head: pointer to list to be freed
 * Return: linked list reversed
 */
void reversed(listint_t **head)
{
    listint_t *prev = NULL;
    listint_t *current = *head;
    listint_t *next = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head = prev;
}

/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: double pointer to head of list
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
 */
int is_palindrome(listint_t **head)
{
    listint_t *copy = *head;
	listint_t *half = *head;
	listint_t *ini = *head;
    int n = 0;
    int half_n = 0;


    if (*head == NULL)
	{
		return (1);
	}

    while (copy)
	{
		n += 1;
		copy = copy->next;
	}
	while (half_n != (n / 2))
	{
		half_n += 1;
		half = half->next;
	}
	reversed(&half);
	while (ini && half)
	{
		if (ini->n != half->n)
		{
			return (0);
		}
		ini = ini->next;
		half = half->next;
	}
	return (1);
}
