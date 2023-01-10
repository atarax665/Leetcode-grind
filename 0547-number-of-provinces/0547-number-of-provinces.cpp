class Solution {
public:
    struct dsu
{
    vector<int> parent;
    vector<int> size;
    int totalComponents;

    void init(int n)
    {
        parent.resize(n);
        size.resize(n);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
        totalComponents = n;
    }

    int get(int x)
    {
        return (x == parent[x] ? x : (parent[x] = get(parent[x])));
    }

    void unite(int x, int y)
    {
        x = get(x);
        y = get(y);
        if (x != y)
        {
            if (size[x] < size[y])
                swap(x, y);
            parent[y] = x;
            size[x] += size[y];
            totalComponents--;
        }
    }
};
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        dsu d;
        d.init(n);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (isConnected[i][j] == 1)
                {
                    d.unite(i, j);
                }
            }
        }
        return d.totalComponents;
    }
};