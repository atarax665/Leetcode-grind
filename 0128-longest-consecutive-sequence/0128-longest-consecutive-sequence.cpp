class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int num : nums)
        {
            mp[num] = 1;
        }
        for(int num : nums)
        {
            if(mp.find(num - 1) != mp.end())
            {
                mp[num] = 0;
            }
        }
        int ans = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            int len = 1;
            if(mp[nums[i]] == 1)
            {
                while(mp.find(nums[i] + len) != mp.end())
                {
                    len++;
                }
            }
            ans = max(ans, len);
        }
        return ans;
    }
};