class Solution {
public:
    int count = 0;
    vector<vector<pair<int, int>>> adj; //storing with arrow dirn
    
    void dfs(int node, int parent) {
        // i want to do dfs from 0 and flip wherever child is not pointing to parent
    
        for (auto it : adj[node]) {
            int child = it.first;
            int sign = it.second;
            if (child != parent) {
                count += sign;   //for opposite 1 will get added else nothing
                dfs(child, node);
            }
        }
    }

    int minReorder(int n, vector<vector<int>>& connections) {
        adj.resize(n);
        for (int i =0;i<connections.size();i++) {
            adj[connections[i][1]].push_back({connections[i][0], 0});
            adj[connections[i][0]].push_back({connections[i][1], 1});
        }
        dfs(0, -1);
        return count;
    }
};