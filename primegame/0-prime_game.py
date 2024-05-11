#!/usr/bin/python3
"""
This script determines the winner of a game based on the count of prime numbers up to each number in a list.
The function counts the prime numbers up to the maximum number in the list, then evaluates each number
in the list to determine if the cumulative count of primes up to that number is odd or even.
If odd, Maria wins, and if even, Ben wins.
Return the winner's name or None in case of a tie.
"""


def determine_prime_game_winner(total_games, number_ranges):
    """
    Determine the winner of the Prime Count Game based on counting
    prime numbers within specified ranges
    """

    if not number_ranges or total_games < 1:
        return None

    max_range_limit = max(number_ranges)
    is_prime = [True for _ in range(max(max_range_limit + 1, 2))]

    for i in range(2, int(pow(max_range_limit, 0.5)) + 1):
        if not is_prime[i]:
            continue
        for j in range(i*i, max_range_limit + 1, i):
            is_prime[j] = False

    is_prime[0] = is_prime[1] = False
    cumulative_primes = 0

    for i in range(len(is_prime)):
        if is_prime[i]:
            cumulative_primes += 1
        is_prime[i] = cumulative_primes

    maria_score = 0

    for limit in number_ranges:
        maria_score += is_prime[limit] % 2 == 1

    if maria_score * 2 == len(number_ranges):
        return None
    if maria_score * 2 > len(number_ranges):
        return "Maria"
    return "Ben"
