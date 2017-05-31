//
// Multiply Strings
// https://leetcode.com/problems/multiply-strings/#/description
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUF_LEN  230
#define BUF_LEN2 112

char* multiply(char* num1, char* num2)
{
    char *ret = (char *)malloc(BUF_LEN);
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    char buf[BUF_LEN2][BUF_LEN2] = { 0 };
    int i, j, ri, k;
    int tmp;

    memset(ret, 0, BUF_LEN);

    if (num1[0] == '0' || num2[0] == '0') {
        ret[0] = '0';
        return ret;
    }

    for (i = len2 - 1; i >= 0; --i) {
        ri = len2 - i - 1;
        for (j = len1 - 1; j >= 0; --j) {
            tmp = (num2[i] - '0') * (num1[j] - '0') + buf[ri][j + 1];
            buf[ri][j + 1] = tmp % 10;
            buf[ri][j] = tmp / 10;
        }
    }

    /*for (i = 0; i < 10; ++i) {
        printf("%c", buf[0][i] + '0');
    }
    printf("\n");
    for (i = 0; i < 10; ++i) {
        printf("%c", buf[1][i] + '0');
    }
    printf("\n");
    for (i = 0; i < 10; ++i) {
        printf("%c", buf[2][i] + '0');
    }
    printf("\n");*/

    for (i = len1; i >= 0 - (len2 - 1); --i) {
        tmp = 0;
        for (j = 0; j < len2; ++j) {
            ri = j + i;
            if (ri < 0) continue;
            if (ri > len1) break;
            tmp += buf[j][ri];
        }
        k = i + len2;
        // printf("tmp: %d, ret[k]: %d\n", tmp, ret[k]);
        tmp += ret[k];
        ret[k] = tmp % 10;
        ret[k - 1] = tmp / 10;
    }

    /*for (i = 0; i < 10; ++i) {
        printf("%d,", ret[i]);
    }
    printf("\n");*/

    for (i = 0; i < BUF_LEN; ++i) {
        if (ret[i]) break;
    }

    k = len1 + len2;
    for (j = i; j <= k; ++j) {
        ret[j] += '0';
    }

    return ret + i;
}

int main(int argc, char const *argv[])
{
    char num1[] = "408";
    char num2[] = "5";
    printf("%s\n", multiply(num1, num2));
    return 0;
}