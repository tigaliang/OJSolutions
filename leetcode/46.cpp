//
// Permutations
// https://leetcode.com/problems/permutations/#/description
//
#include <stdio.h>
#include <vector>

using namespace std;

typedef vector<int> vi;

class Solution {
public:
    vector<vi> permute(vector<int>& nums)
    {
        vector<vi> ret;
        if (nums.size() <= 1) {
            ret.push_back(nums);
        } else {
            for (int i = 0, l = nums.size(); i < l; ++i) {
                vi tmp;
                for (int j = 0; j < l; ++j) {
                    if (j != i) tmp.push_back(nums[j]);
                }
                vector<vi> tmpret = permute(tmp);
                for (int k = 0, ll = tmpret.size(); k < ll; ++k) {
                    tmpret[k].push_back(nums[i]);
                    ret.push_back(tmpret[k]);
                }
            }
        }
        return ret;
    }
};

int main(int argc, char const *argv[])
{
    vi nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    Solution sol;
    vector<vi> ret = sol.permute(nums);
    for (int i = 0; i < ret.size(); ++i) {
        for (int j = 0; j < ret[i].size(); ++j) {
            printf("%d ", ret[i][j]);
        }
        printf("\n");
    }
    return 0;
}