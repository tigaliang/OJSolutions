//
// Two Sum II - Input array is sorted
// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
//

#include <stdio.h>
#include <stdlib.h>

static int binarysearch(int target, int* list, int l, int r)
{
    int m;
    while (l < r) {
        m = (l + r) / 2;
        if (list[m] == target) {
            return m;
        } else if (list[m] > target) {
            r = m;
        } else {
            if (l == m) {
                return list[r] == target ? r : -1;
            }
            l = m;
        }
    }
    return list[l] == target ? l : -1;
}

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize)
{
    int* ret = (int*) malloc(2 * sizeof(int));
    *returnSize = 2;
    
    int i;
    int j;
    for (i = 0; i < numbersSize; ++i) {
        j = binarysearch(target - numbers[i], numbers, i + 1, numbersSize - 1);
        if (j > 0) break;
    }
    ret[0] = i + 1;
    ret[1] = j + 1;

    return ret;
}

int main(int argc, char const *argv[])
{
    int numbers[] = { 2, 7, 11, 15 };
    int returnSize;
    int* ret = twoSum(numbers, 4, 18, &returnSize);

    printf("ret: %d, %d\n", ret[0], ret[1]);

    free(ret);

    return 0;
}