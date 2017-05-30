//
// Search Insert Position
// https://leetcode.com/problems/search-insert-position/#/description
//

#include <stdio.h>

static int dosearch(int *nums, int begin, int end, int target)
{
    int m;

    if (begin == end) {
        if (nums[begin] >= target) return begin;
        return begin + 1;
    }

    m = begin + (end - begin) / 2;
    if (nums[m] == target) return m;
    if (nums[m] < target && nums[m + 1] > target) return m + 1;

    if (target < nums[m]) {
        if (m > begin) return dosearch(nums, begin, m - 1, target);
        return begin;
    } else {
        return dosearch(nums, m + 1, end, target);
    }
}

int searchInsert(int* nums, int numsSize, int target)
{
    if (numsSize == 0) return 0;
    return dosearch(nums, 0, numsSize - 1, target);
}

int main(int argc, char const *argv[])
{
    int a[] = {1, 3, 5, 6};
    printf("%d\n", searchInsert(a, 4, 7));
    return 0;
}