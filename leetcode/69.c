//
// Sqrt(x)
// https://leetcode.com/problems/sqrtx/#/description
//

#include <stdio.h>

int mySqrt(int n)
{
    // Newton–Raphson method
    double x;
    double r;

    if (0 == n)
        return 0;

    x = 1.0;
    do {
        r = (double)((int) x);
        if (r * r - n > 0 && (r - 1) * (r - 1) - n <= 0) {
            r = r - 1;
            break;
        }
        if (r * r - n <= 0 && (r + 1) * (r + 1) - n > 0)
            break;

        x = (x * x + n) / (2 * x);
    } while (1);

    return r;
}

int main(int argc, char const *argv[])
{
    printf("%d\n", mySqrt(2147395599));
    return 0;
}