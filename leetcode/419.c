//
// Battleships in a Board
// https://leetcode.com/problems/battleships-in-a-board/
//

#include <stdio.h>

int countBattleships(const char** board, int boardRowSize, int boardColSize) {
    int n = 0;
    int r = 0;
    int c = 0;

    for (r = 0; r < boardRowSize; ++r) {
        for (c = 0; c < boardColSize; ++c) {
            // both below & right side is empty
            if (board[r][c] == 'X'
                && (r == boardRowSize - 1 || board[r + 1][c] == '.')
                && (c == boardColSize - 1 || board[r][c + 1] == '.')) {
                ++n;
            }
        }
    }

    return n;
}

int main(int argc, char const *argv[])
{
    const char* board[] = {
        "X..X",
        "...X",
        "...X"
    };
    printf("n = %d\n", countBattleships(board, 3, 4));
    return 0;
}