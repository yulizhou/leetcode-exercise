class NumArray {
public:
    NumArray(vector<int> &nums) {
        sums = nums;
        for (int i = 1; i < nums.size(); i++) {
            sums[i] += sums[i - 1];
        }
    }
    int sumRange(int i, int j) {
        return i == 0 ? sums[j] : sums[j] - sums[i - 1];
    }
private:
    vector<int> sums;
};