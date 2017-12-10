class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size(), i = 0, j = n - 1;
        vector<int> temp = nums;
        sort(temp.begin(), temp.end());
        while (i < n && nums[i] == temp[i]) i++;
        while (j > i && nums[j] == temp[j]) j--;
        return j - i + 1;
    }
};


// the O(n) time and O(1) solution
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size(), start = -1, end = -2;
        int mn = nums[n - 1], mx = nums[0];
        for (int i = 1; i < n; ++i) {
            mx = max(mx, nums[i]);
            mn = min(mn, nums[n - 1 - i]);
            if (mx > nums[i]) end = i;
            if (mn < nums[n - 1 - i]) start = n - 1 - i;
        }
        return end - start + 1;
    }
};