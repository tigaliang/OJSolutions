//
// Unique Paths II
// https://leetcode.com/problems/unique-paths-ii/#/description
//
#include <stdio.h>

int uniquePathsWithObstacles(int** grid, int r, int c)
{
    int i, j;

    if (0 == r || 0 == c)
        return 0;
    if (1 == grid[r - 1][c - 1])
        return 0;

    for (i = r - 1; i >= 0; --i) {
        for (j = c - 1; j >= 0; --j) {
            if (r - 1 == i && c - 1 == j)
                grid[i][j] = 1;
            else if (1 == grid[i][j])
                grid[i][j] = 0;
            else if (r - 1 == i)
                grid[i][j] = grid[i][j + 1];
            else if (c - 1 == j)
                grid[i][j] = grid[i + 1][j];
            else
                grid[i][j] = grid[i + 1][j] + grid[i][j + 1];
        }
    }

    return grid[0][0];
}

int main(int argc, char const *argv[])
{
    return 0;
}