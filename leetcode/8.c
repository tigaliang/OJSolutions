//
// https://leetcode.com/problems/string-to-integer-atoi/#/description
// String to Integer (atoi)
//

#include <stdio.h>
#include <string.h>
#include <limits.h>

int myAtoi(char* str)
{
    long long ret;
    int neg;
    int i, len;

    len = strlen(str);
    if (!str || len == 0) {
        return 0;
    }

    for (i = 0; i < len; ++i) {
        if (!isspace(str[i])) {
            break;
        }
    }

    ret = 0;
    neg = str[i] == '-';
    if (neg || str[i] == '+') i += 1; 

    for (; i < len && str[i] >= '0' && str[i] <= '9'; ++i) {
        ret = ret * 10 + str[i] - '0';
        if (neg && ret > (long long)INT_MAX + 1) {
            ret = (long long)INT_MAX + 1;
            break;
        } else if (!neg && ret > (long long)INT_MAX) {
            ret = (long long)INT_MAX;
        }
    }

    if (neg) ret *= -1;

    return (int)ret;
}

int main(int argc, char* argv[])
{
    printf("%d\n", myAtoi("-123"));
    return 0;
}