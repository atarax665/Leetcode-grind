class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans = 1;
        int n = nums.size();
           for(int i=0;i<n;i++)
           {
           if(nums[i]==ans)
           {
           ans++;
           }
               else if(nums[i] > ans)
               {
                   return ans;
               }
           }
           return ans;
    }
};