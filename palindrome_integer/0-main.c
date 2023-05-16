#include <stdlib.h>
#include <stdio.h>

#include "palindrome.h"

/**
 * main - Entry point
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(void)
{
	unsigned long n;
	int ret;

	n = 0;
	ret = is_palindrome(n);

	printf("%lu is ", n);
	if (ret == 0)
		printf("not ");
	printf("a palindrome.\n");

	return (EXIT_SUCCESS);
}
