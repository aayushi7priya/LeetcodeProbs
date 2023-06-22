class Solution {
public:
     vector<vector<int>>graph;
     vector<int>vis;
     vector<long long int>subtrsize;
    
    void dfs(int node)
    {
        vis[node] = 1;
        subtrsize[node]++;
        
        for(auto it: graph[node])
        {
            if(!vis[it])
            {
                dfs(it);
                subtrsize[node]+=subtrsize[it];
            }
        }
    }
    
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size();
        graph.resize(n+1);
        vis.resize(n+1);
        subtrsize.resize(n+1);
        
        for(int i=0;i<n;i++)
        {
            graph[roads[i][0]].push_back(roads[i][1]);
            graph[roads[i][1]].push_back(roads[i][0]);
        }
        for(int i =0;i<=n;i++)
        {
            vis[i] = 0;
            subtrsize[i] = 0;
        }
        
        dfs(0);
        long long ans = 0;
        for(int i =1;i<=n;i++)
        {
            ans+= (subtrsize[i]-1+seats)/seats;
        }
        return ans;
    }
};