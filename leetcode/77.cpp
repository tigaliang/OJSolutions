//
// Combinations
// https://leetcode.com/problems/combinations/description/
//

#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;

class Solution {
public:
    vector<vi> combine(int n, int k) {
        vector<vi> ret;
        if (n == k) {
            vi t;
            for (int i = 0; i < n; ++i)
                t.push_back(i + 1);
            ret.push_back(t);
        } else if (k == 1) {
            for (int i = 0; i < n; ++i) {
                vi t;
                t.push_back(i + 1);
                ret.push_back(t);
            }
        } else {
            for (int e = n; e >= k; --e) {
                vector<vi> tmp_ret = combine(n - (n - e) - 1, k - 1);
                for (int j = 0; j < tmp_ret.size(); ++j) {
                    tmp_ret[j].push_back(e);
                    ret.push_back(tmp_ret[j]);
                }
            }
        }

        return ret;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    vector<vi> ret = sol.combine(5, 3);
    for (int i = 0; i < ret.size(); ++i) {
        for (int j = 0; j < ret[i].size(); ++j)
            cout << ret[i][j] << " ";
        cout << endl;
    }

    return 0;
}