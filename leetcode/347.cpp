//
// Top K Frequent Elements
// https://leetcode.com/problems/top-k-frequent-elements/
//

#include <stdio.h>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        typedef map<int, int> mii;
        mii m;
        for (int i  = 0; i < nums.size(); ++i) {
            if (m.count(nums[i])) {
                m[nums[i]] += 1;
            } else {
                m[nums[i]] = 1;
            }
        }

        vector< vector<int> > c(nums.size());
        for (mii::iterator it = m.begin(); it != m.end(); ++it) {
            c[it->second - 1].push_back(it->first);
        }

        vector<int> r;
        for (int i = nums.size() - 1; i >= 0; --i) {
            int si = c[i].size();
            if (si > 0) {
                for (int j = 0; j < si; j++) {
                    r.push_back(c[i][j]);
                }
                if (r.size() >= k) {
                    break;
                }
            }            
        }

        return r;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(2);
    v.push_back(1);
    v.push_back(1);
    v.push_back(3);

    Solution s;
    vector<int> r = s.topKFrequent(v, 2);

    for (int i = 0; i < r.size(); ++i) {
        printf("%d\n", r[i]);
    }

    return 0;
}
