#!/usr/bin/python3
"""
Module that defines a function to generate Pascal's Triangle up to a specified number of rows
"""


def pascal_triangle(n):
    """
    Generate Pascal's Triangle up to n rows;

    If n is less than or equal to 0, the function returns an empty list.
    Otherwise, it starts with the first row of Pascal's Triangle, which is always [1].
    For each subsequent row up to n, the function computes the values based on the
    sum of two consecutive elements in the previous row, with 1s at the edges of each row.

    Args:
    n (int): The number of rows of Pascal's Triangle to generate

    Returns:
    list: A list of lists containing the values of Pascal's Triangle
    """

    if n <= 0:
        return []

    triangle = [[1]]

    for i in range(1, n):
        row = [1]
        for j in range(1, i):
            row.append(triangle[i-1][j-1] + triangle[i-1][j])
        row.append(1)
        triangle.append(row)

    return triangle
