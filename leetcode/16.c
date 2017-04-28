//
// 3Sum Closest
// https://leetcode.com/problems/3sum-closest/#/description
//

#include <stdio.h>

static int numsSize;
static void quick_sort(int* nums, int begin, int end)
{
    int pivot = nums[begin];
    int begin_orgin, end_orgin;
    begin_orgin = begin;
    end_orgin = end;

    while (true) {
        while (begin < end && nums[end] >= pivot) --end;
        if (begin == end) break;
        nums[begin++] = nums[end];
        while (begin < end && nums[begin] <= pivot) ++begin;
        if (begin == end) break;
        nums[end--] = nums[begin];
    }

    nums[begin] = pivot;
    if (begin > begin_orgin) {
        quick_sort(nums, begin_orgin, begin - 1);
    }
    if (end < end_orgin) {
        quick_sort(nums, end + 1, end_orgin);
    }
}

static int myabs(int a, int b)
{
    int x = a - b;
    return x < 0 ? (-x) : x;
}

int threeSumClosest(int* nums, int numsSize_, int target)
{
    int i, j, k;
    int ret;
    int tmp;

    numsSize = numsSize_;
    quick_sort(nums, 0, numsSize - 1);

    ret = nums[0] + nums[1] + nums[2];
    if (ret == target) return ret;

    for (i = 0; i < numsSize - 2; ++i) {
        j = i + 1;
        k = numsSize - 1;

        while (j < k) {
            tmp = nums[i] + nums[j] + nums[k];
            if (myabs(tmp, target) < myabs(ret, target)) {
                ret = tmp;
                if (ret == target) return ret;
            }
            if (tmp < target) {
                ++j;
            } else {
                // must be "tmp > target"
                --k;
            }
        }
    }

    return ret;
}

int main(int argc, char const *argv[])
{
    int nums[] = { 1, 2, 4, 8, 16, 32, 64, 128 };
    printf("%d\n", threeSumClosest(nums, 8, 82));
    return 0;
}