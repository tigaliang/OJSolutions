//
// 739. Daily Temperatures
// https://leetcode.com/contest/weekly-contest-61/problems/daily-temperatures/
//

#include <stdio.h>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ret;
        stack<int> s;
        for (int i = 0, l = temperatures.size(); i < l; ++i)
            ret.push_back(0);
        for (int i = 0, l = temperatures.size(); i < l; ++i) {
            while (!s.empty()) {
                int t = temperatures[s.top()];
                if (t < temperatures[i]) {
                    ret[s.top()] = i - s.top();
                    s.pop();
                } else
                    break;
            }
            s.push(i);
        }

        return ret;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> temperatures;
    temperatures.push_back(73);
    temperatures.push_back(74);
    temperatures.push_back(75);
    temperatures.push_back(71);
    temperatures.push_back(69);
    temperatures.push_back(72);
    temperatures.push_back(76);
    temperatures.push_back(73);

    Solution sol;
    vector<int> ret = sol.dailyTemperatures(temperatures);
    for (int i = 0; i < ret.size(); ++i)
        printf("%d \n", ret[i]);

    return 0;
}