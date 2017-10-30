//
// Word Search
// https://leetcode.com/problems/word-search/description/
//

#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <cstring>

using namespace std;

typedef vector<char> VC;

struct P {
    int i;
    int j;

    P(int ii, int jj) {
        i = ii;
        j = jj;
    }
};

typedef vector<P> VP;

class Solution {
public:
    bool exist(vector<VC>& board, string word) {
        int n_rows = board.size();
        if (n_rows < 1)
            return false;
        int n_cols = board[0].size();
        if (n_cols < 1)
            return false;

        vector<char *> access;
        for (int i = 0; i < n_rows; ++i) {
            char *row = new char[n_cols];
            memset(row, 0, n_cols);
            access.push_back(row);
        }

        stack<VP> svp;
        VP first;
        for (int i = 0; i < n_rows; ++i) {
            for (int j = 0; j < n_cols; ++j) {
                if (board[i][j] == word[0])
                    first.push_back(P(i, j));
            }
        }
        if (first.empty())
            return false;
        svp.push(first);

        int count = 0;
        while (!svp.empty()) {
            VP top = svp.top();
            if (top.empty()) {
                svp.pop();
                continue;
            }
            int i = top.back().i;
            int j = top.back().j;

            if (access[i][j]) {
                access[i][j] = 0;
                top.pop_back();
                svp.pop();
                svp.push(top);
                continue;
            }

            cout << i << ',' << j << ',' << count << endl;

            access[i][j] = 1;
            count += 1;
            if (count == word.length())
                return true;

            VP next;
            if (i > 0 && !access[i - 1][j] && word[count] == board[i - 1][j]) {
                next.push_back(P(i - 1, j));
            } else if (i < n_rows - 1 && !access[i + 1][j] && word[count] == board[i + 1][j]) {
                next.push_back(P(i + 1, j));
            } else if (j > 0 && !access[i][j - 1] && word[count] == board[i][j - 1]) {
                next.push_back(P(i, j - 1));
            } else if (j < n_cols - 1 && !access[i][j + 1] && word[count] == board[i][j + 1]) {
                cout << "xx" << endl;
                next.push_back(P(i, j + 1));
            }
            if (!next.empty()) {
                svp.push(next);
            } else {
                access[i][j] = 0;
                count -= 1;
                top.pop_back();
                svp.pop();
                svp.push(top);
            }
        }

        for (int i = 0; i < n_rows; ++i)
            free(access[i]);

        return false;
    }
};

int main(int argc, char const *argv[])
{
    vector<VC> board;
    VC row1;
    row1.push_back('A');
    row1.push_back('B');
    row1.push_back('C');
    row1.push_back('E');
    board.push_back(row1);
    VC row2;
    row2.push_back('S');
    row2.push_back('F');
    row2.push_back('C');
    row2.push_back('S');
    board.push_back(row2);
    VC row3;
    row3.push_back('A');
    row3.push_back('D');
    row3.push_back('E');
    row3.push_back('E');
    board.push_back(row3);

    /*
    A B C E
    S F E S
    A D E E
    */

    Solution solution;
    if (solution.exist(board, "SEE"))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}