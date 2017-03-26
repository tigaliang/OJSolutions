//
// https://leetcode.com/problems/hamming-distance/
// Hamming Distance
//

#include <stdio.h>

int hammingDistance(int x, int y)
{
    int i;
    int tmp = x ^ y;
    int ret = 0;
    int mask = 1;

    for (i = 0; i < 32; ++i) {
        ret += ((tmp & (mask << i)) ? 1 : 0);
    }

    return ret;
}

int main(int argc, char const *argv[])
{
    printf("%d\n", foo(1, 4));
    return 0;
}