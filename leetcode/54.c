//
// Spiral Matrix
// https://leetcode.com/problems/spiral-matrix/#/description
//

#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int row, int col)
{
    int *ret;
    int ri = 0;
    int i, j, k;
    int l;
    int m;
    int cr, cc;

    if (row < 1)
        return NULL;

    ret = (int *) malloc(row * col * sizeof(int));

    cr = row - 1;
    cc = col - 1;
    for (l = 0, m = (row + 1) / 2; l < m; ++l) {
        if (cc == 0) {
            i = j = l;
            for (k = 0; k <= cr; ++k)
                ret[ri++] = matrix[i++][j];
            break;
        }
        if (cr == 0) {
            i = j = l;
            for (k = 0; k <= cc; ++k)
                ret[ri++] = matrix[i][j++];
            break;
        }

        // left to right
        i = l;
        j = l;
        for (k = 0; k < cc; ++k)
            ret[ri++] = matrix[i][j++];

        // up to down
        i = l;
        j = col - 1 - l;
        for (k = 0; k < cr; ++k)
            ret[ri++] = matrix[i++][j];

        // right to left
        i = row - 1 - l;
        j = col - 1 - l;
        for (k = 0; k < cc; ++k)
            ret[ri++] = matrix[i][j--];

        // down to up
        i = row - 1 - l;
        j = l;
        for (k = 0; k < cr; ++k)
            ret[ri++] = matrix[i--][j];

        cr -= 2;
        cc -= 2;
        if (cr < 0 || cc < 0)
            break;
    }

    return ret;
}

int main(int argc, char const *argv[])
{
    int* m[3];
    int* r;
    int i, j;

    int a0[] = {1};
    int a1[] = {4};
    int a2[] = {7};
    m[0] = a0;
    m[1] = a1;
    m[2] = a2;

    r = spiralOrder(m, 3, 1);
    for (i = 0; i < 3; ++i) {
        printf("%d", r[i]);
        printf(i == 2 ? "\n" : ",");
    }
    free(r);

    return 0;
}