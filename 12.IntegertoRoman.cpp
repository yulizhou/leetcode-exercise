class Solution {
public:
    string intToRoman(int num) {
        string res = "";
        vector<string> val1{"", "M", "MM", "MMM"};
        vector<string> val2{"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        vector<string> val3{"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        vector<string> val4{"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        return val1[num / 1000] + val2[(num % 1000) / 100] + val3[(num % 100) / 10] + val4[num % 10];
    }
};