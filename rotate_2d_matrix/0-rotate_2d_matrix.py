#!/usr/bin/python3
"""
This module contains a function to rotate a 2D matrix by 90 degrees clockwise
"""


def rotate_2d_matrix(matrix):
    """
    Rotate the given n x n 2D matrix by 90 degrees clockwise

    Args:
        matrix (list of list): the input 2D matrix to be rotated

    Returns:
        None. The function modifies the input matrix in place
    """

    n = len(matrix)

    # Transpose the matrix
    for i in range(n):
        for j in range(i, n):
            matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]

    # Reverse each row
    for i in range(n):
        matrix[i] = matrix[i][::-1]
