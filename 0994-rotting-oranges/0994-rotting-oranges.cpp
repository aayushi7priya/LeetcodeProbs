class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        int vis[n][m];
        memset(vis, 0, sizeof(vis));
        queue<pair<pair<int,int>, int>> q;
        int time = 0;
        for(int i =0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 2) {
                    q.push({{i, j}, time});
                    vis[i][j] = 1;
                }
            }
        }
        
        while(!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            time = q.front().second;
            
            q.pop();
            
            int dx[] = {-1, 1, 0, 0};
            int dy[] = {0, 0, -1, 1};

            for (int i = 0; i < 4; i++) {
                int newRow = row + dx[i];
                int newCol = col + dy[i];

                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && grid[newRow][newCol] == 1 && !vis[newRow][newCol]) {
                    vis[newRow][newCol] = 1;
                    q.push({{newRow, newCol}, time + 1});
                }
            }
        }
        
        for(int i =0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1 && !vis[i][j]) {
                    return -1; 
                }
            }
        }
        
        return time;
    }
};
