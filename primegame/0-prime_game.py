#!/usr/bin/python3

"""
Module implementing a prime number game between Maria and Ben.
"""


def isWinner(x, nums):
    """
    Determine the winner of the prime game for multiple rounds.

    Args:
        x: number of rounds.
        nums: array of n values for each round.

    Returns:
        Name of the player that won the most rounds, or None if tie.
    """

    if not nums or x == 0:
        return None

    def is_prime(n):
        """
        Check if a number is prime.
        """

        if n < 2:
            return False

        if n == 2:
            return True

        if n % 2 == 0:
            return False

        for i in range(3, int(n**0.5) + 1, 2):
            if n % i == 0:
                return False

        return True

    def count_primes(n):
        """
        Count prime numbers from 1 to n.
        """

        count = 0

        for i in range(2, n + 1):
            if is_prime(i):
                count += 1

        return count

    maria_wins = 0
    ben_wins = 0

    for i in range(x):
        if i >= len(nums):
            break

        n = nums[i]
        prime_count = count_primes(n)

        # If odd number of primes, Maria wins (she goes first).
        # If even number of primes (including 0), Ben wins.
        if prime_count % 2 == 1:
            maria_wins += 1
        else:
            ben_wins += 1

    if maria_wins > ben_wins:
        return "Maria"
    elif ben_wins > maria_wins:
        return "Ben"
    else:
        return None
