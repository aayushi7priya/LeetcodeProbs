class Solution {
public:
    int n,m;
    vector<vector<int>> vis;
    
    void dfs(int row, int col, vector<vector<int>> &grid)
    {
        vis[row][col] =1;
        
        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, -1, 0, 1};
        
        for(int i =0;i<4;i++)
        {
            int nrow = row + dx[i];
            int ncol = col + dy[i];
            
            if(nrow>=0 && nrow<n && ncol >=0 && ncol <m && vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1)
            {
                vis[nrow][ncol] = 1;
                dfs(nrow,ncol, grid);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        
        vis.assign(n, vector<int>(m, 0));
        
        for(int i =0;i<m;i++)
        {
            if(grid[0][i] == 1 && vis[0][i]==0)
            {
                vis[0][i] =1;
                dfs(0, i, grid);
            }
            if(grid[n-1][i] == 1 && vis[n-1][i]==0)
            {
                vis[n-1][i] =1;
                dfs(n-1, i, grid);
            }
        }
        
        for(int i =0;i<n;i++)
        {
            if(grid[i][0] == 1 && vis[i][0]==0)
            {
                vis[i][0] =1;
                dfs(i, 0, grid);
            }
            if(grid[i][m-1] == 1 && vis[i][m-1]==0)
            {
                vis[i][m-1] =1;
                dfs(i, m-1, grid);
            }
        }
        int cnt =0;
        for(int i =0;i<n;i++)
        {
            for(int j =0;j<m;j++)
            {
                if(grid[i][j]==1 && vis[i][j] == 0)
                    cnt++;
            }
        }
        return cnt;
    }
};