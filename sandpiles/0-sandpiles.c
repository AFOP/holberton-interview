#include <stdlib.h>
#include <stdio.h>

#include "sandpiles.h"

/**
 * not_stable - check if grid is not stable
 * @grid: 3x3 grid
 *
 */
int not_stable(int grid1[3][3])
{
    int i, j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (grid1[i][j] > 3)
            {
                grid1[i][j] -= 4;
                if (i > 0)
                    grid1[i - 1][j] += 1;
                if (i < 2)
                    grid1[i + 1][j] += 1;
                if (j > 0)
                    grid1[i][j - 1] += 1;
                if (j < 2)
                    grid1[i][j + 1] += 1;
            }
        }
    }
    return 1;
}

/**
 * sandpiles_sum - sum 3x3 grids
 * @grid1: 3x3 grid one
 * @grid2: 3x3 grid two
 *
 */

void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
    int i, j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            grid1[i][j] += grid2[i][j];
        }
    }    
    not_stable(grid1);
}
