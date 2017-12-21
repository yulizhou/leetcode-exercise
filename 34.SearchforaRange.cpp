class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        // initialize {-1, -1}
        vector<int> res(2, -1);
        int leftIndex = helper(nums, target, true);
        if (leftIndex == nums.size() || nums[leftIndex] != target) {
            return res;
        }
        res[0] = leftIndex;
        res[1] = helper(nums, target, false) - 1;
        return res;
    }
    
    int helper(vector<int>& nums, int target, bool left) {
        int lo = 0, hi = nums.size();
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (nums[mid] > target || (left && target == nums[mid])) {
                hi = mid;
            }
            else lo = mid + 1;
        }
        return lo;
    }
};