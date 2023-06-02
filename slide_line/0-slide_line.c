#include <stdlib.h>
#include <stdio.h>

#include "slide_line.h"

/**
 * slide_line - slides and merges an array of integers
 * @line: array of integers
 * @size: size of the array
 * @direction: direction to slide (SLIDE_LEFT or SLIDE_RIGHT)
 * Return: 1 upon success, or 0 upon failure
 */


int slide_line(int *line, size_t size, int direction)
{
    int i, j, merged;

    if (direction != SLIDE_LEFT && direction != SLIDE_RIGHT)
        return 0;

    if (direction == SLIDE_LEFT)
    {
        merged = 0;
        for (i = 0, j = 1; j < (int)size;)
        {
            if (line[j] == 0)
            {
                j++;
                continue;
            }
            if (line[i] == 0)
            {
                line[i] = line[j];
                line[j] = 0;
                merged = 1;
                continue;
            }
            if (line[i] == line[j])
            {
                line[i] *= 2;
                line[j] = 0;
                merged = 1;
            }
            i++;
            j++;
        }
        return merged;
    }
    else if (direction == SLIDE_RIGHT)
    {
        merged = 0;
        for (i = size - 1, j = size - 2; j >= 0;)
        {
            if (line[j] == 0)
            {
                j--;
                continue;
            }
            if (line[i] == 0)
            {
                line[i] = line[j];
                line[j] = 0;
                merged = 1;
                continue;
            }
            if (line[i] == line[j])
            {
                line[i] *= 2;
                line[j] = 0;
                merged = 1;
            }
            i--;
            j--;
        }
        return merged;
    }

    return 0;
}
