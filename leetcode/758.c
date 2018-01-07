//
// Bold Words in String
// https://leetcode.com/contest/weekly-contest-66/problems/bold-words-in-string/
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *mystrstr(const char *s1, const char *s2, int *l)
{
    size_t l1, l2;

    l2 = strlen(s2);
    if (!l2) {
        *l = l2;
        return (char *)s1;
    }
    l1 = strlen(s1);
    while (l1 >= l2) {
        l1--;
        if (!memcmp(s1, s2, l2)) {
            *l = l2;
            return (char *)s1;
        }
        s1++;
    }
    return NULL;
}

char* boldWords(char** words, int wordsSize, char* S)
{
    int i, l;
    int s = strlen(S);
    char *m = (char *)malloc(s);
    char *f;
    int npt = 0;
    int flag = 0;
    char *r;
    int j;

    memset(m, 0, s);

    for (i = 0; i < wordsSize; ++i) {
        for (j = 0; j < s; ++j){
            f = mystrstr(S + j, words[i], &l);
            if (f)
                memset(f - S + m, 1, l);
        }
    }

    for (i = 0; i < s; ++i) {
        if (m[i] && !flag) {
            flag = 1;
            npt += 1;
        }
        if (!m[i])
            flag = 0;
    }

    for (i = 0; i < s; ++i)
        printf("%d", m[i]);
    printf("\n");

    r = (char *)malloc(7 * npt + 1 + s);
    r[7 * npt + s] = 0;

    j = 0;
    flag = 0;
    for (i = 0; i < s; ++i) {
        if (m[i]) {
            if (!flag) {
                flag = 1;
                r[j++] = '<';
                r[j++] = 'b';
                r[j++] = '>';
            }
        }
        if (!m[i] && flag) {
            flag = 0;
            r[j++] = '<';
            r[j++] = '/';
            r[j++] = 'b';
            r[j++] = '>';
        }
        r[j++] = S[i];
    }
    if (flag) {
        r[j++] = '<';
        r[j++] = '/';
        r[j++] = 'b';
        r[j++] = '>';
    }

    return r;
}

int main(int argc, char const *argv[])
{
    char *words[] = {"ccb","b","d","cba","dc"};
    printf("%s\n", boldWords(words, 5, "eeaadadadc"));
    return 0;
}