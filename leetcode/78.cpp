//
// Subsets
// https://leetcode.com/problems/subsets/description/
//

#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;

class Solution {
private:
    vector<vi> combine(int n, int k, vi& nums) {
        vector<vi> ret;
        if (k == 0) {
            vi tmp_ret;
            ret.push_back(tmp_ret);
            return ret;
        } if (n == k) {
            vi t;
            for (int i = 0; i < n; ++i)
                t.push_back(nums[i]);
            ret.push_back(t);
        } else if (k == 1) {
            for (int i = 0; i < n; ++i) {
                vi t;
                t.push_back(nums[i]);
                ret.push_back(t);
            }
        } else {
            for (int e = n; e >= k; --e) {
                vector<vi> tmp_ret = combine(n - (n - e) - 1, k - 1, nums);
                for (int j = 0; j < tmp_ret.size(); ++j) {
                    tmp_ret[j].push_back(nums[e - 1]);
                    ret.push_back(tmp_ret[j]);
                }
            }
        }

        return ret;
    }
public:
    vector<vi> subsets(vector<int>& nums) {
        vector<vi> ret;
        for (int i = 0; i <= nums.size(); ++i) {
            vector<vi> tmp_ret = combine(nums.size(), i, nums);
            for (int j = 0; j < tmp_ret.size(); ++j) {
                ret.push_back(tmp_ret[j]);
            }
        }
        return ret;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    vi nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(4);
    nums.push_back(5);
    vector<vi> ret = sol.subsets(nums);
    for (int i = 0; i < ret.size(); ++i) {
        for (int j = 0; j < ret[i].size(); ++j)
            cout << ret[i][j] << " ";
        cout << endl;
    }

    return 0;
}