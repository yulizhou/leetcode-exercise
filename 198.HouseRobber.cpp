class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
        if (nums.size() == 1) return nums[0];
        // initialize dp
        vector<int> dp = {nums[0], max(nums[0], nums[1])};
        // build the dp array
        for (int i = 2; i < nums.size(); i++) {
            dp.push_back(max(dp[i - 1], nums[i] + dp[i - 2]));
        }
        return dp.back();
    }
};