#!/usr/bin/python3
"""
Module that checks if all boxes can be unlocked starting from the first box
"""


def canUnlockAll(boxes):
    """
    Determine if all boxes can be unlocked using the keys found inside them
    """

    box_count = len(boxes)
    is_unlocked = [False] * box_count
    is_unlocked[0] = True
    unlock_queue = [0]

    while unlock_queue:
        current_box = unlock_queue.pop(0)
        for key in boxes[current_box]:
            if key < box_count and not is_unlocked[key]:
                is_unlocked[key] = True
                unlock_queue.append(key)

    return all(is_unlocked)
