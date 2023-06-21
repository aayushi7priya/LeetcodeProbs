class Solution {
public:
int newIndex = 0;
vector<vector<pair<int,double>>> adj;   
vector<int> vis;
    
    bool dfs(int cur,int destination,double &ans){
        if(cur==destination)return true;
        vis[cur] = 1;
        for(auto it:adj[cur]){
            if(vis[it.first]==1)continue;
            ans*=it.second;
            if(dfs(it.first,destination,ans))return true;
            ans/=it.second;
        }
        return false;
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<string> variables;
        map<string,int> mp;
        int numSize = equations.size();
        
        for(int i = 0; i < numSize ; i++){
            for(int j =0;j<2;j++)
            {
                if(mp.find(equations[i][j])==mp.end()){
                    variables.push_back(equations[i][j]);
                    mp[equations[i][j]] = newIndex;   //basically here i am allotting each string an index
                    newIndex++;
                }
            }
        }
        adj.resize(newIndex);
        for(int i = 0; i < numSize; i++){
            string a = equations[i][0], b = equations[i][1];
            adj[mp[a]].push_back({mp[b],values[i]});        //just making a graph but with weight
            adj[mp[b]].push_back({mp[a],1/values[i]});     
        }
        int q = queries.size();
        vector<double> ans(q,-1);   //by default -1
        for(int i = 0; i < q; i++){
            string a = queries[i][0], b = queries[i][1];
            
            //if either of index not here then it will be -1 only
            if(mp.find(a)==mp.end()||mp.find(b)==mp.end())
            continue;
            
            vis.resize(newIndex);
            for(int i =0;i<newIndex;i++) vis[i] = 0;
            double val=1;
            if(dfs(mp[a],mp[b],val))ans[i]=val;
        }
        return ans;
    }
};