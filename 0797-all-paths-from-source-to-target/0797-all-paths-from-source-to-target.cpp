class Solution {
public:
    int n;
    vector<vector<int>> ans;
    vector<int>path;
    void dfs(int node, vector<vector<int>>& graph)
    {
        if(node == n-1)
        {
           ans.push_back(path);
            return;
        }
        for(auto it: graph[node])
        {
            path.push_back(it);
            dfs(it, graph);
            path.pop_back();
        }
        
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        n = graph.size();
        path.push_back(0);
        dfs(0, graph);
        
        return ans;
    }
};