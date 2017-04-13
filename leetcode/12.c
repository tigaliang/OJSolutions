//
// Integer to Roman
// https://leetcode.com/problems/integer-to-roman/#/description
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static void fill(int n, char ch10, char ch5, char ch1, char *buf, int c)
{
    int i;
    if (n == 9) {
        buf[c++] = ch1;
        buf[c++] = ch10;
    } else if (n >= 5) {
        buf[c++] = ch5;
        n -= 5;
        for (i = 0; i < n; ++i) {
            buf[c++] = ch1;
        }
    } else if (n == 4) {
        buf[c++] = ch1;
        buf[c++] = ch5;
    } else {
        for (i = 0; i < n; ++i) {
            buf[c++] = ch1;
        }
    }
}

char* intToRoman(int num)
{
    int k, h, t, n;
    char *buf;

    buf = (char *)malloc(100);
    memset(buf, 0, 100);

    k = num / 1000;
    num %= 1000;
    h = num / 100;
    num %= 100;
    t = num / 10;
    num %= 10;
    n = num;

    fill(k, '\0', '\0', 'M', buf, strlen(buf));
    fill(h, 'M', 'D', 'C', buf, strlen(buf));
    fill(t, 'C', 'L', 'X', buf, strlen(buf));
    fill(n, 'X', 'V', 'I', buf, strlen(buf));

    return buf;
}

int main(int argc, char const *argv[])
{
    printf("%s\n", intToRoman(1984));
    return 0;
}