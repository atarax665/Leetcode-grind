class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int totalT = 0, maxCur = 0;
        
        for(int i = 0; i < colors.size(); i++)
        {
            if(i > 0 && colors[i] != colors[i - 1])
            {
                maxCur = 0;
            }
            totalT += min(maxCur, neededTime[i]);
            maxCur = max(maxCur, neededTime[i]);
        }
        return totalT;
    }
};