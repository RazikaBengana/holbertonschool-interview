#!/usr/bin/python3
"""
Module that contains a function to determine the minimum number of copy and paste
operations needed to replicate a character in a text file to achieve a target count.
"""


def minOperations(n):
    """
    Calculate the minimum number of operations required to produce exactly n 'H' characters
    using only the 'Copy All' and 'Paste' operations.
    The solution involves finding the sum of prime factors of n, as each factor represents
    a sequence of operations

    Args:
    n (int): the target number of 'H' characters to be produced

    Returns:
    int: the minimum number of operations required
    """
    if n == 1:
        return 0

    operations = 0
    factor = 2

    while n > 1:
        while n % factor == 0:
            operations += factor
            n //= factor

        factor += 1

    return operations
