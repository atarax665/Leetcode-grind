class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
           int ans=1,n= nums.size();
           for(int i=0;i<n;i++)
           {
           if(nums[i]==ans)
           ans++;
           }
           return ans;
    }
};