//
// Next Permutation
// https://leetcode.com/problems/next-permutation/#/description
//

#include <stdio.h>

void nextPermutation(int* nums, int numsSize)
{
    int i, j;
    int t = -1;
    for (i = numsSize - 1; i > 0; --i) {
        if (nums[i - 1] < nums[i]) {
            t = i - 1;
            break;
        }
    }
    for (i = t + 1, j = numsSize - 1; i < j; ++i, --j) {
        // reverse
        nums[i] ^= nums[j];
        nums[j] ^= nums[i];
        nums[i] ^= nums[j];
    }
    if (t >= 0) {
        for (i = t + 1; i < numsSize; ++i) {
            if (nums[i] > nums[t]) {
                nums[i] ^= nums[t];
                nums[t] ^= nums[i];
                nums[i] ^= nums[t];
                break;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    int i;
    int nums[] = {1, 2, 5, 4, 1};
    nextPermutation(nums, 5);

    for (i = 0; i < 5; ++i) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    return 0;
}