class Solution {
public:
    
    int vis[1002];
    
    void dfs(int node,vector<vector<int>>& rooms)
    {
        vis[node] = 1;
        
        for(auto it: rooms[node])
        {
            if(!vis[it])
                dfs(it, rooms);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        memset(vis, 0, sizeof(vis));
        
        //agar components 1 se jyada hua to false
        int cnt =0;
        for(int i =0;i<rooms.size();i++)
        {
            if(!vis[i])
            {
                cnt++;
                dfs(i, rooms);
            }
        }
        if(cnt>1) return false;
        else return true;
        
    }
};