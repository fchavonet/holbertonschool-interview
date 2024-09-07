#include "sandpiles.h"

/**
 * sandpiles_sum - Adds and stabilizes two 3x3 sandpiles.
 * @grid1: left 3x3 grid.
 * @grid2: right 3x3 grid.
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	/* Add grid2 to grid1 */
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
			grid1[i][j] += grid2[i][j];
	}

	/* Stabilize the grid */
	while (is_stable(grid1) == 0)
	{
		printf("=\n");
		_print_grid(grid1);
		toppling_round(grid1);
	}
}

/**
 * is_stable - Checks if a 3x3 grid is stable.
 * @grid: 3x3 grid.
 * Return: 1 if the grid is stable, 0 otherwise.
 */
int is_stable(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
				return (0);
		}
	}

	return (1);
}

/**
 * toppling_round - Performs one round of toppling on a 3x3 grid.
 * @grid: 3x3 grid to stabilize.
 */
void toppling_round(int grid[3][3])
{
	int i, j;
	int temp_grid[3][3] = {0};

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
			{
				temp_grid[i][j] -= 4;

				/* Top neighbor */
				if (i - 1 >= 0)
					temp_grid[i - 1][j] += 1;

				/* Right neighbor */
				if (j + 1 < 3)
					temp_grid[i][j + 1] += 1;

				/* Bottom neighbor */
				if (i + 1 < 3)
					temp_grid[i + 1][j] += 1;

				/* Left neighbor */
				if (j - 1 >= 0)
					temp_grid[i][j - 1] += 1;
			}
		}
	}

	/* Update the grid */
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
			grid[i][j] += temp_grid[i][j];
	}
}

/**
 * _print_grid - Print 3x3 grid.
 * @grid: 3x3 grid to print.
 */
void _print_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}
