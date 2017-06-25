//
// Jump Game
// https://leetcode.com/problems/jump-game/#/description
//
#include <stdio.h>

/**
 * Back tracing from the last index, find
 * the minimum index we should reach.
 */
bool canJump(int *nums, int numsSize)
{
    int i;
    int target = numsSize - 1;

    for (i = numsSize - 2; i >= 0; --i) {
        if (nums[i] + i >= target)
            // If we can reach i, we can reach the target.
            target = i;
    }
    return target == 0;
}

int main(int argc, char const *argv[])
{
    int nums[] = {3, 2, 1, 0, 4};
    printf("%s\n", canJump(nums, 5) ? "true" : "false");
    return 0;
}