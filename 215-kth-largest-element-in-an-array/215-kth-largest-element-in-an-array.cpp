class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        map<int, int> m;
        for(auto i : nums)
        {
            m[i]++;
        }
        int fromfront = nums.size() - k + 1;
        int ans;
        for(auto i : m)
        {
            if(i.second >= fromfront)
            {
                ans = i.first;
                break;
            }
            else if(i.second < fromfront)
            {
                fromfront -= i.second;
            }
        }
        return ans;
    }
};