//
// 3Sum
// https://leetcode.com/problems/3sum/#/description
//

#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

class Solution {
private:
    void quick_sort(vector<int>& nums, int begin, int end) {
        int pivot = nums[begin];
        int numsSize = nums.size();
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
public:
    vector<vector<int> > threeSum(vector<int>& nums) {
        int c, i, j, k;
        int target;
        vector<vector<int> > ret;
        int numsSize = nums.size();

        if (numsSize < 3) {
            return ret;
        }

        quick_sort(nums, 0, numsSize - 1);
        /*for (i = 0; i < numsSize; ++i) {
            printf("%d\n", nums[i]);
        }*/

        for (c = 0; c < numsSize - 2; ++c) {
            target = nums[c];
            if (target > 0) break;
            if (c > 0 && target == nums[c - 1]) continue;

            i = c + 1;
            j = numsSize - 1;
            while (i < j) {
                while (i < j && nums[i] + nums[j] < -target) ++i;
                while (i < j && nums[i] + nums[j] > -target) --j;

                if (i < j && nums[i] + nums[j] == -target) {
                    vector<int> holder;
                    // printf("malloc: %d, %d\n", sizeof(int) * 3, sizeof(int *) * (*returnSize + 1));
                    holder.push_back(target);
                    holder.push_back(nums[i]);
                    holder.push_back(nums[j]);
                    ret.push_back(holder);
                    while (i < j && nums[++i] == nums[i - 1]);
                    while (i < j && nums[--j] == nums[j + 1]);
                }
            }
        }

        return ret;
    }
};

int main(int argc, char const *argv[])
{
    int i;
    vector<int> nums;
    nums.push_back(-1);
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(-1);
    nums.push_back(-4);

    Solution sol;
    vector<vector<int> > ret = sol.threeSum(nums);

    for (i = 0; i < ret.size(); ++i) {
        printf("%d, %d, %d\n", ret[i][0], ret[i][1], ret[i][2]);
    }

    return 0;
}