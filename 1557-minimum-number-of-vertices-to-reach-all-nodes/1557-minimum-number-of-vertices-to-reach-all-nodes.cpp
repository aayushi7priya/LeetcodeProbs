class Solution {
public:
    
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> visited(n), ans;
        
        for(int i =0;i<n;i++) visited[i] =0;
        for(int i =0;i<edges.size();i++)
        {
            visited[edges[i][1]] =1;
        }
        
        for(int i =0;i<n;i++)
        {
            if(visited[i]==0)
                ans.push_back(i);
        }
        return ans;
    }
};