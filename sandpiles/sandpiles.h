#ifndef SANDPILES_H
#define SANDPILES_H

#include <stdio.h>

/* Function prototypes */
void sandpiles_sum(int grid1[3][3], int grid2[3][3]);
int is_stable(int grid[3][3]);
void toppling_round(int grid[3][3]);
void _print_grid(int grid[3][3]);

#endif /* SANDPILES_H */
