class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxCnt = 0;
        int currentCnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) currentCnt++;
            else {
                maxCnt = max(maxCnt, currentCnt);
                currentCnt = 0;
            }
        }
        return max(maxCnt, currentCnt);;
    }
};