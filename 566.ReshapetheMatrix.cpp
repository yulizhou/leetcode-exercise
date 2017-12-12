class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int row = nums.size();
        int col = nums[0].size();
        if (row * col != r * c) return nums;
        
        // make the resultant matrix
        vector<vector<int>> res(r, vector<int>(c));
        int newRow = 0;
        int newCol = 0;
        // loop over original matrix
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                res[newRow][newCol] = nums[i][j];
                newCol++;
                if (newCol == c) {
                    newCol = 0;
                    newRow++;
                }
            }
        }
        return res;
    }
};