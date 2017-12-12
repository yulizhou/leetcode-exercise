class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int len = nums.size();
        int res = 0;
        int current_cnt = 0;
        for (int i = 0; i < len; i++) {
            if (i == 0 || nums[i] > nums[i-1]) res = max(res, ++current_cnt);
            else current_cnt = 1;
        }
        return res;
    }
};