//
// Climbing Stairs
// https://leetcode.com/problems/climbing-stairs/#/description
//

#include <stdio.h>
#include <stdlib.h>

int climbStairs(int n)
{
    int i;
    int *a;
    int s;

    if (1 == n)
        return 1;
    if (2 == n)
        return 2;

    a = (int *)malloc(n * sizeof(int));
    a[n - 1] = 1;
    a[n - 2] = 2;
    for (i = n - 3; i >= 0; --i) {
        a[i] = a[i + 1] + a[i + 2];
    }

    s = a[0];
    free(a);

    return s;
}

int main(int argc, char const *argv[])
{
    printf("%d\n", climbStairs(5));
    return 0;
}