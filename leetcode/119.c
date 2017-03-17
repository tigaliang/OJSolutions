//
// Pascal's Triangle II
// https://leetcode.com/problems/pascals-triangle-ii/#/description
//

#include <stdio.h>

/**
* Return an array of size *returnSize.
* Note: The returned array must be malloced, assume caller calls free().
*/
/*int* getRow(int rowIndex, int* returnSize) {
    int* ret[2];
    int i, j;
    int which;
    int left, right;
    
    *returnSize = rowIndex + 1;
    ret[0] = (int *)malloc(sizeof(int) * (*returnSize));
    ret[1] = (int *)malloc(sizeof(int)* (*returnSize));

    ret[0][0] = 1;
    which = 1;
    for (i = 2; i <= *returnSize; ++i) {
        for (j = 0; j < i; ++j) {
            left = (j == 0) ? 0 : ret[(which + 1) % 2][j - 1];
            right = (j == i - 1) ? 0 : ret[(which + 1) % 2][j];
            ret[which][j] = left + right;
        }
        which = (which + 1) % 2;
    }

    if (rowIndex % 2) {
        free(ret[0]);
        return ret[1];
    }
    free(ret[1]);
    return ret[0];
}*/

int* getRow(int rowIndex, int* returnSize) {
    int i, j;
    int* ret;
    
    *returnSize = rowIndex + 1;
    ret = (int *)malloc(sizeof(int) * (rowIndex + 1));
    memset(ret, 0, sizeof(int) * (rowIndex + 1));

    ret[0] = 1;
    for (i = 1; i < rowIndex + 1; ++i) {
        for (j = i; j > 0; --j) {
            ret[j] += ret[j - 1];
        }
    }

    return ret;
}

int main(int argc, char* argv[])
{
    int size;
    int* row = getRow(6, &size);
    int i;
    for (i = 0; i < size; ++i) {
        if (i != 0) printf(", ");
        printf("%d", row[i]);
    }
    printf("\n");

    return 0;
}
