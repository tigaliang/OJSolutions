//
// Add Binary
// https://leetcode.com/problems/add-binary/#/description
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* addBinary(char* a, char* b)
{
    char *sum, *tsum;
    int la, lb;
    int i, j;
    int flag;
    int s;

    la = strlen(a);
    lb = strlen(b);

    sum = (char *)malloc((la > lb ? la : lb) + 1);

    i = la - 1;
    j = lb - 1;
    sum[la > lb ? la : lb] = '\0';
    flag = 0;
    for (; i >= 0 || j >= 0; --i, --j) {
        s = 0;
        if (i >= 0)
            s += a[i] - '0';
        if (j >= 0)
            s += b[j] - '0';
        s += flag;
        sum[i > j ? i : j] = s % 2 + '0';
        flag = s / 2;
    }

    if (flag) {
        tsum = (char *)malloc((la > lb ? la : lb) + 2);
        tsum[0] = '1';
        tsum[(la > lb ? la : lb) + 1] = '\0';
        strcpy(tsum + 1, sum);
        free(sum);
        sum = tsum;
    }

    return sum;
}

int main(int argc, char const *argv[])
{
    printf("%s\n", addBinary("10000011", "111000"));
    return 0;
}