class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int len = nums.size();
        int leftSum = 0;
        int rightSum = 0;
        // loop to get the right sum
        for (int i = 0; i < len; i++){
            rightSum += nums[i];
        }
        // loop to compare left and right sums
        for (int i = 0; i < len; i++){
            if (leftSum == rightSum - leftSum - nums[i]){
                return i;
            }
            leftSum += nums[i];
        }
        return -1;
    }
};