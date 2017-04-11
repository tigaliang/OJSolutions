//
// Longest Palindromic Substring
// https://leetcode.com/problems/longest-palindromic-substring/#/description
//

#include <stdio.h>
#include <string.h>

char* longestPalindrome(char* s)
{
    char ss[1001] = { 0 };
    int len = strlen(s);
    int i;
    int start0, start1, l;

    if (len == 0) {
        return (char *)"";
    }
    if (len == 1) {
        return s;
    }

    // reverse of s
    for (i = len - 1; i >= 0; --i) {
        ss[len - i - 1] = s[i];
    }

    for (l = len; l > 0; --l) {
        for (start0 = 0; start0 + l <= len; ++start0) {
            start1 = len - l - start0;
            if (strncmp(s + start0, ss + start1, l) == 0) {
                goto end;
            }
        }
    }
end:
    s[start0 + l] = '\0';
    return s + start0;
}

int main(int argc, char const *argv[])
{
    char s[] = "babad";
    printf("%s\n", longestPalindrome(s));
    return 0;
}