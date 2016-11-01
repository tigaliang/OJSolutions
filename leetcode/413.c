//
// Arithmetic Slices
// https://leetcode.com/problems/arithmetic-slices/
//

#include <stdio.h>

static inline int nsubslices(int l) {
    return (l - 1) * (l - 2) / 2;
}

int numberOfArithmeticSlices(int* A, int ASize) {
    int n = 0;
    int l = 2;
    for (int i = 2; i < ASize; ++i) {
        if (A[i] - A[i - 1] == A[i - 1] - A[i - 2]) {
            ++l;
        } else {
            n += nsubslices(l);
            l = 2;
        }
    }
    n += nsubslices(l);

    return n;
}

int main(int argc, char** argv) {
    int A[] = { 1, 2, 3 };
    printf("n = %d\n", numberOfArithmeticSlices(A, 3));
    return 0;
}