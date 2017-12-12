class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int count = m + n - 1;
        --m; --n;
        while (m >= 0 && n >= 0) nums1[count--] = nums1[m] > nums2[n] ? nums1[m--] : nums2[n--];
        while (n >= 0) nums1[count--] = nums2[n--];
    }
};