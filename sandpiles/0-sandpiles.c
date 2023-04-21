#include <stdlib.h>
#include <stdio.h>

#include "sandpiles.h"

/**
 * sum_grid - sum the two grids
 * @grid1: 3x3 grid
 * @grid2: 3x3 grid
 *
 */
void sum_grid(int grid1[3][3], int grid2[3][3]) 
{
    int i, j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            grid1[i][j] += grid2[i][j];
        }
    }
}

/**
 * redistribute - redistribute the grid
 * @grid: 3x3 grid
 *
 */
void redistribute(int grid1[3][3])
{
    int i, j;
    int temp[3][3];

    for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			temp[i][j] = 0;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (grid1[i][j] > 3)
            {
                if (i > 0)
                    temp[i - 1][j] += 1;
                if (i < 2)
                    temp[i + 1][j] += 1;
                if (j > 0)
                    temp[i][j - 1] += 1;
                if (j < 2)
                    temp[i][j + 1] += 1;
                grid1[i][j] -= 4;
            }
        }
    }
    sum_grid(grid1, temp);
}

/**
 * is_stable - check the grid is stable
 * @grid: 3x3 grid
 *
 * return: 0 if not is stable or 1 if is stable
 */
int is_stable(int grid1[3][3])
{
    int i, j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (grid1[i][j] > 3)
            {
                return 0;
            }
        }
    }
    return 1;
}

/**
 * print_grid - Print 3x3 grid
 * @grid: 3x3 grid
 *
 */
static void print_grid(int grid[3][3])
{
	int i, j;

    printf("=\n");
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

/**
 * sandpiles_sum - sum 3x3 grids
 * @grid1: 3x3 grid one
 * @grid2: 3x3 grid two
 *
 */

void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
    sum_grid(grid1, grid2);
    while (!is_stable(grid1))
    {
        print_grid(grid1);
        redistribute(grid1);
    }
}
