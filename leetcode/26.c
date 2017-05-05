//
// Remove Duplicates from Sorted Array
// https://leetcode.com/problems/remove-duplicates-from-sorted-array/#/description
//

#include <stdio.h>

int removeDuplicates(int* nums, int numsSize)
{
    int i, j;
    int found;

    if (numsSize < 2) return numsSize;

    i = 0;
    while (1) {
        found = 0;
        for (j = i + 1; j < numsSize; ++j) {
            if (nums[i] < nums[j]) {
                found = 1;
                nums[i + 1] = nums[j];
                break;
            }
        }
        if (!found) break;
        ++i;
    }
    return i + 1;
}

int main(int argc, char const *argv[])
{
    int a[] = {1, 1, 1, 2};
    int l = removeDuplicates(a, 4);
    int i;

    for (i = 0; i < l; ++i) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}