class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int cur = 0;
        int len = bits.size();
        while (cur < len - 1){
            cur += bits[cur] + 1;
        }
        // now the cursor has two possibilities:
        // 1. it's at the last bit
        // 2. it's outside the index range (len-1)
        return cur == len - 1;
    }
};