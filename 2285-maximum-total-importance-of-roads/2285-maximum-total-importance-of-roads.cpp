class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        long long indegree[n];
        memset(indegree, 0, sizeof(indegree));
        for(int i =0;i<roads.size();i++)
        {
            indegree[roads[i][0]]++;
            indegree[roads[i][1]]++;
        }
        sort(indegree, indegree+n);
        long long ans = 0;
        for(int i =0;i<n;i++)
        {
            ans+= indegree[i]*(i+1);
        }
        return ans;
    }
};