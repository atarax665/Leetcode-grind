class Solution {
    public int[] findBall(int[][] grid) {
     int[] curr= new int[grid[0].length];
     int[] ans= new int[grid[0].length];
        
    if(grid[0].length == 1)
    {
        int[] a = {-1};
        return a;
    }
     // Arrays.fill(ans,-1);
     for(int j=0;j<grid[0].length;j++)
     {
    curr[j]=j;
     }
        
     for(int i=0;i<grid.length;i++)
     {
     for(int j=0;j<grid[i].length;j++)
     {
         if(ans[j]==-1)
         {
             continue;
         }
         if(i == 0 && ((j == 0 && grid[i][curr[j]] == -1) || (j == grid[0].length - 1 && grid[i][curr[j]] == 1)))
         {
             curr[j] = -1;
         }
         else if(curr[j]!=grid[i].length-1 && curr[j] != 0 && ((grid[i][curr[j]] == 1 && grid[i][curr[j] + 1] == -1) || (grid[i][curr[j]] == -1 && grid[i][curr[j] - 1] == 1)))
         {
             curr[j] = -1;
         }
         else if(curr[j]!=grid[i].length-1 && curr[j] != 0 && grid[i][curr[j]] == -1)
         {
             if(grid[i][curr[j] - 1] == 1)
                 curr[j] = -1;
             else
                 curr[j] = curr[j] - 1;
         }
         
        else if(curr[j]!=grid[i].length-1 && grid[i][curr[j]]==1&&grid[i][curr[j]+1]==1)
        {
            if(curr[j] + 1 > grid[i].length - 1)
                curr[j] = -1;
            else
                curr[j] = curr[j] + 1;
        }
            
        else if(curr[j] != 0 && grid[i][curr[j]] == -1 && grid[i][curr[j]-1]==-1 )
        {
            if(curr[j] - 1 < 0)
                curr[j] = -1;
            else
                curr[j] = curr[j] - 1;
        }
         else
         {
             curr[j] = -1;
         }
     }
         ans = curr.clone();
    }   
    return ans;
}
}