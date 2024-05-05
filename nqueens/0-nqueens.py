#!/usr/bin/python3
"""
Module that solves the N-Queens problem using a recursive generator function
"""

import sys


if len(sys.argv) != 2:
    print('Usage: nqueens N')
    exit(1)

if not sys.argv[1].isdigit():
    print('N must be a number')
    exit(1)

N = int(sys.argv[1])

if N < 4:
    print('N must be at least 4')
    exit(1)


def queens(N, i, a, b, c, d):
    """
    Generate all solutions to the N-Queens problem for a given N

    N: the size of the board (N x N)
    i: current index (or row) in the recursive call
    a: columns where queens are placed
    b: diagonals (top-left to bottom-right)
    c: anti-diagonals (bottom-left to top-right)
    d: current configuration of queens on the board, as a list of lists

    The function recursively attempts to place queens in a manner that
    they do not attack each other, yielding each valid board configuration
    """

    if i < N:
        for j in range(N):
            if j not in a and i+j not in b and i-j not in c:
                yield from queens(N, i+1, a+[j], b+[i+j], c+[i-j], d+[[i, j]])
    else:
        yield d


for solution in queens(N, 0, [], [], [], []):
    print(solution)
