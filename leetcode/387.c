//
// First Unique Character in a String
// https://leetcode.com/problems/first-unique-character-in-a-string/#/description
//

#include <stdio.h>

int firstUniqChar(char* s)
{
    int len;
    int a[26] = { 0 };
    int i;

    for (i = 0, len = strlen(s); i < len; ++i) {
        a[s[i] - 'a'] += 1;
    }
    
    for (i = 0; i < len; ++i) {
        if (a[s[i] - 'a'] == 1) {
            return i;
        }
    }

    return -1;
}

int main(int argc, char const *argv[])
{
    printf("%d\n", firstUniqChar("loveleetcode"));
    return 0;
}