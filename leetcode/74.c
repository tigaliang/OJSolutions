//
// Search a 2D Matrix
// https://leetcode.com/problems/search-a-2d-matrix/description/
//
#include <stdio.h>

static int C;

#define R(i) (i / C)
#define C(i) (i % C)
#define I(r, c) (r * C + c)

static int binarysearch(int target, int** list, int l, int r)
{
    int m, tt;

    while (l < r) {
        m = (l + r) / 2;
        tt = list[R(m)][C(m)];
        if (tt == target) {
            return m;
        } else if (tt > target) {
            r = m;
        } else {
            if (l == m) {
                return list[R(r)][C(r)] == target ? r : -1;
            }
            l = m;
        }
    }

    return list[R(l)][C(l)] == target ? l : -1;
}

bool searchMatrix(int** m, int r, int c, int t)
{
    C = c;
    if (!r || !c) return false;
    return -1 == binarysearch(t, m, 0, r * c -1) ? false : true;
}

int main(int argc, char const *argv[])
{
    int r0[] = {1, 3, 4, 7};
    int r1[] = {8, 10, 11, 14};
    int r2[] = {21, 22, 24, 50};
    int* g[3];
    g[0] = r0;
    g[1] = r1;
    g[2] = r2;

    printf("%s\n", searchMatrix(g, 3, 4, 51) ? "true" : "false");

    return 0;
}