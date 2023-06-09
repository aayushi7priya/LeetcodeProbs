class Solution {
public:
    vector<bool> vis;
    vector<vector<int>>adj;
    void dfs(int node)
    {
        vis[node] = true;
        //ls.push_back(node);
        
        for(auto i: adj[node])
        {
            if(!vis[i])
            {
                dfs(i);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        //adjacency list
       int n = isConnected.size();
        vis.resize(n, false);
        adj.resize(n);
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(isConnected[i][j]==1 && i!=j)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        
        int count = 0;
        for(int i = 0; i<n;i++)
        {
            if(!vis[i])
            {
                count++;
                dfs(i);
            }
            
        }
        return count;
        
    }
};