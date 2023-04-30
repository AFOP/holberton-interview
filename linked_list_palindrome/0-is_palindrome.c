#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * reversed - reversed a palindrome
 * @head: pointer to list to be freed
 * Return: linked list reversed
 */
int count(listint_t **head)
{
    listint_t *current = *head;
    int n = 1;

    while (current->next != NULL)
    {
        n++;
        current = current->next;
    }
    return n;
}

/**
 * reversed - reversed a palindrome
 * @head: pointer to list to be freed
 * Return: linked list reversed
 */
listint_t *reversed(listint_t **head)
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

    return prev;
}

/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: double pointer to head of list
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
 */
int is_palindrome(listint_t **head)
{
    listint_t *rev;
    listint_t *current;
    int i = 0;

    rev = reversed(head);
    current = reversed(&rev);
    i = count(&rev);

    if (i % 2 == 0)
    {
        while (current != NULL && rev != NULL)
        {
            if (current->n != rev->n)
            {
                return (0);
            }
            current = current->next;
            rev = rev->next;
        }
        return (1);
    }
    return (0);
}
