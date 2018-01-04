class Solution {
public:
    string addBinary(string a, string b) {
        string res = "";
        int m = a.length() - 1;
        int n = b.length() - 1;
        int carry = 0;
        while (m >= 0 || n >= 0) {
            int p = m >= 0 ? a[m--] - '0' : 0;
            int q = n >= 0 ? b[n--] - '0' : 0;
            int sum = p + q + carry;
            res = to_string(sum % 2) + res;
            carry = sum / 2;
        }
        // if there is one last carry
        return carry == 1 ? "1" + res : res;
    }
};