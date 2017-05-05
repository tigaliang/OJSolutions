//
// Remove Element
// https://leetcode.com/problems/remove-element/#/description
//

#include <stdio.h>

int removeElement(int* nums, int numsSize, int val)
{
    int i, j;

    for (i = 0, j = 0; j < numsSize; ++j) {
        if (nums[j] != val) {
            nums[i++] = nums[j];
        }
    }
    return i;
}

int main(int argc, char const *argv[])
{
    int a[] = {1, 1, 1, 2};
    int l = removeElement(a, 4, 3);
    int i;

    for (i = 0; i < l; ++i) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}