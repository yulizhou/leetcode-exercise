class Solution {
public:
    bool judgeCircle(string moves) {
        pair<int, int> pos(0, 0);
        for (char move : moves) {
            if (move == 'U') pos.second++;
            else if (move == 'D') pos.second--;
            else if (move == 'L') pos.first--;
            else pos.first++;
        }
        return pos.first == 0 && pos.second == 0;
    }
};