//
// Length of Last Word
// https://leetcode.com/problems/length-of-last-word/#/description
//
#include <stdio.h>
#include <string.h>

int lengthOfLastWord(char* s)
{
    int len = 0;
    int reset = 0;
    int i, l;
    if (!s) return 0;
    for (i = 0, l = strlen(s); i < l; ++i) {
        if (s[i] == ' ') {
            reset = 1;
        } else {
            if (reset) {
                len = 0;
                reset = 0;
            }
            ++len;
        }
    }
    return len;
}

int main(int argc, char const *argv[])
{
    printf("%d\n", lengthOfLastWord("Hello world   a"));
    return 0;
}