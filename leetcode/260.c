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

    ret[0] = 0;
    ret[1] = 0;
    for (i = 0; i < numsSize; ++i) {
        if (nums[i] & mask) {
            ret[0] ^= nums[i];
        } else {
            ret[1] ^= nums[i];
        }
    }

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