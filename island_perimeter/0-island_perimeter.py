#!/usr/bin/python3
"""
Island Perimeter module
"""
def island_perimeter(grid):
    """ Calculate perimeter of the island (grid)

        Args:
            grid ([[int]]): is a list of list of integers
        Return: perimeter of the island described in grid 
    """
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
