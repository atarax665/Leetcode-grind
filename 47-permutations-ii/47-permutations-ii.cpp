class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>> ans;
        vector<vector<int>> ans1;
        backtrack(n, nums, 0, ans);
        for(auto i : ans)
        {
            ans1.push_back(i);
        }
        return ans1;
    }
    
    void backtrack(int n, vector<int> nums, int idx, set<vector<int>> &ans)
    {
        if(idx >= n)
        {
            ans.insert(nums);
            return;
        }
        //now we will do nothing  but just swap the values of individuals with itself and all numbers and on backtracking we will again change the array to its original input
        for(int i = idx; i<nums.size(); i++){
            swap(nums[idx], nums[i]);
            //again make a recursive call for the next index
            backtrack(n, nums, idx+1, ans);
            //backtracking again swapping to return array to its original input 
            swap(nums[idx], nums[i]);
        }
    }
};