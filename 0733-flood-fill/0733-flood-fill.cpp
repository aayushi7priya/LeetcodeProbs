class Solution {
public:
    vector<vector<int>> ans;
    int colors;
    void dfs(int row, int col,  vector<vector<int>>& visited, vector<vector<int>>& image)
    {
        int n = image.size();
        int m = image[0].size();
        
        visited[row][col] = 1;
        ans[row][col] = colors;

        //up, down, left, and right
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        
        for (int i = 0; i < 4; i++) {
            int newRow = row + dx[i];
            int newCol = col + dy[i];

            if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && image[newRow][newCol] == image[row][col] && !visited[newRow][newCol]) {
                dfs(newRow, newCol, visited, image);
            }
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        colors = color;
        ans = image;
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        dfs(sr, sc, visited, image);
        return ans;
        
    }
};