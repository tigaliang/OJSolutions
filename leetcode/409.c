//
// Longest Palindrome
// https://leetcode.com/problems/longest-palindrome/#/description
//

#include <stdio.h>
#include <string.h>

int longestPalindrome(const char* s)
{
    int arr[52] = { 0 };
    int i, l;
    int singles_num;

    l = strlen(s);
    if (l == 0) {
        return 0;
    }

    for (i = 0; i < l; ++i) {
        if (s[i] < 'a') {
            arr[s[i] - 'A'] += 1;
        } else {
            arr[s[i] - 'a' + 26] += 1;
        }
    }

    singles_num = 0;
    for (i = 0; i < 52; ++i) {
        if (arr[i] % 2) {
            singles_num += 1;
        }
    }

    return l - singles_num + (singles_num > 0 ? 1 : 0);
}

int main(int argc, char const *argv[])
{
    printf("%d\n", longestPalindrome("aa"));
    return 0;
}