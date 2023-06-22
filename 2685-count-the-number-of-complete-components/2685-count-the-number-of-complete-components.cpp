class Solution {
public:
    vector<vector<int>>graph;
    vector<int>vis;
    void dfs(int node, int& node_count, int& edge_count)    //this passing by reference is important 
    {                                                       //if u don't when u are calculating check after dfs, it won't take into account changed value
        vis[node] = 1;
        node_count++;
        edge_count+=graph[node].size();
        for(auto it: graph[node])
        {
            if(vis[it]==0)
                dfs(it, node_count, edge_count);
            
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        graph.resize(n);
        vis.resize(n);
        for(int i =0;i<n;i++) vis[i] = 0;
        for(int i =0;i<edges.size();i++)
        {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        int ans = 0; //number of components
        for(int i =0;i<n;i++)
        {   int node_count=0, edge_count =0;
            if(vis[i]==0)
            {
                dfs(i, node_count, edge_count);
                if(edge_count == node_count*(node_count -1) ) ans++;
            }
        }
        return ans;
    }
};