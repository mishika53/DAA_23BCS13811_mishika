// sudoku_solver.cpp
#include <iostream>
#include <cmath>
using namespace std;

void Print(int board[][9], int n) {
    for (int i = 0; i < n; i++)  {
        for (int j = 0; j < n; j++)
            cout << board[i][j] << " ";
        cout << endl;
    }
}

bool isValid(int board[][9], int i, int j, int num, int n) {
    for (int x = 0; x < n; x++)
        if (board[i][x] == num || board[x][j] == num)
            return false;

    int rn = sqrt(n), si = i - i % rn, sj = j - j % rn;
    for (int x = si; x < si + rn; x++)
        for (int y = sj; y < sj + rn; y++)
            if (board[x][y] == num)
                return false;

    return true;
}

bool SudokuSolver(int board[][9], int i, int j, int n) {
    if (i == n) return true;
    if (j == n) return SudokuSolver(board, i + 1, 0, n);
    if (board[i][j] != 0) return SudokuSolver(board, i, j + 1, n);

    for (int num = 1; num <= 9; num++) {
        if (isValid(board, i, j, num, n)) {
            board[i][j] = num;
            if (SudokuSolver(board, i, j + 1, n)) return true;
            board[i][j] = 0;
        }
    }
    return false;
}

int main() {
    int board[9][9];
    for (int i = 0; i < 9; i++)  // read from stdin
        for (int j = 0; j < 9; j++)
            cin >> board[i][j];

    if (SudokuSolver(board, 0, 0, 9))
        Print(board, 9);
    else
        cout << "No solution found\n";

    return 0;
}

