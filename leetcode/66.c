//
// Plus One
// https://leetcode.com/problems/plus-one/#/description
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize)
{
    int i;
    int t;
    int d;
    int *ret;

    if (digitsSize <= 0)
        return NULL;

    t = 1;
    for (i = digitsSize - 1; i >= 0; --i) {
        d = digits[i] + t;
        digits[i] = d % 10;
        t = d / 10;
    }

    ret = (int *)malloc((digitsSize + t) * sizeof(int));
    if (t) {
        ret[0] = t;
    }
    memcpy(ret + t, digits, digitsSize * sizeof(int));
    *returnSize = digitsSize + t;

    return ret;
}

int main(int argc, char const *argv[])
{
    int digits[] = {9, 9, 0};
    int rs;
    int *r = plusOne(digits, 3, &rs);
    int i;
    for (i = 0; i < rs; ++i)
        printf("%d", r[i]);
    printf("\n");
    free(r);
    return 0;
}