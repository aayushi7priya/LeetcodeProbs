class Solution {
public:
    int vis[101];
    
    bool dfs(int k,int color, vector<vector<int>>& graph)
    {
        vis[k] = color;
    
        for(auto i: graph[k])
        {
            if(vis[i]==-1)
            {
                if(dfs(i, 1 - color, graph)==false) return false;
            }
            else if(vis[i] == color)
                return false;
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        memset(vis, -1, sizeof(vis));
        
        int n = graph.size();
        for(int k =0;k<n;k++)
        {
            if(vis[k]==-1)
                if(dfs(k,0,graph) == false) return false;
        }   
        return true;
    }
};
