class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                int j = n - 1;
                for (j; j > i; j--) {
                    if (nums[j] > nums[i]) break;
                }
                swap(nums[i], nums[j]);
                reverse(nums.begin() + i + 1, nums.end());
                return;
            }
        }
        return reverse(nums.begin(), nums.end());
    }
};