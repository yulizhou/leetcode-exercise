class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // use set to make sure uniquenes
        set<vector<int>> res;
        // sort it in ascending order
        sort(nums.begin(), nums.end());
        for (int k = 0; k < nums.size(); ++k) {
            // we have to have negative number to have an answer
            if (nums[k] > 0) break;
            int target = 0 - nums[k];
            int i = k + 1, j = nums.size() - 1;
            while (i < j) {
                if (nums[i] + nums[j] == target) {
                    res.insert({nums[k], nums[i], nums[j]});
                    while (i < j && nums[i] == nums[i + 1]) i++;
                    while (i < j && nums[j] == nums[j - 1]) j--;
                    i++;
                    j--;
                } else if (nums[i] + nums[j] < target) i++;
                else j--;
            }
        }
        return vector<vector<int>>(res.begin(), res.end());
    }
};