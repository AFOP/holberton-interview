#!/usr/bin/python3
"""
Create a function def island_perimeter(grid): that returns the perimeter of the island described in grid:
grid is a list of list of integers:
0 represents water
1 represents land
Each cell is square, with a side length of 1
Cells are connected horizontally/vertically (not diagonally).
grid is rectangular, with its width and height not exceeding 100
The grid is completely surrounded by water
There is only one island (or nothing).
The island doesn’t have “lakes” (water inside that isn’t connected to the water surrounding the island).
"""
def island_perimeter(grid):
    perimeter = 0
    
    # Define the possible neighboring directions
    directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]
    
    for row in range(len(grid)):
        for col in range(len(grid[0])):
            if grid[row][col] == 1:
                for dr, dc in directions:
                    new_row, new_col = row + dr, col + dc
                    # Check if the neighbor is out of bounds or is water
                    if new_row < 0 or new_row >= len(grid) or new_col < 0 or new_col >= len(grid[0]) or grid[new_row][new_col] == 0:
                        perimeter += 1
    
    return perimeter
