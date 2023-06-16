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
        if board[row][i] == 1:
            return False

    # Checking the upper diagonal
    for i, j in zip(range(row, -1, -1), range(col, -1, -1)):
        if board[i][j] == 1:
            return False

    # Checking the lower diagonal
    for i, j in zip(range(row, N, 1), range(col, -1, -1)):
        if board[i][j] == 1:
            return False

    return True


def solve_nqueens_util(board, col, N, solutions):
    """Base case: If all queens are placed, add the solution"""
    if col >= N:
        solution = []
        for i in range(N):
            for j in range(N):
                if board[i][j] == 1:
                    solution.append([i, j])
        solutions.append(solution)
        return True

    # Recursive case: Try placing the queen in each row of the current column
    for i in range(N):
        if is_safe(board, i, col, N):
            board[i][col] = 1
            solve_nqueens_util(board, col + 1, N, solutions)
            board[i][col] = 0


def solve_nqueens(N):
    """solve nqueens"""
    if N < 4:
        print(f"N must be at least 4")
        sys.exit(1)

    board = [[0 for _ in range(N)] for _ in range(N)]
    solutions = []
    solve_nqueens_util(board, 0, N, solutions)

    for solution in solutions:
        print(solution)


if __name__ == '__main__':
    if len(sys.argv) != 2:
        print(f"Usage: nqueens N")
        sys.exit(1)

    try:
        N = int(sys.argv[1])
    except ValueError:
        print(f"N must be a number")
        sys.exit(1)

    solve_nqueens(N)
