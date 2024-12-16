#!/usr/bin/python3

"""
Module that calculates the total amount of rainwater retained by the walls.
"""


def rain(walls):
    """
        Calculate the total amount of rainwater retained by the walls.

        Args:
            walls (list of int): Heights of the walls.

        Returns:
            int: Total units of water retained.
    """

    if not walls or len(walls) < 3:
        return 0

    left = 0
    left_max = 0

    right = len(walls) - 1
    right_max = 0

    rainwater = 0

    while left < right:
        if walls[left] < walls[right]:
            if walls[left] > left_max:
                left_max = walls[left]
            else:
                rainwater += left_max - walls[left]
            left += 1
        else:
            if walls[right] > right_max:
                right_max = walls[right]
            else:
                rainwater += right_max - walls[right]
            right -= 1

    return rainwater
