class Solution {
public:

void dfs(int s, int n, vector<vector<int>>& isConnected, vector<int> &visited)
{
    visited[s] = 1;

    for(int i=0;i<n;i++)
    {
        if(isConnected[s][i]==1)
        {
            if(!visited[i])
                dfs(i, n, isConnected, visited);
            else
                continue;
        }
    }
}
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(); //total number of cities
        vector<int>visited(n,0); 
        int count =0;

        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                count++;
               dfs(i, n, isConnected, visited); 
            }
        }
        return count;
    }
};