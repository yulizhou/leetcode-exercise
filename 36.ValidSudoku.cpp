class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) return false;
        bool row[9][9] = {false}, col[9][9] = {false}, subcell[9][9] = {false};
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    // convert char type number to int type
                    int num = board[i][j] - '0' - 1;
                    // map subcell to numbers (0-8)
                    int k = i / 3 * 3 + j / 3;
                    // if any of the current number exists
                    if (row[i][num] || col[j][num] || subcell[k][num]) return false;
                    row[i][num] = col[j][num] = subcell[k][num] = true;
                }
            }
        }
        return true;
    }
}; 