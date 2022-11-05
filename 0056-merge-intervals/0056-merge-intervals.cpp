class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        vector<int> freq(10001, INT_MAX);
        for(int i = 0; i < intervals.size(); i++)
        {
            if(freq[intervals[i][0]] == INT_MAX)
            {
                freq[intervals[i][0]] = 1;
            }
            else if(freq[intervals[i][0]] != INT_MAX)
            {
                freq[intervals[i][0]] += 1;
            }
            if(freq[intervals[i][1]] == INT_MAX)
            {
                freq[intervals[i][1]] = -1;
            }
            else if(freq[intervals[i][1]] != INT_MAX)
            {
                freq[intervals[i][1]] -= 1;
            }
        }
        
        for(int i = 0; i < 19; i++)
        {
            cout<<freq[i]<<" ";
        }
        // 1,5 5,5 5, 6
         // 1,0,0,0,-1
        int k = 0;
        int sum = 0;
        for(int i = 0; i < 10001; i++)
        {
            if(freq[i] == INT_MAX)
                continue;
            if(sum == 0 && freq[i] == 0)
            {
                ans.push_back({i, i});
                k++;
            }
            if(freq[i] > 0)
            {
                if(sum == 0)
                {
                    ans.push_back({i, 0});
                }
                sum += freq[i];
            }
            if(freq[i] < 0)
            {
                sum += freq[i];
                if(sum == 0)
                {
                    ans[k][1] = i;
                    k++;
                }
            }
        }
        return ans;
    }
};