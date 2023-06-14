class Solution {
public:
    vector<vector<int>> adj;
    
    bool dfscheck(int node, vector<int>&vis, vector<int>&pathvis)
    {
        vis[node] = 1;
        pathvis[node] = 1;
        
        for(auto it : adj[node])
        {
            if(!vis[it])
            {
                if(dfscheck(it, vis, pathvis)==true) return true;
            }
            else if(pathvis[it] == true) return true;
        }
        
        pathvis[node] = 0;
        return false;
        
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> vis(numCourses, 0);
        vector<int> pathvis(numCourses, 0);
        adj.resize(numCourses);
        for(int i =0;i<prerequisites.size();i++)
        {
               adj[prerequisites[i][1]].push_back(prerequisites[i][0]); 
        }
        for(int i =0;i<numCourses;i++)
        {
            if(!vis[i])
            {
                if(dfscheck(i,vis, pathvis)==true) return false;
            }
        }
        
        return true;
    }
};