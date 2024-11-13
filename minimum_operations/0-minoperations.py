#!/usr/bin/python3

"""
Module that calculates the minimum operations to reach n H characters.
"""


def minOperations(n):
    """
    Calculates the minimum operations to reach n H characters.

    Args:
        n (int): the target number of H characters.

    Returns:
        int: the minimum number of operations needed, or 0 if n is impossible.
    """
    if n <= 1:
        # No operations are needed if n is less than or equal to 1.
        return 0

    # Initialize the total number of operations performed.
    operations = 0
    # Start checking from the smallest prime number.
    divisor = 2

    # Factorize n by dividing it by the smallest possible divisors.
    while n > 1:
        # If n is divisible by the current divisor.
        while n % divisor == 0:
            # Add the divisor to the operations count.
            operations += divisor
            # Reduce n by dividing it by the current divisor.
            n //= divisor
            # Move to the next potential divisor .
        divisor += 1

    return operations
