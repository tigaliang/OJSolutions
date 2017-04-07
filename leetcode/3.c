//
// Longest Substring Without Repeating Characters
// https://leetcode.com/problems/longest-substring-without-repeating-characters/#/description
//

#include <stdio.h>
#include <string.h>

int lengthOfLongestSubstring(const char* s)
{
    int maxlen;
    int l, i, j;
    int r[256] = { 0 };

    l = strlen(s);
    if (l < 2) {
        return l;
    }

    i = 0;
    r[s[i]] = 1;
    j = 1;
    r[s[j]] += 1;
    maxlen = 1;
    while (true) {
        if (r[s[j]] > 1) {
            maxlen = maxlen > (j - i) ? maxlen : (j - i);
            r[s[i]] -= 1;
            ++i;
        } else {
            ++j;
            if (j == l) {
                maxlen = maxlen > (j - i) ? maxlen : (j - i);
                break;
            }
            r[s[j]] += 1;
        }
    }

    return maxlen;
}

int main(int argc, char const *argv[])
{
    printf("%d\n", lengthOfLongestSubstring("bbbbb"));
    return 0;
}