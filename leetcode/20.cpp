//
// Valid Parentheses
// https://leetcode.com/problems/valid-parentheses/#/description
//

#include <stdio.h>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (int i = 0, len = s.size(); i < len; ++i) {
            char ch = s[i];
            if (ch == '(' || ch == '[' || ch == '{') {
                st.push(ch);
            } else {
                if (st.empty()) {
                    return false;
                }
                char t = st.top();
                if ((t == '(' && ch == ')')
                    || (t == '[' && ch == ']')
                    || (t == '{' && ch == '}')) {
                    st.pop();
                } else {
                    st.push(ch);
                }
            }
        }
        return st.empty();
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    printf("%s\n", sol.isValid("([])[{]}") ? "true" : "false");
    return 0;
}