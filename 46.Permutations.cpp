class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> out;
        vector<int> visited(nums.size(), 0);
        helper(nums, 0, visited, out, res);
        return res;
    }
    
    void helper(vector<int>& nums, int cnt, vector<int>& visited, vector<int>& out, vector<vector<int>>& res) {
        if (cnt == nums.size()) res.push_back(out);
        else {
            for (int i = 0; i < nums.size(); i++) {
                if (visited[i] == 0) {
                    visited[i] = 1;
                    out.push_back(nums[i]);
                    helper(nums, cnt + 1, visited, out, res);
                    out.pop_back();
                    visited[i] = 0;
                }
            }
        }
    }
};