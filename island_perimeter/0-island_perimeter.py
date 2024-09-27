#!/usr/bin/python3

"""
Module to calculate the perimeter of an island in a grid.
An island is represented by 1 numbers and water by 0 numbers.
"""


def island_perimeter(grid):
    """
    Calculates the perimeter of the island in the grid.

    Args:
        grid (list of list of int): 2D grid with 1 as land and 0 as water.

    Returns:
        int: The perimeter of the island.
    """

    perimeter = 0

    # Loop through the grid.
    for i in range(len(grid)):
        for j in range(len(grid[i])):
            # If it's land.
            if grid[i][j] == 1:
                # Add 4 for the current land cell.
                perimeter += 4

                # Check the cell above.
                if grid[i - 1][j] == 1:
                    # Subtract 2 for adjacent land above.
                    perimeter -= 2

                # Check the cell to the left.
                if grid[i][j - 1] == 1:
                    # Subtract 2 for adjacent land on the left.
                    perimeter -= 2

    # Return total perimeter.
    return perimeter
