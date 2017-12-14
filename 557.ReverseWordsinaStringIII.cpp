class Solution {
public:
    string reverseWords(string s) {
        int start = 0;
        int end = 0;
        int n = s.length();
        while (start < n && end < n) {
            // find the end of a word
            while (end < n && s[end] != ' ') end++;
            for (int i = start, j = end - 1; i < j; i++, j--) {
                swap(s[i], s[j]);
            }
            start = ++end;
        }
        return s;
    }
};