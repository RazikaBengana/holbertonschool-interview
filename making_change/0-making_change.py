#!/usr/bin/python3
"""
Module to compute the minimum number of coins needed for a given amount
"""


def makeChange(coins, total):
    """
    Calculate the minimum number of coins required to make up a given amount

    Args:
        coins (list): the available denominations of coins
        total (int): the total amount to make up

    Returns:
        int: the minimum number of coins needed, or -1 if it's not possible
    """
    if total <= 0:
        return 0

    min_coins = [float('inf')] * (total + 1)
    min_coins[0] = 0

    coins.sort()

    for amount in range(total + 1):
        for coin in coins:
            if coin > amount:
                break
            if min_coins[amount - coin] != -1:
                min_coins[amount] = min(min_coins[amount - coin] + 1,
                                        min_coins[amount])

    return min_coins[total] if min_coins[total] != float('inf') else -1
