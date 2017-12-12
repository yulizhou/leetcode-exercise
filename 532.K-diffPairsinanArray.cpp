class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int res = 0;
        unordered_map<int, int> m;
        for (auto num : nums) m[num]++;
        for (auto n : m) {
            if (k == 0 && n.second > 1) res++;
            if (k > 0 && m.count(n.first + k)) res++;
        }
        return res;
    }
};