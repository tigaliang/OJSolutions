//
// Implement strStr()
// https://leetcode.com/problems/implement-strstr/#/description
//
#include <stdio.h>

int strStr(char* haystack, char* needle)
{
    int i, j;
    if (!(haystack && needle)) return -1;
    if (haystack[0] == '\0' && needle[0] == '\0') return 0;
    for (i = 0; haystack[i] != '\0'; ++i) {
        for (j = 0;;++j) {
            if (needle[j] == '\0') return i;
            if (haystack[i + j] != needle[j]) break;
        }
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    char a[] = "abcd";
    char b[] = "e";
    printf("%d\n", strStr(a, b));
    return 0;
}