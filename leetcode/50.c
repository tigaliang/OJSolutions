//
// Pow(x, n)
// https://leetcode.com/problems/powx-n/#/description
//
#include <stdio.h>

double doPow(double x, int n)
{
    double r;

    if (n == 0)
        return 1.0;
    if (n == 1)
        return x;
    r = doPow(x, n / 2);
    if (n % 2)
        return r * r * x;
    return r * r;
}

double myPow(double x, int n)
{
    if (x == 0)
        return 0;
    if (n < 0)
        return 1 / doPow(x, -n);
    return doPow(x, n);
}

int main(int argc, char const *argv[])
{
    printf("pow: %lf\n", myPow(3.1, -3));

    return 0;
}
