class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        helper(n, n, "", res);
        return res;
    }
    
    void helper(int left, int right, string out, vector<string> &res) {
        // remaining right parenthesis must more than left
        // otherwise it's invalid
        if (left > right) return;
        if (left == 0 && right == 0) res.push_back(out);
        else {
            if (left > 0) helper(left - 1, right, out + '(', res);
            if (right > 0) helper(left, right - 1, out + ')', res);
        }
    }
};