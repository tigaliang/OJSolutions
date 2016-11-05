//
// Product of Array Except Self
// https://leetcode.com/problems/product-of-array-except-self/
//

#include <stdio.h>
#include <stdlib.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize)
{
    *returnSize = numsSize;
    if(numsSize == 0) {
        return 0;
    }

    int* ret = (int*) malloc(numsSize * sizeof(int));

    int tmp = 1;
    for (int i = 1; i < numsSize; ++i) {
        tmp *= nums[i - 1];
        ret[i] = tmp;
    }

    ret[0] = 1;
    tmp = 1;
    for (int i = numsSize - 2; i >= 0; --i) {
        tmp *= nums[i + 1];
        ret[i] *= tmp;
    }

    return ret;
}

int main(int argc, char const *argv[])
{
    int nums[] = { 1, 2, 3, 4};
    int returnSize;

    int* ret = productExceptSelf(nums, 4, &returnSize);

    printf("%d, %d, %d, %d\n", ret[0], ret[1], ret[2], ret[3]);

    free(ret);

    return 0;
}
