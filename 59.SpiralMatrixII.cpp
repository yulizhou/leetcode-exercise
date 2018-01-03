class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        // initialize to all 1s
        vector<vector<int>> res(n, vector<int>(n, 1));
        int val = 1; // the value we're going to insert
        int l = n; // the edge length of the current loop/circle
        // iterate over each loop, from outer to inner
        // i is the ith loop
        for (int i = 0; i < n / 2; i++, l -= 2) {
            // the top edge
            for (int col = i; i < i + l; col++) {
                res[i][col] = val++;
            }
            // the right edge
            for (int row = i + 1; row < i + l; row++) {
                res[row][i + l - 1] = val++;
            }
            // the bottom edge
            for (int col = i + l - 2; col >= i; col--) {
                res[i + l - 1][col] = val++;
            }
            // the left edge
            for (int row = i + l - 2; row > i; row--) {
                res[row][i] = val++;
            }
        }
        if (n % 2 != 0) res[n/2][n/2] = val;
        return res;
    }
};