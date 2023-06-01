class Solution {
public:
    int dp[1005][1005];
    string s1, s2;
    int rec(int i, int j) {
        int n = s1.size();
        int m = s2.size();
        
        if (i == n || j == m)
            return dp[i][j] = 0;
        
        if (dp[i][j] != -1)
            return dp[i][j];
        
        int ans = 0;
        if (s1[i] == s2[j])
            ans = 1 + rec(i + 1, j + 1);
        else
            ans = max(rec(i + 1, j), rec(i, j + 1));
        
        return dp[i][j] = ans;
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        memset(dp, -1, sizeof(dp));
        s1 = text1; s2 = text2;
        int ans = rec(0, 0);
        return ans;
    }
};
