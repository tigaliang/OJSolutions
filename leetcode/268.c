//
// https://leetcode.com/problems/missing-number/#/description
// Missing Number
//

#include <stdio.h>

int missingNumber(int* nums, int numsSize)
{
    int i;
    int ret = 0;
    for (i = 0; i < numsSize; ++i) {
        ret ^= nums[i];
    }
    for (i = 0; i <= numsSize; ++i) {
        ret ^= i;
    }
    return ret;
}

int main(int argc, char const *argv[])
{
    int nums[] = {2, 1, 0};

    printf("%d\n", missingNumber(nums, 3));
    return 0;
}