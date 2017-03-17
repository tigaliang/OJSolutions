//
// https://leetcode.com/problems/surrounded-regions/#/description
// Surrounded Regions
//

#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;

struct node
{
    int row;
    int col;
};

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        queue<node> mqueue;
        vector <vector<char>> tmp;
        int row = board.size();
        if (row == 0) {
            return;
        }
        int col = board[0].size();
        if (col == 0) {
            return;
        }

        for (int i = 0; i < row; i++) {
            tmp.push_back(vector<char>());
            for (int j = 0; j < col; j++) {
                tmp[i].push_back('X');
            }
        }

        for (int i = 0; i < col; i++) {
            if (board[0][i] == 'O') {
                tmp[0][i] = 'O';
                node n;
                n.row = 0;
                n.col = i;
                mqueue.push(n);
            }
        }
        if (row > 1) {
            for (int i = 0; i < col; i++) {
                if (board[row - 1][i] == 'O') {
                    tmp[row - 1][i] = 'O';
                    node n;
                    n.row = row - 1;
                    n.col = i;
                    mqueue.push(n);
                }
            }
        }
        for (int i = 0; i < row; i++) {
            if (board[i][0] == 'O') {
                tmp[i][0] = 'O';
                node n;
                n.row = i;
                n.col = 0;
                mqueue.push(n);
            }
        }
        if (col > 1) {
            for (int i = 0; i < row; i++) {
                if (board[i][col - 1] == 'O') {
                    tmp[i][col - 1] = 'O';
                    node n;
                    n.row = i;
                    n.col = col - 1;
                    mqueue.push(n);
                }
            }
        }

        while (!mqueue.empty()) {
            node n = mqueue.front();
            mqueue.pop();
            if (n.row > 0) {
                int u_row = n.row - 1;
                if (board[u_row][n.col] == 'O' && tmp[u_row][n.col] != 'O') {
                    tmp[u_row][n.col] = 'O';
                    node nn;
                    nn.row = u_row;
                    nn.col = n.col;
                    mqueue.push(nn);
                }
            }
            if (n.row < row - 1) {
                int d_row = n.row + 1;
                if (board[d_row][n.col] == 'O' && tmp[d_row][n.col] != 'O') {
                    tmp[d_row][n.col] = 'O';
                    node nn;
                    nn.row = d_row;
                    nn.col = n.col;
                    mqueue.push(nn);
                }
            }
            if (n.col > 0) {
                int l_col = n.col - 1;
                if (board[n.row][l_col] == 'O' && tmp[n.row][l_col] != 'O') {
                    tmp[n.row][l_col] = 'O';
                    node nn;
                    nn.row = n.row;
                    nn.col = l_col;
                    mqueue.push(nn);
                }
            }
            if (n.col < col - 1) {
                int r_col = n.col + 1;
                if (board[n.row][r_col] == 'O' && tmp[n.row][r_col] != 'O') {
                    tmp[n.row][r_col] = 'O';
                    node nn;
                    nn.row = n.row;
                    nn.col = r_col;
                    mqueue.push(nn);
                }
            }
        }

        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                board[i][j] = tmp[i][j];
            }
        }
    }
};

int main(int argc, int* argv[])
{
    /*

    X X X X
    X O O X
    X X O X
    X O X X
    
    */

    vector<vector<char>> test;
    vector<char> row0;
    row0.push_back('X');
    row0.push_back('X');
    row0.push_back('X');
    row0.push_back('X');
    vector<char> row1;
    row1.push_back('X');
    row1.push_back('O');
    row1.push_back('O');
    row1.push_back('X');
    vector<char> row2;
    row2.push_back('X');
    row2.push_back('X');
    row2.push_back('O');
    row2.push_back('X');
    vector<char> row3;
    row3.push_back('X');
    row3.push_back('O');
    row3.push_back('X');
    row3.push_back('X');
    test.push_back(row0);
    test.push_back(row1);
    test.push_back(row2);
    test.push_back(row3);

    Solution solution;
    solution.solve(test);

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            printf("%c", test[i][j]);
        }
        printf("\n");
    }

    return 0;
}