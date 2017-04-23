//
// Longest Common Prefix
// https://leetcode.com/problems/longest-common-prefix/#/description
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* longestCommonPrefix(char** strs, int strsSize)
{
    char *pre;
    int len;
    int i;
    int l;

    if (strsSize == 0) {
        len = 0;
        goto ret;
    }

    len = strlen(strs[0]);
    for (i = 1; i < strsSize; ++i) {
        l = strlen(strs[i]);
        len = l < len ? l : len;
    }

    while (len) {
        for (i = 1; i < strsSize; ++i) {
            if (strncmp(strs[0], strs[i], len)) break;
        }
        if (i == strsSize) break;
        --len;
    }

ret:
    pre = (char *)malloc(len + 1);
    strncpy(pre, strs[0], len);
    pre[len] = '\0';

    return pre;
}

int main(int argc, char const *argv[])
{
    char* strs[] = {"abc", "abcd"};
    printf("%s\n", longestCommonPrefix(strs, 2));
    return 0;
}