//
// Set Matrix Zeroes
// https://leetcode.com/problems/set-matrix-zeroes/description/
//
#include <stdio.h>

void setZeroes(int** matrix, int r, int c)
{
    int i, j;
    int r0 = 0, c0 = 0;

    if (r < 1 || c < 1)
        return;

    for (i = 0; i < r; ++i) {
        for (j = 0; j < c; ++j) {
            if (!matrix[i][j]) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
                if (i == 0)
                    r0 = 1;
                if (j == 0)
                    c0 = 1;
            }
        }
    }

    for (i = 1; i < r; ++i) {
        if (matrix[i][0])
            continue;
        for (j = 0; j < c; ++j)
            matrix[i][j] = 0;
    }
    for (j = 1; j < c; ++j) {
        if (matrix[0][j])
            continue;
        for (i = 0; i < r; ++i)
            matrix[i][j] = 0;
    }

    if (r0) {
        for (j = 0; j < c; ++j)
            matrix[0][j] = 0;
    }
    if (c0) {
        for (i = 0; i < r; ++i)
            matrix[i][0] = 0;
    }
}

int main(int argc, char const *argv[])
{
    int i, j;

    int r0[] = {1,7,4,3};
    int r1[] = {3,0,6,1};
    int r2[] = {1,2,4,0};
    int* g[3];
    g[0] = r0;
    g[1] = r1;
    g[2] = r2;

    setZeroes(g, 3, 4);
    for (i = 0; i < 3; ++i) {
        for (j = 0; j < 4; ++j) {
            printf("%d ", g[i][j]);
        }
        printf("\n");
    }

    return 0;
}