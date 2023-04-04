#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * insert_node - function that inserts a number into a sorted singly linked list.
 * @head: pointer to pointer of first node of listint_t list
 * @number: integer to be included in new node
 * Return: the address of the new node, or NULL if it failed.
 */

listint_t *insert_node(listint_t **head, int number) 
{
    listint_t *new;
    listint_t *current, *aux;

    current = *head;
    aux = *head;

    new = malloc(sizeof(listint_t));
    if (new == NULL)
        return (NULL);

    new->n = number;
    new->next = NULL;

    if (*head == NULL || number < current->n)
    {
        new->next = current;
        *head = new;
    }
    else
    {
        while (aux->next != NULL && aux->next->n < number)
           aux = aux->next;
        if (aux->next != NULL)
           new->next = aux->next;
        aux->next = new;
    }
    return (new);
}