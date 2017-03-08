//
// Reverse Words in a String
// https://leetcode.com/problems/reverse-words-in-a-string/?tab=Description
//

#include <stdio.h>
#include <string.h>
#include <ctype.h>

static void left_align(char *s, int start)
{
    int len;
    int ns;
    int i, j;

    len = strlen(s);
    ns = start + 1;
    while (ns < len && isspace(s[ns])) {
        ++ns;
    }

    i = start;
    j = ns;
    while (j < len) {
        s[i] = s[j];
        s[j] = ' ';
        ++i;
        ++j;
    }
}

static void trim_tail(char *s)
{
    int i;

    i = strlen(s) - 1;
    while (i >= 0 && isspace(s[i])) {
        s[i] = 0;
        --i;
    }
}

static void left_align_and_trim_tail(char *s)
{
    int i;
    int len;

    i = 0;
    len = strlen(s);
    while (i < len) {
        if (isspace(s[i])) {
            if (s[i] != ' ') {
                s[i] = ' ';
            }
            if (i + 1 < len && isspace(s[i + 1])) {
                left_align(s, i + 1);
            }
        }
        ++i;
    }

    trim_tail(s);
}

static void reverse_string(char *s, int len)
{
    int i, j;
    char tmp;
    for (i = 0, j = len - 1; i < j; ++i, --j) {
        tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
    }
}

void reverseWords(char *s)
{
    char *p;
    char *sp;
    int len;
    int i;

    left_align_and_trim_tail(s);

    len = strlen(s);
    reverse_string(s, len);

    trim_tail(s);

    len = strlen(s);
    p = s;
    while (p < s + len && (sp = strchr(p, ' '))) {
        reverse_string(p, sp - p);
        p = sp + 1;
    }
    reverse_string(p, s + len - p);
}

int main(int argc, char const *argv[])
{
    char s[] = "    the sky     is blue     ";
    reverseWords(s);
    printf("%s\n", s);
    return 0;
}
