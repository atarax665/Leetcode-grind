class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int ans = 0;
        int GC = 0;
        int remain = 0;
        for(int i = 0; i < n; i++)
        {
            GC += gas[i] - cost[i];
            if(GC < 0)
            {
                ans = i + 1;
                remain += GC;
                GC = 0;
            }
        }
        if(GC + remain >= 0)
        {
            return ans;
        }
        return -1;
    }
};