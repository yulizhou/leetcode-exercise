class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        string t = A;
        for (int i = 1; i <= B.length() / A.length() + 2; i++, t += A) {
            if (t.find(B) != string::npos) return i;
        }
        return -1;
    }
};