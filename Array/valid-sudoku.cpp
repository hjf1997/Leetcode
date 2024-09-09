#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> row_set(9);
        vector<unordered_set<char>> col_set(9);
        vector<unordered_set<char>> block_set(9);
        for (int i=0; i<9; i++)
            for (int j=0; j<9; j++){
                if (board[i][j] == '.') continue;

                int raw_count = row_set[i].count(board[i][j]);
                row_set[i].insert(board[i][j]);

                int col_count = col_set[j].count(board[i][j]);
                col_set[j].insert(board[i][j]);

                int block_count = block_set[(i/3)*3 + j/3].count(board[i][j]);
                block_set[(i/3)*3 + j/3].insert(board[i][j]);

                if (raw_count + col_count + block_count > 0) return false;
            }
        return true;
    }
};

int main() {
    Solution sol;
    vector<vector<char>> board = {
        {'8','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    bool ans = sol.isValidSudoku(board);
    cout << ans << endl;
    return 0;
}