//
// Simplify Path
// https://leetcode.com/problems/simplify-path/description/
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* simplifyPath(char* path)
{
    char* ret = NULL;
    int len = strlen(path);
    char *next, *cur;
    int idx;

    if (0 == len)
        goto out;
    ret = (char *)malloc(len + 1);
    memset(ret, 0, len + 1);

    idx = 0;
    ret[idx++] = '/';
    if (1 == len)
        goto out;
    cur = path + 1;
    while (true) {
        // skip redundant slashes
        while (cur - path <= len - 1 && (*cur) == '/')
            ++cur;
        if (cur - path == len)
            break;

        next = strchr(cur, '/');
        if (next)
            *next = '\0';

        if (0 == strcmp(cur, "."))
            goto con;
        if (0 == strcmp(cur, "..")) {
            if (1 == idx) {
                goto con;
            } else {
                --idx;
                while (ret[idx] != '/') {
                    ret[idx] = '\0';
                    --idx;
                }
                if (0 == idx)
                    idx = 1;
                else
                    ret[idx] = '\0';
            }
        } else {
            if (idx > 1)
                ret[idx++] = '/';
            strcpy(ret + idx, cur);
            idx += strlen(cur);
        }
con:
        if (!next)
            break;
        cur = next + 1;
    }

out:
    return ret;
}

int main(int argc, char const *argv[])
{
    char path[] = "/abc/../aaa/.";
    printf("%s\n", simplifyPath(path));
    return 0;
}