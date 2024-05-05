#include "sandpiles.h"


#define N_ROWS 3
#define N_COLS 3
#define MAX_GRAINS 3


/**
 * print_sandpile - program that prints the current state of the sandpile
 *
 * @grid: the 3x3 sandpile grid to be printed
 *
 * Return: nothing (void)
 */

void print_sandpile(int grid[3][3])
{
	int i;
	int j;

	printf("=\n");

	for (i = 0; i < N_ROWS; i++)
	{
		for (j = 0; j < N_COLS; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}



/**
 * check_is_stable - program that checks if the sandpile is stable,
 * meaning no cell exceeds the max allowed grains (MAX_GRAINS)
 *
 * if a cell exceeds, copy the grid and indicate instability
 *
 * @grid1: the current sandpile grid
 * @grid2: a secondary grid used to hold updates
 *
 * Return: 1 if stable, 0 if not
 */

int check_is_stable(int grid1[3][3], int grid2[3][3])
{
	int i;
	int j;
	int stable;

	stable = 1;

	for (i = 0; i < N_ROWS; i++)
	{
		for (j = 0; j < N_COLS; j++)
		{
			grid2[i][j] = grid1[i][j];
			if (grid1[i][j] > MAX_GRAINS)
				stable = 0;
		}
	}

	return (stable);
}



/**
 * sum_grids - program that adds the grains of two sandpiles grid by grid
 *
 * @grid1: the base sandpile grid to be modified
 * @grid2: the second grid to add to the first
 *
 * Return: nothing (void)
 */

void sum_grids(int grid1[3][3], int grid2[3][3])
{
	int i;
	int j;

	for (i = 0; i < N_ROWS; i++)
	{
		for (j = 0; j < N_COLS; j++)
		{
			grid1[i][j] += grid2[i][j];
		}
	}
}



/**
 * toppling_round - program that performs a toppling round where grains
 * exceeding MAX_GRAINS are redistributed to adjacent cells
 *
 * @grid1: the primary grid to be updated
 * @grid2: the secondary grid used to check for toppling
 *
 * Return: nothing (void)
 */

void toppling_round(int grid1[3][3], int grid2[3][3])
{
	int i;
	int j;

	for (i = 0; i < N_ROWS; i++)
	{
		for (j = 0; j < N_COLS; j++)
		{
			if (grid2[i][j] > MAX_GRAINS)
			{
				if (i > 0)
					grid1[i - 1][j] += 1;
				if (j < (N_COLS - 1))
					grid1[i][j + 1] += 1;
				if (i < (N_ROWS - 1))
					grid1[i + 1][j] += 1;
				if (j > 0)
					grid1[i][j - 1] += 1;
				grid1[i][j] -= 4;
			}
		}
	}
}



/**
 * sandpiles_sum - program that calculates the sum of two sandpiles and stabilize it
 *
 * this function prints the state of the grid after each stabilization step
 *
 * @grid1: the first sandpile grid to be summed and stabilized
 * @grid2: the second grid to be summed with the first
 *
 * Return: nothing (void)
 */

void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	sum_grids(grid1, grid2);

	while (!check_is_stable(grid1, grid2))
	{
		print_sandpile(grid1);
		toppling_round(grid1, grid2);
	}
}
