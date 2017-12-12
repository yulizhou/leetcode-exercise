class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if (n % 2 == 0) return max(nums[n / 2], nums[n / 2 - 1]);
        else return nums[(n - 1) / 2];
    }
};