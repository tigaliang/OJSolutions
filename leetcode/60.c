//
// Permutation Sequence
// https://leetcode.com/problems/permutation-sequence/#/description
//

#include <stdio.h>
#include <stdlib.h>

char* getPermutation(int n, int k)
{
    char *r = (char *)malloc(n + 1);
    int g, gs, i;
    char *p;
    char tmp;

    for (i = 0; i < n; ++i)
        r[i] = '1' + i;
    r[n] = '\0';

    p = r;
    while (n) {
        gs = 1;
        for (i = n - 1; i; --i)
            gs *= i;

        g = (k - 1) / gs;
        tmp = p[g];
        for (i = g; i; --i)
            p[i] = p[i - 1];
        p[0] = tmp;

        k -= gs * g;
        if (1 == k)
            break;
        --n;
        ++p;
    }

    return r;
}

int main(int argc, char const *argv[])
{
    char *r = getPermutation(9, 54494);
    printf("%s\n", r);
    free(r);

    return 0;
}