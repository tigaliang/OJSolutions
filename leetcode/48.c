//
// Rotate Image
// https://leetcode.com/problems/rotate-image/#/description
//
#include <stdio.h>

void rotate(int** matrix, int r, int c)
{
    int i, j;
    int curi, curj;
    int nexti, nextj;
    int n = 0;
    int round;
    int tmp[2];
    int ti = 0;

    for (n = 0; n < r / 2; ++n) {
        i = n;
        for (j = n; j < r - 1 - n; ++j) {
            curi = i;
            curj = j;
            round = 4;
            tmp[ti % 2] = matrix[curi][curj];
            while (round--) {
                nexti = curj;
                nextj = r - 1 - curi;
                tmp[(++ti) % 2] = matrix[nexti][nextj];
                matrix[nexti][nextj] = tmp[(++ti) % 2];
                ++ti;
                curi = nexti;
                curj = nextj;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    int r0[4] = {1, 2, 3, 4};
    int r1[4] = {5, 6, 7, 8};
    int r2[4] = {9, 10, 11, 12};
    int r3[4] = {13, 14, 15, 16};
    int* matrix[4];
    int i, j;
    int r = 4;

    matrix[0] = r0;
    matrix[1] = r1;
    matrix[2] = r2;
    matrix[3] = r3;

    rotate(matrix, 4, 4);

    for (i = 0; i < r; ++i) {
        for (j = 0; j < r; ++j) {
            printf("%d,", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}