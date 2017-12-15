class Solution {
public:    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int color = image[sr][sc];
        if (color != newColor) dfs(image, sr, sc, color, newColor);
        return image;
    }
    
    void dfs(vector<vector<int>>& image, int r, int c, int color, int newColor) {
        int row = image.size();
        int col = image[0].size();
        if (r < 0 || r >= row || c < 0 || c >= col || image[r][c] != color) return;
        image[r][c] == newColor;
        dfs(image, r - 1, c, color, newColor);
        dfs(image, r, c - 1, color, newColor);
        dfs(image, r + 1, c, color, newColor);
        dfs(image, r, c + 1, color, newColor);
    }
};