//
// Search for a Range
// https://leetcode.com/problems/search-for-a-range/#/description
//

#include <stdio.h>
#include <stdlib.h>

static int dosearch(int* nums, int begin ,int end, int target, int what)
{
    int m;

    if (begin == end) {
        if (nums[begin] == target) return begin;
        else return -1;
    }

    m = begin + (end - begin) / 2;
    if (nums[m] == target) {
        if (what == 0) {
            if (m > begin && nums[m - 1] == target) {
                return dosearch(nums, begin, m - 1, target, 0);
            } else {
                return m;
            }
        } else {
            if (m < end && nums[m + 1] == target) {
                return dosearch(nums, m + 1, end, target, 1);
            } else {
                return m;
            }
        }
    } else if (nums[m] > target) {
        if (m > begin) return dosearch(nums, begin, m - 1, target, what);
        else return -1;
    } else { // if (nums[m] < target)
        if (m < end) return dosearch(nums, m + 1, end, target, what);
        else return -1;
    }
}

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize)
{
    int *r = (int *)malloc(sizeof(int) * 2);
    *returnSize = 2;

    r[0] = dosearch(nums, 0, numsSize - 1, target, 0);
    r[1] = dosearch(nums, 0, numsSize - 1, target, 1);

    return r;
}

int main(int argc, char const *argv[])
{
    int nums[] = {5, 7, 7, 8, 8, 10};
    int returnSize;
    int *ret = searchRange(nums, 6, 8, &returnSize);
    printf("%d, %d\n", ret[0], ret[1]);
    return 0;
}