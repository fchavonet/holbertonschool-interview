#include "slide_line.h"

/**
 * slide_line - Slides and merges an array of integers in a given direction.
 * @line: Pointer to an array of integers.
 * @size: The size of the array.
 * @direction: The direction to slide and merge (SLIDE_LEFT or SLIDE_RIGHT).
 *
 * Return: 1 on success, or 0 on failure if an invalid direction is provided.
 */
int slide_line(int *line, size_t size, int direction)
{
	if (direction == SLIDE_LEFT)
	{
		slide_left(line, size);
		merge_left(line, size);
		slide_left(line, size);
	}
	else if (direction == SLIDE_RIGHT)
	{
		slide_right(line, size);
		merge_right(line, size);
		slide_right(line, size);
	}
	else
		return (0);

	return (1);
}

/**
 * slide_right - Slides the values in the array to the right.
 * @line: Pointer to an array of integers.
 * @size: The size of the array.
 */
void slide_right(int *line, size_t size)
{
	int pos = size - 1;

	/* Traverse the array from right to left. */
	for (int i = size - 1; i >= 0; i--)
	{
		if (line[i] != 0)
		{
			/* Move non-zero value to the correct position. */
			line[pos] = line[i];

			/* Set the current position to zero if a value was moved. */
			if (pos != i)
				line[i] = 0;

			/* Update the position for the next non-zero value. */
			pos--;
		}
	}
}

/**
 * merge_right - Merges adjacent equal values when sliding to the right.
 * @line: Pointer to an array of integers.
 * @size: The size of the array.
 */
void merge_right(int *line, size_t size)
{
	/* Traverse the array from right to left. */
	for (int i = size - 1; i > 0; i--)
	{
		if (line[i] == line[i - 1] && line[i] != 0)
		{
			/* Merge adjacent equal values. */
			line[i] *= 2;
			/* Set the second element to zero. */
			line[i - 1] = 0;
		}
	}
}

/**
 * slide_left - Slides the values in the array to the left.
 * @line: Pointer to an array of integers.
 * @size: The size of the array.
 */
void slide_left(int *line, size_t size)
{
	size_t pos = 0;

	/* Traverse the array from left to right. */
	for (size_t i = 0; i < size; i++)
	{
		if (line[i] != 0)
		{
			/* Move non-zero value to the correct position. */
			line[pos] = line[i];

			/* Set the current position to zero if a value was moved. */
			if (pos != i)
				line[i] = 0;

			/* Update the position for the next non-zero value. */
			pos++;
		}
	}
}

/**
 * merge_left - Merges adjacent equal values when sliding to the left.
 * @line: Pointer to an array of integers.
 * @size: The size of the array.
 */
void merge_left(int *line, size_t size)
{
	/* Traverse the array from left to right. */
	for (size_t i = 0; i < size - 1; i++)
	{
		if (line[i] == line[i + 1] && line[i] != 0)
		{
			/* Merge adjacent equal values. */
			line[i] *= 2;
			/* Set the second element to zero. */
			line[i + 1] = 0;
		}
	}
}
