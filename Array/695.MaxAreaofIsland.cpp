class Solution {
public:
    vector<vector<int>> directions{{0,-1},{-1,0},{0,1},{1,0}};
    void island(vector<vector<int>>& grid, int i, int j, int& current_island_size, int& res) {
        int m = grid.size();
        int n = grid[0].size();
        // base case
        if (i >= m || j >= n || i < 0 || j < 0 || grid[i][j] <= 0) return;
        // otherwise explore each direction
        res = max(res, ++current_island_size);
        grid[i][j] *= -1; // mark as visited
        for (auto direction : directions) {
            island(grid, i + direction[0], j + direction[1], current_island_size, res);
        }
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int res = 0;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != 1) continue;
                int current_island_size = 0;
                island(grid, i, j, current_island_size, res);
            }
        }
        return res;
    }
};