class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> indices;
        vector<int> res;
        
        for (int i = 0; i < nums.size(); ++i) {
            indices[nums[i]] = i; // if repeated, use the latter one
        }
        
        for (int i = 0; i < nums.size(); ++i) {
            int t = target - nums[i];
            if (indices.count(t) && indices[t] != i) {
                res.push_back(i);
                res.push_back(indices[t]);
                break;
            }
        }
        return res;
    }
};