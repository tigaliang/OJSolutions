//
// Valid Sudoku
// https://leetcode.com/problems/valid-sudoku/#/description
//

#include <stdio.h>

bool isValidSudoku(char** board, int boardRowSize, int boardColSize)
{
    int a[3][9][9];
    int i, j, k;
    int c;

    for (i = 0; i < 3; ++i)
        for (j = 0; j < 9; ++j)
            for (k = 0; k < 9; ++k)
                a[i][j][k] = 0;

    for (i = 0; i < 9; ++i)
        for (j = 0; j < 9; ++j) {
            if (board[i][j] == '.') continue;
            c = board[i][j] - '0';
            if (a[0][i][c - 1]) return false; // row
            if (a[1][j][c - 1]) return false; // column
            if (a[2][i / 3 * 3 + j / 3][c - 1]) return false; // grid

            a[0][i][c - 1] = 1;
            a[1][j][c - 1] = 1;
            a[2][i / 3 * 3 + j / 3][c - 1] = 1;
        }

    return true;
}

int main(int argc, char const *argv[])
{
    return 0;
}