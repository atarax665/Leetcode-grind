class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans;
        n = 2 * n;
        int i, j;
        for(i = 0, j = n / 2; i < n / 2, j < n; i++, j++)
        {
            cout<<i<<" "<<j<<"\n";
            ans.push_back(nums[i]);
            ans.push_back(nums[j]);
        }
        return ans;
    }
};