class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int len = nums.size();
        int res = 50000;
        int degree = 0;
        
        // map stores the count
        unordered_map<int, int> map;
        // position stores first and last position of a value
        unordered_map<int, pair<int, int>> position;
        
        for (int i = 0; i < len; i++) {
            if (++map[nums[i]] == 1) {
                position[nums[i]] = {i, i};
            } else {
                position[nums[i]].second = i;
            }
            degree = max(degree, map[nums[i]]);
        }
        
        for (auto val : map) {
            if (val.second == degree) {
                res = min(res, position[val.first].second - position[val.first].first + 1);
            }
        }
        return res;
    }
};