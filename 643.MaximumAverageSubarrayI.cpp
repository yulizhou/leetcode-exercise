class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        // calculate the sum of the first k elements
        double sum = accumulate(nums.begin(), nums.begin() + k, 0);
        double res = sum;
        for (int i = k; i < nums.size(); i++) {
            sum += nums[i] - nums[i-k];
            res = max(sum, res);
        }
        return res / k;
    }
};