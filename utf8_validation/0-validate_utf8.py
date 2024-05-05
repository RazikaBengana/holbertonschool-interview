#!/usr/bin/python3
"""Module that contains a function to validate UTF-8 encoding"""


def validUTF8(data):
    """
    Validate UTF-8 encoding in a list of integers.
    Each integer in the list should represent one byte of a UTF-8 encoded character.
    The function checks if the given list of byte-values forms valid UTF-8 encoded characters.
    Returns True if the data is valid UTF-8, otherwise False.
    """

    if not (type(data) is list and all([isinstance(n, int) for n in data])):
        return False

    # Convert negative integers to their corresponding positive values
    data = [n + 256 if n < 0 and n > -129 else n for n in data]

    # Keep only the least significant 8 bits of each integer
    data = [n & 0xFF if n >= 0 else n for n in data]

    try:
        bytes(data).decode(encoding='utf-8', errors='strict')
    except (ValueError, UnicodeDecodeError):
        return False
    return True
