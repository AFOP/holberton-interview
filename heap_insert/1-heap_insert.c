#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary_trees.h"

/**
 * heap_insert - Insert a value into a Max Binary Heap
 * @root: Double pointer to the root node of the Heap
 * @value: The value to store in the node to be inserted
 *
 * Return: Pointer to the inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
    heap_t *new_node, *current_node;
    int temp;

    if (root == NULL)
        return (NULL);

    new_node = binary_tree_node(NULL, value);
    if (new_node == NULL)
        return (NULL);

    if (*root == NULL)
    {
        *root = new_node;
        return (new_node);
    }

    current_node = *root;
    while (current_node != NULL)
    {
        if (current_node->n < new_node->n)
        {
            temp = current_node->n;
            current_node->n = new_node->n;
            new_node->n = temp;
            if (current_node->left != NULL)
                current_node = current_node->left;
            else
            {
                current_node->left = new_node;
                new_node->parent = current_node;
                break;
            }
        }
        else if (current_node->n > new_node->n)
        {
            if (current_node->right != NULL)
                current_node = current_node->right;
            else
            {
                current_node->right = new_node;
                new_node->parent = current_node;
                break;
            }
        }
        else
            break;
    }

    while (new_node->parent != NULL && new_node->parent->n < new_node->n)
    {
        temp = new_node->parent->n;
        new_node->parent->n = new_node->n;
        new_node->n = temp;
        new_node = new_node->parent;
    }

    return (new_node);
}

