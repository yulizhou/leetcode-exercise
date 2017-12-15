class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        // the set contains substring chars of the current window
        set<char> t;
        int ans = 0, i = 0, j = 0;
        while (i < n && j < n) {
            if (t.find(s[j]) == t.end()) {
                t.insert(s[j++]);
                ans = max(ans, j - i);
            }
            else {
                // window left increase
                t.erase(s[i++]);
            }
        }
        return ans;
    }
};