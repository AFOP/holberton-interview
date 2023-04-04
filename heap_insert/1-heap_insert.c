#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary_trees.h"

/**
 * struct heap_t - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
typedef struct heap_s
{
	int n;
	struct heap_s **parent;
    struct heap_s *left;
    struct heap_s *right;
} heap_t;

/**
 * heapify - Recursive function to restore max-heap property.
 *
 * @heap: Pointer to the heap to heapify
 */
void heapify(heap_t *heap)
{
    heap_t *child;
    int tmp;

    while (heap->left)
    {
        child = heap->left;
        if (heap->right && heap->right->n > child->n)
            child = heap->right;
        if (heap->n >= child->n)
            return;
        tmp = heap->n;
        heap->n = child->n;
        child->n = tmp;
        heap = child;
    }
}

/**
 * heap_insert - inserts a value into a Max Binary Heap
 * @root: is a double pointer to the root node of the Heap
 * @value: is the value to store in the node to be inserted
 * If the address stored in root is NULL, the created node must become the root node.
 * You have to respect a Max Heap ordering
 * You are allowed to have up to 6 functions in your file
 * Return: pointer to the new node, or NULL on failure
*/

heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node, *parent;

    if (!root)
        return (NULL);

    /* Create new node */
    new_node = binary_tree_node(NULL, value);
    if (!new_node)
        return (NULL);

    /* If the root is empty, the new node becomes the root */
    if (!*root)
        return (*root = new_node);

    /* Find the first available spot from left to right */
    parent = *root;
    while (parent->left && parent->right)
    {
        if (binary_tree_balance(parent->left) <= 0)
            parent = parent->left;
        else
            parent = parent->right;
    }

    /* Insert the new node */
    if (!parent->left)
        return (parent->left = new_node);
    else
        return (parent->right = new_node);
}
