//
// Decode Ways
// https://leetcode.com/problems/decode-ways/#/description
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int numDecodings(char* s)
{
    int l;
    int i;
    int n;
    int *r;

    l = strlen(s);
    if (l == 0) {
        return 0;
    }
    if (s[0] == '0') {
        return 0;
    }
    if (l == 1) {
        return 1;
    }

    r = (int *)malloc((l + 1) * sizeof(int));

    r[0] = 1;
    r[1] = 1;
    for (i = 2; i <= l; ++i) {
        n = 0;
        if (s[i - 1] != '0') {
            n += r[i - 1];
        }
        if (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] <= '6')) {
            n += r[i - 2];
        }
        r[i] = n;
    }

    return r[l];
}

int main(int argc, char const *argv[])
{
    printf("%d\n", numDecodings("10"));
    return 0;
}