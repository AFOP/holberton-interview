#!/usr/bin/python3
"""
In a text file, there is a single character H.
Your text editor can execute only two operations
in this file: Copy All and Paste. Given a number n,
write a method that calculates the fewest number
of operations needed to result in exactly n
H characters in the file.

Prototype: def minOperations(n)
@n: number repeat the character
Returns an integer
If n is impossible to achieve, return 0
"""


def minOperations(n):
    half = 2
    number_of_operations = 0

    if n <= 1 or type(n) is not int:
        return 0

    while n > 1:
        if n % half == 0:
            n /= half
            number_of_operations += half
        else:
            half += 1

    return number_of_operations
