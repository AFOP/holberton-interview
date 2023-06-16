#!/usr/bin/python3
"""
nqueens
"""
import sys


def is_safe(board, row, col, N):
    """
    Check if the current position is safe for the queen
    Checking the row
    """
    for i in range(col):
        if board[row][i] == 'Q':
            return False

    # Checking the upper diagonal
    for i, j in zip(range(row, -1, -1), range(col, -1, -1)):
        if board[i][j] == 'Q':
            return False

    # Checking the lower diagonal
    for i, j in zip(range(row, N, 1), range(col, -1, -1)):
        if board[i][j] == 'Q':
            return False

    return True


def solve_nqueens_util(board, col, N):
    """Base case: If all queens are placed, print the solution"""
    if col >= N:
        print_solution(board, N)
        return True

    # Recursive case: Try placing the queen in each row of the current column
    for i in range(N):
        if is_safe(board, i, col, N):
            board[i][col] = 'Q'
            solve_nqueens_util(board, col + 1, N)
            board[i][col] = '.'


def solve_nqueens(N):
    """Create an empty N x N board"""
    board = [['.' for _ in range(N)] for _ in range(N)]
    solve_nqueens_util(board, 0, N)


def print_solution(board, N):
    """Print the board configuration"""
    for i in range(N):
        print(' '.join(board[i]))
    print()


if __name__ == '__main__':
    if len(sys.argv) != 2:
        print('Usage: nqueens N')
        sys.exit(1)

    try:
        N = int(sys.argv[1])
    except ValueError:
        print('N must be a number')
        sys.exit(1)

    if N < 4:
        print('N must be at least 4')
        sys.exit(1)

    solve_nqueens(N)
