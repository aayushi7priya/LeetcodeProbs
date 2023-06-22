class Solution {
public:
     void dfs(vector<int>graph[],int vis[],long long subtsize[],int start){
        vis[start]=1;
        subtsize[start]+=1;
        for(auto child:graph[start])
        {
            if(!vis[child])
            {
               dfs(graph,vis,subtsize,child);
                subtsize[start]+=subtsize[child]; 
            }
        }
    }
    
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n=roads.size();
        vector<int>graph[n+1];
        int vis[n+1];
        
        //graph making
        for(int i=0;i<n;i++)                 //total nodes are n+1 but size of roads is n so iteration upto n 
        {
            graph[roads[i][0]].push_back(roads[i][1]);
            graph[roads[i][1]].push_back(roads[i][0]);
        }
        long long subtsize[n+1];  //this will store size of subtree for each node
        for(int i=0;i<=n;i++)
        {
            vis[i]=0;
            subtsize[i]=0;
        }
        dfs(graph,vis,subtsize,0);
        long long ans=0;
        
        for(int i=1;i<=n;i++)   //here start from 1 not from 0 
        {
           ans+=(subtsize[i]+seats-1)/seats;
        }
        return ans;
    }
   
};