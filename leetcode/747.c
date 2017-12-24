//
// Largest Number Greater Than Twice of Others
// https://leetcode.com/contest/weekly-contest-64/problems/largest-number-greater-than-twice-of-others/
//
#include <stdio.h>

int dominantIndex(int* nums, int numsSize)
{
    int max = 0;
    int max2nd = -1;
    int i;

    for (i = 1; i < numsSize; ++i) {
        if (nums[i] > nums[max]) {
            max2nd = max;
            max = i;
        } else if (max2nd == -1 || nums[i] > nums[max2nd])
            max2nd = i;
    }

    if ((long long)nums[max] >= (long long)nums[max2nd] * 2)
        return max;
    return -1;
}

int main(int argc, char const *argv[])
{
    int nums[] = {1, 0, 0, 0};
    printf("%d\n", dominantIndex(nums, 4));
    return 0;
}