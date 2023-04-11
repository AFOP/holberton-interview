#!/usr/bin/python3
"""
In a text file, there is a single character H.
Your text editor can execute only two operations
in this file: Copy All and Paste. Given a number n,
write a method that calculates the fewest number
of operations needed to result in exactly n
H characters in the file.

Prototype: def minOperations(n)
@n: number de characters
Returns an integer
If n is impossible to achieve, return 0
"""


def minOperations(n):
    if not isinstance(n, int) or n < 1:
        return 0
    dp = [n+1] * (n+1)
    dp[1] = 0
    for i in range(2, n+1):
        for j in range(1, i):
            if i % j == 0:
                dp[i] = min(dp[i], dp[j] + i//j - 1)
    return dp[n]
