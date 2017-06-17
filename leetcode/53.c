//
// Maximum Subarray
// https://leetcode.com/problems/maximum-subarray/#/description
//

#include <stdio.h>

int maxSubArray(int* nums, int numsSize)
{
    int cur;
    int max;
    int i;
    cur = max = nums[0];
    for (i = 1; i < numsSize; ++i) {
        if (cur < 0)
            cur = nums[i];
        else
            cur += nums[i];
        if (cur > max)
            max = cur;
    }
    return max;
}

int main(int argc, char const *argv[])
{
    int nums[] = {-2,1,-3,4,-1,2,1,-5,4};
    printf("%d\n", maxSubArray(nums, 9));
    return 0;
}