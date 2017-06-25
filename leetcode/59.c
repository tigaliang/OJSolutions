//
// Spiral Matrix II
// https://leetcode.com/problems/spiral-matrix-ii/#/description
//

#include <stdio.h>
#include <stdlib.h>

/**
 * Return an array of arrays.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int** generateMatrix(int n)
{
    int ri = 1;
    int i, j, k, l, m, c;

    int **ret = (int **) malloc(n * sizeof(int *));
    for (i = 0; i < n; ++i)
        ret[i] = (int *) malloc(n * sizeof(int));

    if (n < 1)
        return NULL;
    if (n == 1) {
        ret[0][0] = 1;
        return ret;
    }

    c = n - 1;
    for (l = 0, m = (n + 1) / 2; l < m; ++l) {
        // left to right
        i = l;
        j = l;
        for (k = 0; k < c; ++k)
            ret[i][j++] = ri++;

        // up to down
        i = l;
        j = n - 1 - l;
        for (k = 0; k < c; ++k)
            ret[i++][j] = ri++;

        // right to left
        i = n - 1 - l;
        j = n - 1 - l;
        for (k = 0; k < c; ++k)
            ret[i][j--] = ri++;

        // down to up
        i = n - 1 - l;
        j = l;
        for (k = 0; k < c; ++k)
            ret[i--][j] = ri++;

        c -= 2;
        if (c == 0) {
            ret[n / 2][n / 2] = ri++;
            break;
        }
        if (c < 0)
            break;
    }

    return ret;
}

int main(int argc, char const *argv[])
{
    int n = 3;
    int **ret = generateMatrix(n);
    int i, j;
    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j)
            printf("%d ", ret[i][j]);
        printf("\n");
    }

    return 0;
}