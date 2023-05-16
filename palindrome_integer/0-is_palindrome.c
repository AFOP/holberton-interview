#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "palindrome.h"

/**
 * is_palindrome - checks whether or not a given unsigned integer is a palindrome
 * @n: number to check
 * Return: return 1 if n is a palindrome, and 0 otherwise
 */
int is_palindrome(unsigned long n)
{
    char num_str[20];
    sprintf(num_str, "%lu", n);

    int i = 0;
    int j = strlen(num_str) - 1;

    while (i < j) {
        if (num_str[i] != num_str[j])
            return (0);
        i++;
        j--;
    }
    return (1);
}
