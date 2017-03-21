//
// https://leetcode.com/problems/count-and-say/#/description
// Count and Say
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* countAndSay(int n)
{
#define BUF_SIZE 4096
    char buf1[BUF_SIZE] = { 0 };
    char buf2[BUF_SIZE] = { 0 };
    char *cur, *pre;
    char *tmp;
    int i, len;
    int num;

    buf1[0] = '1';
    cur = buf1;
    pre = buf2;

    while (--n) {
        // swap buffer
        tmp = cur;
        cur = pre;
        pre = tmp;

        memset(cur, 0, BUF_SIZE);
        len = strlen(pre);

        num = 0;
        for (i = 0; i < len; ++i) {
            ++num;
            if (i == len - 1 || pre[i] != pre[i + 1]) {
                sprintf(cur + strlen(cur), "%d%c", num, pre[i]);
                num = 0;
            }
        }
    }

    len = strlen(cur);
    pre = (char *)malloc(len + 1);
    strncpy(pre, cur, len);
    pre[len] = '\0';
    
    return pre;
}

int main(int argc, const char* argv[])
{
    printf("%s\n", countAndSay(6));
    return 0;
}