//
// Search in Rotated Sorted Array
// https://leetcode.com/problems/search-in-rotated-sorted-array/#/description
//

#include <stdio.h>

static int mbsearch(int* nums, int begin, int end, int target)
{
    int m;

    if (begin == end) {
        if (nums[begin] == target) return begin;
        return -1;
    }

    m = begin + (end - begin) / 2;
    if (nums[m] == target) return m;
    if (m == begin) return mbsearch(nums, m + 1, end, target);

    if (nums[begin] < nums[m] && nums[m] > nums[end]) {
        if (target >= nums[begin] && target < nums[m])
            return mbsearch(nums, begin, m - 1, target);
        else
            return mbsearch(nums, m + 1, end, target);
    }

    if (nums[begin] > nums[m] && nums[m] < nums[end]) {
        if (target > nums[m] && target <= nums[end])
            return mbsearch(nums, m + 1, end, target);
        else
            return mbsearch(nums, begin, m - 1, target);
    }

    // if (nums[begin] < nums[m] && nums[m] < nums[end])
    if (target < nums[m])
        return mbsearch(nums, begin, m - 1, target);
    else
        return mbsearch(nums, m + 1, end, target);
}

int search(int* nums, int numsSize, int target)
{
    if (numsSize < 1) return -1;
    return mbsearch(nums, 0, numsSize - 1, target);
}

int main(int argc, char const *argv[])
{
    int nums[] = {5, 1, 2, 3, 4};
    printf("%d\n", search(nums, 5, 1));

    return 0;
}