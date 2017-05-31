//
// Combination Sum II
// https://leetcode.com/problems/combination-sum-ii/#/description
//

#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> vi;

class Solution {
public:
    vector<vi> foo(vi& c, int b, int e, int t)
    {
        vector<vi> ret;

        for (int i = b; i < e && c[i] <= t; ++i) {
            if (i > b && c[i] == c[i - 1]) continue;
            if (t > c[i]) {
                vector<vi> tmpv = foo(c, i + 1, e, t - c[i]);
                for (int j = 0; j < tmpv.size(); ++j) {
                    vi tmp;
                    tmp.push_back(c[i]);
                    for (int k = 0; k < tmpv[j].size(); ++k) {
                        tmp.push_back(tmpv[j][k]);
                    }
                    ret.push_back(tmp);
                }
            } else { // t == c[i]
                vi tmp;
                tmp.push_back(c[i]);
                ret.push_back(tmp);
            }
        }

        return ret;
    }

    vector<vi> combinationSum2(vector<int>& candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        return foo(candidates, 0, candidates.size(), target);
    }
};

int main(int argc, char const *argv[])
{
    vector<int> candidates;
    candidates.push_back(10);
    candidates.push_back(1);
    candidates.push_back(2);
    candidates.push_back(7);
    candidates.push_back(6);
    candidates.push_back(1);
    candidates.push_back(5);

    Solution sol;
    vector<vi> ret = sol.combinationSum2(candidates, 8);

    for (int i = 0; i < ret.size(); ++i) {
        for (int j = 0; j < ret[i].size(); ++j) {
            printf("%d ", ret[i][j]);
        }
        printf("\n");
    }

    return 0;
}