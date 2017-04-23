//
// Letter Combinations of a Phone Number
// https://leetcode.com/problems/letter-combinations-of-a-phone-number/#/description
//

#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

static string m[] = {"", "", "abc", "def", "ghi", "jlk",
    "mno", "pqrs", "tuv", "wxyz"};

class Solution
{
public:
    vector<string> letterCombinations(string digits)
    {
        vector<string> holder;
        int len = digits.length();
        if (len == 0) {
            return holder;
        }

        string tmp;
        string btn;

        if (len == 1) {
            btn = m[digits[0] - '0'];
            for (int i = 0, l = btn.length(); i < l; ++i) {
                tmp = "0";
                tmp[0] = btn[i];
                holder.push_back(tmp);
            }
        }

        vector<string> bholder = letterCombinations(digits.substr(0, len - 1));
        btn = m[digits[len - 1] - '0'];
        for (int i = 0, l = btn.length(); i < l; ++i) {
            for (int j = 0, size = bholder.size(); j < size; ++j) {
                tmp = "0";
                tmp[0] = btn[i];
                holder.push_back(bholder[j] + tmp);
            }
        }

        return holder;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    vector<string> a = sol.letterCombinations("234");

    for (int i = 0, size = a.size(); i < size; ++i) {
        printf("%s\n", a[i].c_str());
    }

    return 0;
}