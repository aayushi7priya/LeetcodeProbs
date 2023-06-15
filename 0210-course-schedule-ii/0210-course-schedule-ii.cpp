class Solution {
public:
   
    vector<int> bfs(vector<vector<int>> &adj, int numCourses)
    {
          vector<int>topoSort;
          vector<int>indegree(numCourses, 0);
        for(auto i: adj)
        {
            for(auto it: i)
            {
                indegree[it]++;
            }
        }
        queue<int>q;
        
        for(int i =0;i<indegree.size();i++)
        {
            if(indegree[i]==0)
                q.push(i);
        }
        
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            topoSort.push_back(node);
            for(auto it:adj[node])
            {
                indegree[it]--;
                if(indegree[it] == 0)
                {
                    q.push(it);
                }
            }
        }
        if(topoSort.size()!=numCourses)
            return {};
        else return topoSort;
        
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(int i =0;i<prerequisites.size();i++)
        {
             adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        
        return bfs(adj, numCourses);
        //now all left is to do topo sort
    }
};