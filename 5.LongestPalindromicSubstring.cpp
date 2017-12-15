class Solution {
public:
    string longestPalindrome(string s) {
        // initialize dp
        int dp[s.length()][s.length()] = {0};
        int left = 0;
        int right = 0;
        int len = 0;
        for (int j = 0; j < s.length(); j++) {
            for (int i = 0; i < j; i++) {
                dp[i][j] = (s[i] == s[j] && (j - i < 2 || dp[i + 1][j - 1]));
                // if is a palindrome and larger than our record
                // we save the index for later
                if (dp[i][j] && len < j - i + 1) {
                    len = j - i + 1;
                    left = i;
                    right = j;
                }
            }
            // when i == j
            dp[j][j] = 1;
        }
        return s.substr(left, right - left + 1);
    }
};