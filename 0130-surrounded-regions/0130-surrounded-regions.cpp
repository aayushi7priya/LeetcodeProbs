class Solution {
public:
    int n, m;
    vector<vector<int>> vis;

    void dfs(int row, int col, vector<vector<char>>& board) {
        vis[row][col] = 1;

        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++) {
            int nrow = row + dx[i];
            int ncol = col + dy[i];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && board[nrow][ncol] == 'O' && vis[nrow][ncol] == 0) {
                vis[nrow][ncol] = 1;
                dfs(nrow, ncol, board);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        n = board.size();
        m = board[0].size();

        vis.assign(n, vector<int>(m, 0));

        for (int i = 0; i < m; i++) {
            if (board[0][i] == 'O' && vis[0][i] == 0) {
                vis[0][i] = 1;
                dfs(0, i, board);
            }

            if (board[n - 1][i] == 'O' && vis[n - 1][i] == 0) {
                vis[n - 1][i] = 1;
                dfs(n - 1, i, board);
            }
        }

        for (int j = 0; j < n; j++) {
            if (board[j][0] == 'O' && vis[j][0] == 0) {
                vis[j][0] = 1;
                dfs(j, 0, board);
            }

            if (board[j][m - 1] == 'O' && vis[j][m - 1] == 0) {
                vis[j][m - 1] = 1;
                dfs(j, m - 1, board);
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O' && vis[i][j] == 0) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
