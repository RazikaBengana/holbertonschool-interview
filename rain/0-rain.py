#!/usr/bin/python3
"""Module to simulate water trapping after rain between walls"""


def rain(walls):
    """
    Calculate the amount of water trapped after raining between walls

    Args:
        walls (list of int): the heights of the walls where water can be trapped

    Returns:
        int: the total amount of water that can be trapped between the walls

    Raises:
        ValueError: if the input is not a list of integers
    """

    if type(walls) is not list or not all(type(n) is int for n in walls):
        return 0

    total_water_units = 0
    walls_len = len(walls)

    for current_wall_index in range(1, walls_len - 1):
        left_max = max(walls[:current_wall_index])
        right_max = max(walls[current_wall_index + 1:])

        water_level = min(left_max, right_max)

        if water_level > walls[current_wall_index]:
            total_water_units += water_level - walls[current_wall_index]

    return total_water_units
