class Solution {
public:
    int vis[10002];
    int pathvis[10002];
    int checknode[10002];
    vector<int>ans;
    bool dfscheck(int node,vector<vector<int>>& graph )
    {
        vis[node] = 1;
        pathvis[node] = 1;
        for(auto i: graph[node])
        {
            if(!vis[i])
                {
                        if(dfscheck(i, graph)==true)
                        {
                            return true;
                        }
                }
            else if(pathvis[i]) 
            {
                return true;
            }
        }
        checknode[node] = 1;
        pathvis[node] = 0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int v = graph.size();
        memset(vis, 0, sizeof(vis));
        memset(pathvis, 0, sizeof(pathvis));
        memset(checknode, 0, sizeof(checknode));
        for(int i =0;i<v;i++)
        {
            if(!vis[i])
            {
                dfscheck(i, graph);
            }
        }
        
        for(int i =0;i<v;i++)
        {
            if(checknode[i]==1)
                ans.push_back(i);
        }
        
        return ans;
    }
};