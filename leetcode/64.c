//
// Minimum Path Sum
// https://leetcode.com/problems/minimum-path-sum/#/description
//

#include <stdio.h>
#include <stdlib.h>

#define mymin(x, y) ((x) < (y) ? (x) : (y))

int minPathSum(int** g, int r, int c)
{
    int i, j;
    int l = 0;
    int **t;

    if (r < 1 || c < 1)
        return 0;

    t = (int **)malloc(r * sizeof(int *));
    for (i = 0; i < r; ++i)
        t[i] = (int *)malloc(c * sizeof(int));

    for (i = 0; i < r; ++i) {
        for (j = 0; j < c; ++j) {
            if (i == 0 && j == 0)
                t[i][j] = g[i][j];
            else if (i == 0)
                t[i][j] = g[i][j] + t[i][j - 1];
            else if (j == 0)
                t[i][j] = g[i][j] + t[i - 1][j];
            else
                t[i][j] = g[i][j] + mymin(t[i - 1][j], t[i][j - 1]);
        }
    }

    l = t[r - 1][c - 1];

    for (i = 0; i < r; ++i)
        free(t[i]);
    free(t);

    return l;
}

int main(int argc, char const *argv[])
{
    int r0[] = {1,7,4,3,2,2,2,9,2,6};
    int r1[] = {3,6,6,1,0,5,9,6,3,8};
    int r2[] = {1,5,4,5,3,8,7,2,5,6};
    int* g[3];
    g[0] = r0;
    g[1] = r1;
    g[2] = r2;

    printf("%d\n", minPathSum(g, 3, 10));

    // [[],[],[],[5,7,6,9,0,8,1,4,7,5],[0,2,1,9,5,3,6,5,9,9],[5,3,6,1,8,9,0,7,4,7],[6,9,4,2,0,6,0,3,2,9],[8,3,3,1,2,9,5,8,6,6],[9,1,9,5,4,7,6,4,5,0],[4,1,1,8,5,1,7,5,4,9],[6,4,4,9,8,8,8,5,8,4],[1,7,7,3,2,4,0,9,8,7],[1,4,0,3,5,5,4,2,2,1],[3,0,5,8,0,3,6,0,0,5],[7,2,4,6,5,7,0,7,8,1],[7,9,5,7,4,0,5,1,4,9],[2,8,0,9,8,2,5,6,2,5],[3,9,9,8,6,4,7,8,4,5],[9,1,6,5,0,3,5,5,4,0]]

    return 0;
}