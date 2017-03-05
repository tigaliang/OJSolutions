//
// Divide Two Integers
// https://leetcode.com/problems/divide-two-integers/?tab=Description
//

#include <stdio.h>

/**
 * Deternmine the n-th(from right to left, indexed from 0) bit
 * of num is 1 or 0
 */
int bit0or1(int num, int n) {
    int mask = 1 << n;
    return ((num | mask) == num) ? 1 : 0;
}

/**
 * Return dividend / divisor
 */
int divide(int dividend, int divisor)
{
    int bits = sizeof(int) * 8;
    unsigned int ret = 0;
    unsigned int remainder = 0;
    unsigned int dividend_tmp;
    unsigned int divisor_tmp;
    int real_ret;

    if (dividend == 0) {
        return 0;
    }

    dividend_tmp = (dividend < 0) ? -dividend : dividend;
    divisor_tmp = (divisor < 0) ? -divisor : divisor;

    while (bits--) {
        remainder += bit0or1(dividend_tmp, bits);
        if (remainder >= divisor_tmp) {
            ret = (ret << 1) + 1;
            remainder = (remainder - divisor_tmp) << 1;
        } else {
            ret <<= 1;
            remainder <<= 1;
        }
    }

    real_ret = ret;
    if ((dividend < 0 && divisor > 0)
        || (dividend > 0 && divisor < 0)) {
        return -real_ret;
    }

    if (ret == 0x80000000) {
        return 0x7FFFFFFF;
    }

    return real_ret;
}

int main(int argc, char const *argv[])
{
    printf("%d\n", divide(-2147483648, 1));
}
