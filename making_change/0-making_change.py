#!/usr/bin/python3

"""
Module implementing dynamic programming solution for the coin change problem.
"""


def makeChange(coins, total):
    """
    Finds the fewest number of coins needed to reach the total.
    If it's impossible, returns -1.

    Args:
        coins (list): list of coin denominations.
        total (int): target amount to reach.

    Returns:
        int: minimum number of coins needed, or -1 if impossible.
    """

    # Edge case: if total is zero or negative, no coins are needed.
    if total <= 0:
        return 0

    # Initialize DP table with "infinite" values.
    dp = [float("inf")] * (total + 1)
    dp[0] = 0

    # Build the solution incrementally.
    for coin in coins:
        for amount in range(coin, total + 1):
            # Check if using the current coin reduces the number of coins.
            if dp[amount - coin] + 1 < dp[amount]:
                dp[amount] = dp[amount - coin] + 1

    # Check if solution was found.
    if dp[total] == float("inf"):
        return -1
    else:
        return dp[total]
