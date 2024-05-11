#!/usr/bin/python3
"""
Module that calculates the perimeter of an island in a grid
"""


def island_perimeter(grid):
    """
    Calculate the perimeter of an 'island' in a 2D grid

    This function iterates over each cell in a grid.
    If a cell is part of the island (represented by 1),
    it checks its neighboring cells (top, bottom, left, right).
    If a neighboring cell is water (represented by 0) or it is out of bounds,
    the perimeter is increased by one for that side.

    Args:
        grid (list of list of int): The grid representation of the map;
                                    Land cells are 1, water cells are 0

    Returns:
        int: The total perimeter of the island
    """

    rows, cols = len(grid), len(grid[0])
    perimeter = 0

    # Loop through each cell in the grid
    for row in range(rows):
        for col in range(cols):
            # If we find a land cell, check its surroundings
            if grid[row][col] == 1:
                # Check top
                if row == 0 or grid[row-1][col] == 0:
                    perimeter += 1
                # Check bottom
                if row == rows - 1 or grid[row+1][col] == 0:
                    perimeter += 1
                # Check left
                if col == 0 or grid[row][col-1] == 0:
                    perimeter += 1
                # Check right
                if col == cols - 1 or grid[row][col+1] == 0:
                    perimeter += 1
    return perimeter
