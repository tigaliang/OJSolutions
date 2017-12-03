//
// 738. Monotone Increasing Digits
// https://leetcode.com/contest/weekly-contest-61/problems/monotone-increasing-digits/
//
#include <stdio.h>

int monotoneIncreasingDigits(int N)
{
    int current_digit, last_digit;
    int n = N;
    int r = 0;
    int current_base = 1;

    last_digit = -1;
    while (n) {
        current_digit = n % 10;

        if (last_digit != -1 && current_digit > last_digit) {
            r = current_digit * current_base - 1;
            current_digit -= 1;
        } else
            r = r + current_digit * current_base;

        last_digit = current_digit;
        n /= 10;
        current_base *= 10;
    }

    return r;
}

int main(int argc, char const *argv[])
{
    printf("%d\n", monotoneIncreasingDigits(332));
    return 0;
}