class Solution {
    public int[] findBall(int[][] grid) {
        int[] curr= new int[grid[0].length];
     int[] ans= new int[grid[0].length];
     Arrays.fill(ans,-1);
     for(int j=0;j<grid[0].length;j++)
     {
    curr[j]=j;
     }
     for(int i=0;i<grid.length;i++){
     for(int j=0;j<grid[i].length-1;j++)
     {
    if(grid[i][j]==1&&grid[i][j+1]==1)
    ans[j + 1]=curr[j];
    if(grid[i][j]==-1&& grid[i][j+1]==-1)
    ans[j] = curr[j + 1];
     } 
        curr = ans.clone();
         if(i == grid.length - 1)
             break;
         Arrays.fill(ans, -1);
    }
        int[] finalAns = new int[grid[0].length];
        Arrays.fill(finalAns, -1);
        for(int j=0;j<grid[0].length;j++)
     {
    if(ans[j] != -1)
    {
        finalAns[ans[j]] = j;
    }
     }
    return finalAns;
}
}