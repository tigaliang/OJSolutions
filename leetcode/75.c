//
// Sort Colors
// https://leetcode.com/problems/sort-colors/description/
//
#include <stdio.h>

void sortColors(int* nums, int numsSize)
{
    int i, j;
    int k;

    if (0 == numsSize)
        return;

    i = 0;
    j = numsSize - 1;

    for (k = 0; k <= j; ++k) {
        if (0 == nums[k]) {
            while (0 == nums[i]) ++i;
            if (i >= k)
                continue;
            nums[k] = nums[i];
            nums[i] = 0;
            ++i;
        } else if (2 == nums[k]) {
            while (2 == nums[j]) --j;
            if (j <= k)
                continue;
            nums[k] = nums[j];
            nums[j] = 2;
            --j;
            if (0 == nums[k])
                --k;
        }
    }
}

int main(int argc, char const *argv[])
{
    int i;
    int nums[] = {2, 1, 2};

    sortColors(nums, sizeof(nums) / sizeof(int));

    for (i = 0; i < sizeof(nums) / sizeof(int); ++i)
        printf("%d ", nums[i]);

    return 0;
}