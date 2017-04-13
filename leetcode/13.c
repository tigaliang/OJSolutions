//
// Roman to Integer
// https://leetcode.com/problems/roman-to-integer/#/description
//

#include <stdio.h>
#include <string.h>

int romanToInt(const char* s)
{
    int m[26];
    int l, i;
    int sum;
    int cur;

    m['I' - 'A'] = 1;
    m['V' - 'A'] = 5;
    m['X' - 'A'] = 10;
    m['L' - 'A'] = 50;
    m['C' - 'A'] = 100;
    m['D' - 'A'] = 500;
    m['M' - 'A'] = 1000;

    sum = 0;
    l = strlen(s);
    sum += m[s[l - 1] - 'A'];
    for (i = l - 2; i >= 0; --i) {
        cur = m[s[i] - 'A'];
        sum += cur < m[s[i + 1] - 'A'] ? -cur : cur;
    }

    return sum;
}

int main(int argc, char const *argv[])
{
    printf("%d\n", romanToInt("MMMCMXCIX"));
    return 0;
}