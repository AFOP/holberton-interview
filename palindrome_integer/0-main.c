#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "palindrome.h"

/**
 * main - Check runtime of is_palindrome
 *
 * Return: Always 0.
 */
int main(void)
{
	unsigned long n;
	clock_t start;
	clock_t end;
	clock_t diff;
	
	start = clock();
	for (n = 0; n < 10000000; n++)
	{
		is_palindrome(n);
	}
	end = clock();

	diff = (double)(end - start) / 1000;

	if (diff > 1000) /* More than 1 second */
		printf("Runtime too long\n");
	else
		printf("OK\n");

	return (0);
}
