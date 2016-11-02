//
// Single Number III
// https://leetcode.com/problems/single-number-iii/
//

#include <stdio.h>
#include <stdlib.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* singleNumber(int* nums, int numsSize, int* returnSize) {
    if (numsSize < 1) {
        *returnSize = 0;
        return 0;
    }

    *returnSize = 2;
    int* ret = (int*) malloc(2 * sizeof(int));
    
    int i;
    int xorret = nums[0];
    for (i = 1; i < numsSize; ++i) {
        xorret ^= nums[i];
    }

    int mask = 1;
    while (!(xorret & mask)) mask = mask << 1;

    int* arr1 = (int*) malloc(numsSize * sizeof(int));
    int len1 = 0;
    int* arr2 = (int*) malloc(numsSize * sizeof(int));
    int len2 = 0;
    for (i = 0; i < numsSize; ++i) {
        if (nums[i] & mask) {
            arr1[len1++] = nums[i];
        } else {
            arr2[len2++] = nums[i];
        }
    }

    ret[0] = arr1[0];
    for (i = 1; i < len1; ++i) {
        ret[0] ^= arr1[i];
    }

    ret[1] = arr2[0];
    for (i = 1; i < len2; ++i) {
        ret[1] ^= arr2[i];
    }

    free(arr1);
    free(arr2);

    return ret;
}

int main(int argc, char const *argv[])
{
    int nums[] = {1, 2, 1, 3, 2, 5};
    int* returnSize;
    int* ret = singleNumber(nums, 6, returnSize);
    printf("[%d, %d]\n", ret[0], ret[1]);

    return 0;
}