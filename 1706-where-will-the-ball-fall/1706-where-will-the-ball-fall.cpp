class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) 
    {
        int n = grid.size(), m = grid[0].size();
        
        if (m==1)
            return {-1};
        
        // 2 vectors to store position of balls (b0,b1,b2...)
        // index in both represents the column number in that particular row
        // value in both represents the ball numer that has managed to rach that column 
        // curr - to store the current position of ball number
        // next - to calculate next position of ball number
        vector<int> curr(m,-1),next(m,-1);
        
        // currently each ball starts at it's index
        for (int i=0; i<m; i++)
        {
            curr[i]=i;
        }
        
        // iterate through each row and each time calculate the next values based on the current values 
        for (int i=0; i<n; i++)
        {
            // if we get 2 consecutive 1, ball will go right side (increase it's index in next)
            // if we get 2 consecutive -1, ball will go left side (decrease it's index in next)
            
            // check for first 2 columns
            if (grid[i][0]==1 && grid[i][1]==1)
            {
                next[1]=curr[0];
            }
            
            if (grid[i][0]==-1 && grid[i][1]==-1)
            {
                next[0]=curr[1];
            }
            
            // check for rest of the colums
            for (int j=1; j<m-1; j++)
            {
                if (grid[i][j]==1 && grid[i][j+1]==1)
                {
                    next[j+1]=curr[j];
                }
                
                if (grid[i][j]==-1 && grid[i][j+1]==-1)
                {
                    next[j]=curr[j+1];
                }
            }
            
            // curr will become next for next row
            curr = next;
            
            // for last row, we have next vector containing ball numbers (value) in the respective columns (index)
            if (i==n-1)
                break;
            
            // initialise next to -1 again 
            for (int i=0; i<m; i++)
            {
                next[i]=-1;
            }
        }
        
        // we need to return vector having whose value represents column and index represents the ball number
        vector <int> ans (m,-1);
        
        for (int i=0; i<m; i++)
        {
            if (next[i]!=-1)
                ans[next[i]]=i;
        }
        return ans;
    }
};