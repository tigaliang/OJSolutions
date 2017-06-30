//
// Unique Paths
// https://leetcode.com/problems/unique-paths/#/description
//
#include <stdio.h>

int uniquePaths(int m, int n)
{
    int a[100][100];
    int i, j;
    if (0 == m || 0 == n)
        return 0;

    for (i = m - 1; i >= 0; --i) {
        for (j = n - 1; j >= 0; --j) {
            if (m - 1 == i || n - 1 == j)
                a[i][j] = 1;
            else
                a[i][j] = a[i + 1][j] + a[i][j + 1];
        }
    }

    return a[0][0];
}

int main(int argc, char const *argv[])
{
    printf("%d\n", uniquePaths(3, 2));
    return 0;
}