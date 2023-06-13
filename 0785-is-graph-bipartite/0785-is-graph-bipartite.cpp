class Solution {
public:
    int vis[101];
    
    bool bfs(int k, vector<vector<int>>& graph)
    {
        vis[k] = 0;
        queue<pair<int,int>>q;
        q.push({k,0});
        
        while(!q.empty())
        {
            int next = q.front().first;
            int color = q.front().second;
            
            q.pop();
            for(auto i : graph[next])
            {
                if(vis[i] == -1)
                {
                    if(color == 1) 
                    {
                        vis[i] = 0; 
                        q.push({i, 0});
                    }
                    else 
                    {
                        vis[i] = 1; 
                        q.push({i, 1});
                    }
                }
                else if(vis[i] == color)
                        return false;
  
            }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        memset(vis, -1, sizeof(vis));
        
        int n = graph.size();
        for(int k =0;k<n;k++)
        {
            if(vis[k]==-1)
                if(bfs(k,graph) == false) return false;
        }   
        return true;
    }
};
