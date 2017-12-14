class NumArray {
public:
    NumArray(vector<int> &nums) {
        accuSum.push_back(0);
        for (int num : nums)
            accuSum.push_back(accuSum.back() + num);
    }

    int sumRange(int i, int j) {
        return accuSum[j + 1] - accuSum[i];
    }
private:
    vector<int> accuSum;
};