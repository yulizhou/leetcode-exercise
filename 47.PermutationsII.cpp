class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> res;
        helper(nums, 0, res);
        return vector<vector<int>> (res.begin(), res.end());
    }
    
    void helper(vector<int>& nums, int start, set<vector<int>>& res) {
        if (start >= nums.size()) res.insert(nums);
        // iterate over leaf nodes, which obtained by swaping
        for (int i = start; i < nums.size(); i++) {
            if (i != start && nums[i] == nums[start]) continue;
            swap(nums[i], nums[start]);
            helper(nums, start + 1, res);
            swap(nums[i], nums[start]);
        }
    }
};