class Solution {
public:
        int dfs(vector<vector<int>>&adj,int n,int node,int myrank,vector<int>&rank,vector<vector<int>>&ans)
    {
        if(rank[node]!=-2)
        {
            return rank[node];
        }
        int lowestrank=myrank;//Assume my current rank is the lowest
        rank[node]=myrank;  //Rank of the current node be the myrank
        for(auto it:adj[node])
        {
            if(rank[it]==myrank-1 || rank[it]==n)
            {
                //First condition is for nor going back to the parent node
                continue;
            }
            int next_node_rank = dfs(adj,n,it,myrank+1,rank,ans);
            lowestrank=min(lowestrank,next_node_rank);
            if(next_node_rank>myrank)
            {
                vector<int>v;
                v.push_back(min(node,it));
                v.push_back(max(node,it));
                ans.push_back(v);
                //This mmin and max is used just to avoid duplication
            }
        }
        rank[node]=n; //Just to know the current node is completed and no need for further
        return lowestrank;
    }
    
    
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>>adj(n,vector<int>());
        for (auto& conn : connections) {
            adj[conn[0]].push_back(conn[1]);
            adj[conn[1]].push_back(conn[0]);
        }
        vector<int>rank(n,-2);
        vector<vector<int>>ans;
        dfs(adj,n,0,0,rank,ans);
        return ans;
    }
};