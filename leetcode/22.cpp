//
// Generate Parentheses
// https://leetcode.com/problems/generate-parentheses/#/description
//

#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> foo(string current, int left, int right) {
        vector<string> ret;
        if (left == 0 && right == 0) {
            ret.push_back(current);
            return ret;
        }
        vector<string> tmp1, tmp2;
        if (left > 0) {
            tmp1 = foo(current + "(", left - 1, right);
        }
        if (left < right) {
            tmp2 = foo(current + ")", left, right - 1);
        }
        for (int i = 0; i < tmp1.size(); ++i) {
            ret.push_back(tmp1[i]);
        }
        for (int i = 0; i < tmp2.size(); ++i) {
            ret.push_back(tmp2[i]);
        }
        return ret;
    }

    vector<string> generateParenthesis(int n) {
        return foo("", n, n);
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    vector<string> ret = sol.generateParenthesis(4);
    for (int i = 0; i < ret.size(); ++i) {
        printf("%s\n", ret[i].c_str());
    }
    return 0;
}