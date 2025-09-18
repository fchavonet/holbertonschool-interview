#!/usr/bin/python3

"""
Module that generates Pascal's Triangle up to n rows.
"""


def pascal_triangle(n):
    """
    Returns Pascal's Triangle as a list of lists of integers.
    """

    if n <= 0:
        return []

    triangle = [[1]]

    for i in range(1, n):
        prev_row = triangle[i - 1]
        new_row = [1]

        for j in range(1, i):
            new_row.append(prev_row[j - 1] + prev_row[j])

        new_row.append(1)
        triangle.append(new_row)

    return triangle
