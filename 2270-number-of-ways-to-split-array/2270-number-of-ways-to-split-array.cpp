class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long sum = accumulate(nums.begin(), nums.end(), 0l);
        int count = 0;
        
        long long innerSum = 0;
        for(int i = 0; i < nums.size() - 1; i++)
        {
            innerSum += nums[i];
            if(2 * innerSum >= sum)
            {
                count++;
            }
        }
        return count;
    }
};