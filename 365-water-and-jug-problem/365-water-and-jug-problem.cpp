class Solution {
public:
    bool dfs(int x, int y, int z, int curr, vector<int> &vis)
    {
        if (curr < 0 || curr > x + y || vis[curr] == 1)
            return false;
        if (curr == z)
            return true;
        vis[curr] = 1;
        if(dfs(x, y, z, curr + x, vis) || dfs(x, y, z, curr - x, vis) || dfs(x, y, z, curr + y, vis) || dfs(x, y, z, curr - y, vis))
            return true;
        return false;
        // bool a = dfs(x, y, z, curr + x, vis);
        // bool b = dfs(x, y, z, curr - x, vis);
        // bool c = dfs(x, y, z, curr + y, vis);
        // bool d = dfs(x, y, z, curr - y, vis);
        // return a || b || c || d;
    }
    bool canMeasureWater(int x, int y, int z)
    {
        if (x + y == z || x == z || y == z)
            return true;
        if (x + y < z)
            return false;
        int m = x + y; // max capacity
        vector<int> vis(m + 1, 0);
        return dfs(x, y, z, 0, vis);
    }
};