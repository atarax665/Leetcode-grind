class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);

        int sz = nums.size();
        for (int i = 0, lsum = 0; i < sz; ++i) {
            sum -= nums[i];
            if (i > 0) lsum += nums[i-1];
            if (sum == lsum) return i;
        }
        return -1;
    }
};