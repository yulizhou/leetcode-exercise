class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        if (M.empty() || M[0].empty()) return {};
        int row = M.size();
        int col = M[0].size();
        vector<vector<int>> res = M;
        vector<vector<int>> directions = {{0,-1},{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1}};
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                int cnt = 1; // avoid division by zero
                int sum = M[i][j];
                for (auto d : directions) {
                    int x = i + d[0];
                    int y = j + d[1];
                    if (x < 0 || x >= row || y < 0 || y >= col) continue;
                    cnt++;
                    sum += M[x][y];
                }
                res[i][j] = sum / cnt;
            }
        }
        return res;
    }
};